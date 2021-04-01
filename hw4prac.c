#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



struct address_t {
        int oct1;
        int oct2;
        int oct3;
        int oct4;
        char alias[10];
};

struct address_t addressArray[100];
FILE *outputReport;

char *getDateAndTime();

void readDataFile();
void generateLocalityRpt(struct address_t addressArray[100], int amount);



//main function
int main() {

        //creating variables for main function
        char name[32];
        char named[80];
        FILE *filePointer;


        //take in user's name
        printf("Enter your name: ");
        fgets(name,sizeof(name),stdin);

        //redirecting name input into another variable
        sprintf(named,"%s", name);



        filePointer=fopen("222_Locality_Report", "w");

        //return an error message if the file doesn't open properly
        if(filePointer==NULL) {
                printf("Error opening file: 222_Locality_report");
                return (1);
                                }


        //output statements for the file

        fprintf(filePointer,"%s%s", named, getDateAndTime());
        fprintf(filePointer, "CS222 Network Locality Report\n");
      


        fclose(filePointer);
        //fclose(inputReport);  
        readDataFile();


        return (0);
}


void readDataFile() {
        FILE *inputReport;
        FILE *write;
        int i = 0, j = 0, k= 0, z;
        //char word[] = "";
        char talias[10];
	char ip[64];
        int tip[4] = {0};
	char sentinel[] = "NONE\0";
        static struct address_t addressArray[100];


        inputReport=fopen("CS222_Inet.txt", "r");
        write=fopen("222_Locality_Report", "a");

        //testing
        int temp = 0;
   
	while(fgets(ip, sizeof ip, inputReport) != NULL) {
		
		
		
		sscanf(ip, "%d.%d.%d.%d %s", tip, tip+1, tip+2, tip+3, talias);
		if((tip[0]!=0) && (tip[1] != 0)) {
			addressArray[k].oct1 = tip[0];
			//printf("%d\n", addressArray[k].oct1);
			
			addressArray[k].oct2 = tip[1];
			//printf("%d\n", addressArray[k].oct2);

			addressArray[k].oct3 = tip[2];
			//printf("%d\n", addressArray[k].oct3);

			addressArray[k].oct4 = tip[3];
			//printf("%d\n", addressArray[k].oct4);

			strcpy(addressArray[k].alias , talias);
			//printf("%s\n", addressArray[k].alias);
	        	//printf("\n");	
		}
		
		k++;
	}

	generateLocalityRpt(addressArray, k-1);
}

void generateLocalityRpt(struct address_t addressArray[100], int amount) {
	int i = 0, j = 0, counter=0, local = 0;
	int val1, val2;
	
	outputReport = fopen("222_Locality_Report", "a");

        fprintf(outputReport, "Address total: %d\n", amount);
        
	
	//for loop to check how many values are distinct
	
	for (i=0; i< amount; i++) {
		
		counter = 0; //reset the counter
		for (j = i+1; j<amount; j++) {

			//comparison of first two integers of the addresses
			if((addressArray[j].oct1 == addressArray[i].oct1) &&
					(addressArray[j].oct2 == addressArray[i].oct2)) {
						counter++; //add to the counter if there's a match
			}
		}

		//if the counter remained zero, add to local
		if(counter == 0) {
			local++;
		}		
	}

        fprintf(outputReport, "Localities: %d\n\n", local);
			
		
	



	for(i=0;i < local; i++) {
		val1 = addressArray[i].oct1;
		val2 = addressArray[i].oct2;
       	        fprintf(outputReport, "%d", addressArray[i].oct1);
       	        fprintf(outputReport, ".");
       	        fprintf(outputReport, "%d\n", addressArray[i].oct2);
       	        //printf("%s\n", addressArray[i].alias);

		for(j=0; j<amount; j++) {
			
			if((val1 == addressArray[j].oct1) &&
					(val2 == addressArray[j].oct2)) {
						fprintf(outputReport, "%s\n", addressArray[j].alias);
			}
	}
	fprintf(outputReport,"\n");	
	}
	

	fclose(outputReport);
}


//time function to return the current time
char *getDateAndTime() {
        time_t t;
        time(&t);
        return ctime(&t);
}



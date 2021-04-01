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


char *getDateAndTime();

void readDataFile();
void generateLocalityRpt(struct address_t addressArray[100]);



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
        fprintf(filePointer, "Address total: \n");
        fprintf(filePointer, "Localities: \n\n");


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
		if(tip[0]!=0) {
			printf("%d\n", tip[0]);
			printf("%d\n", tip[1]);
			printf("%d\n", tip[2]);
			printf("%d\n", tip[3]);
			printf("%s\n", talias);
	        	printf("\n");	
		}
		
	}

}




//time function to return the current time
char *getDateAndTime() {
        time_t t;
        time(&t);
        return ctime(&t);
}



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

char *getDateAndTime();

void readDataFile();
void generateLocalityRpt(char ip[]);
void localityMkr(char ip[]);
void aliasMkr(char ip[]);

struct address_t {
        int oct1;
        int oct2;
        int oct3;
        int oct4;
        char alias[10];
};

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
        FILE *filePointer;
        char ip[64];

        inputReport=fopen("CS222_Inet.txt", "r");
        filePointer=fopen("222_Locality_Report", "a");

        //testing
        while (fgets(ip, sizeof ip, inputReport) != NULL) {
                //fprintf(filePointer, "%s", ip);
                generateLocalityRpt(ip);
        }

        fclose(inputReport);
        fclose(filePointer);
}

void generateLocalityRpt(char ip[]) {
	FILE *write;
	int i = 0, j= 0;
	size_t len = strlen(ip);
	char qual = '.', qual2 = ' ',locality[16], ips[64];
	char word[64];
	int counter1, counter2, counter3, counter4;
	static struct address_t addressArray[100];


	for(i; i < len; i++) {

		//printf("%c\n", ip[i]); 
		if(ip[i] == '.') {
			counter2 = i;
			//printf("%d", counter2);
			for(j; j< counter2; j++) {
				printf("%c", ip[j]);
			}
			j = counter2;
			printf("\n");
		}
		
		if(ip[i] == ' ') {
			counter2 = i;
			for(j; j< counter2; j++) {
				printf("%c", ip[j]);
			}
			printf("\n");
		}	
		//printf("%d", count);
		//if(count==1) {
		//	printf("%s", &ip[i+1]);
		
		//}

	}
	

	printf("\n");


        write = fopen("222_Locality_Report", "a");
        //printf("%s", ip);
}



//time function to return the current time
char *getDateAndTime() {
        time_t t;
        time(&t);
        return ctime(&t);
}



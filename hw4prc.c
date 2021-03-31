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
        FILE *write;
        char ip[64];
	int i = 0, j = 0, k= 0;
        char word[] = "", word2[] = "Hello";
        int counter1, counter2, counter3, counter4;
        static struct address_t addressArray[100];


        inputReport=fopen("CS222_Inet.txt", "r");
        write=fopen("222_Locality_Report", "a");

        //testing
	int temp = 0;
        while (fgets(ip, sizeof ip, inputReport) != NULL) {
		
		for(i=0; i< strlen(ip); i++) {
			if(ip[i] == '.') {
				counter2 = i;
				break;
			}
		}
		for(j=0; j< counter2; j++) {
			printf("%c", ip[j]);
			//strcpy(addressArray[k].alias, word2);
				}
		//printf("\n%s", addressArray[k].alias);
		printf("\n");
		
    

		counter2++;
		for(i= counter2; i < strlen(ip); i++) {
			if(ip[i] == '.') {
				counter2 = i;
				break;
			}
		}
		j++;
		for(j; j<counter2; j++) {
			printf("%c", ip[j]);
		}	
		printf("\n");
		
		counter2++;
		for(i = counter2; i <strlen(ip); i++) {
			if(ip[i] == '.') {
				counter2 = i;
				break;
			}
		}
		j++;
		for(j; j< counter2; j++) {
			printf("%c", ip[j]);
		}

		printf("\n");

                counter2++;
                for(i = counter2; i <strlen(ip); i++) {
                        if(ip[i] == ' ') {
                                counter2 = i;
                                break;
                        }
                }
                j++;
                for(j; j< counter2; j++) {
                        printf("%c", ip[j]);
                }
		
		printf("\n");
		
		counter2++;
		for(i=counter2; i < strlen(ip); i++) {
			printf("%c", ip[i]);
			strcpy(word, &ip[i]);
		}
		printf("%s", word);
		printf("\n\n");
		k++;
		
	}
        fclose(inputReport);
        fclose(write);
}

void generateLocalityRpt(char ip[]) {

}



//time function to return the current time
char *getDateAndTime() {
        time_t t;
        time(&t);
        return ctime(&t);
}



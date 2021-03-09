#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_LEN 100

char *getDateAndTime();
int getInteger();
void decimalToBinary(int decValue, char binString[]);
void decimalToHex(int decValue, char hexString[]);
void decimalToOct(int decValue, char octString[]);


int main() {

	//creating variable for namee
	char name[32], valueString[100], valueString1[100], valueString2[100];
	char save[1], filename[100], buf[512];
	int t = 1;
	FILE *filePointer;

	//take in user's name
	printf("Enter your name: ");
	fgets(name,sizeof(name),stdin);
	//printf("%s\n", name);

	while(t=1) {
		int numb = getInteger();

		//printf("%d", numb);	
		if(numb>=1 && numb<=1000000) {
	       		decimalToHex(numb, valueString1);
        		decimalToOct(numb, valueString2);
       			decimalToBinary(numb, valueString);
		}

		else {
			break;
		}
        	
		}	
	
	

	

	//printf("Today's date: %s\n", getDateAndTime());
	return (0);
}


char *getDateAndTime() {
	time_t t;
	time(&t);
	return ctime(&t);
}


int getInteger() {


        char val1[100], brk[] = "X", brk1[] = "x";
        int urange = 1000000, lrange = 1, intval, result;


//	printf("%s", val1);
        while(lrange == 1) {
		printf("Enter an Integer (1-1000000) or type x to exit: ");
		fgets(val1, sizeof(val1), stdin);

//		printf("%s\n", val1);


		if(*val1 == 'x' || *val1 == 'X') { 
			break;
		}

		else if(*val1<lrange || *val1>urange) {
			break;
		}

		else {
			intval = atoi(val1);

		}


		if(intval >= lrange && intval <= urange) {
			printf("\nDecimal: %d\n", intval);
			break;
              		 }
		else {
			printf("Error: %d is out of range\n", intval);

		}
        }


	return intval;
}


void decimalToBinary(int decValue, char binString[]) {
	
	int quotient, i = 1, j;
	quotient = decValue;

	while(quotient != 0) {
		binString[i++] = quotient % 2;
		quotient = quotient / 2;
	}

	if(decValue>0)
		printf("Binary: ");

	
	for(j = i-1; j>0;j--)
		printf("%d", binString[j]);
	printf("\n");

	
}

void decimalToHex(int decValue, char hexString[]) {
	long int quotient;
	int i = 1, j, temp;

	quotient = decValue;

	while(quotient!=0) {
		temp = quotient % 16;

		//convert integer into character
		if(temp<10)
			temp = temp + 48;
		else
			temp = temp + 55;

		hexString[i++] = temp;
		quotient = quotient / 16;
	}

	
	if(decValue>0)
		printf("Hexadecimal: ");

	for(j= i-1; j > 0; j--)
		printf("%c", hexString[j]);
	printf("\n");
}


void decimalToOct(int decValue, char octString[]) {
	int quotient, i = 1, j, temp;

	quotient = decValue;

	while(quotient!=0) {
		octString[i++] = quotient % 8;
		quotient = quotient / 8;
	}
	if(decValue>0)
                printf("Octal: ");


        for(j = i-1; j>0;j--)
                printf("%d", octString[j]);
        printf("\n");
}

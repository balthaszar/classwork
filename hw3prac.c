#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

char *getDateAndTime();
int getInteger();
void decimalToBinary(int decValue, char binString[]);
void decimalToHex(int decValue, char hexString[]);
void decimalToOct(int decValue, char octString[]);


int main() {

	//creating variable for name
	char name[32], valueString[100];
	//take in user's name
	printf("Enter your name: ");
	fgets(name,sizeof(name),stdin);

	int numb = getInteger();
	decimalToBinary(numb, valueString);

	


	//printf("Today's date: %s\n", getDateAndTime());
	return (0);
}


char *getDateAndTime() {
	time_t t;
	time(&t);
	return ctime(&t);
}


int getInteger() {


        char val1[100], val2;
        int urange = 1000000, lrange = 1, intval;


	printf("%s", val1);
        while(lrange == 1) {
		printf("Enter an Integer (1-1000000) or type x to exit: ");
		fgets(val1, sizeof(val1), stdin);

		if(*val1 == 'x' || *val1 == 'X') { 
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

	printf("Binary: ");


	for(j = i-1; j>0;j--)
		printf("%d", binString[j]);
	printf("\n");

	
}



/*Assignment #3: ConvertDec_to_Hex_oct_bin.c
 *
 * Yonel Beaulieu
 * Date: 03/09/2021
 *
 * Notes: The file will output an error, that 0 is out of range, at the end of the sequence
 * 	 I was unable to get the file output to write the hexadecimal, octal, and binary 		  statement. I believe I needed to use sprintf, but could not get it to function properly 
 *
 */


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

//main function
int main() {

	//creating variables for main function
	char name[32], valueString[100], valueString1[100], valueString2[100];
	char save[1], filename[100], buf[512],testing[100], named[80];
	int t = 1, quotient, i = 1;
	FILE *filePointer;

	//take in user's name
	printf("Enter your name: ");
	fgets(name,sizeof(name),stdin);
	
	//redirecting name input into another variable
	sprintf(named,"%s", name);

	//while loop, to keep asking for numbers
	while(t=1) {

		//function call to getInteger
		int numb = getInteger();

		//range that numb needs to be tu run additional functions	
		if(numb>=1 && numb<=1000000) {

			//function calls, numb to Hex, Oct, Bin
	       		decimalToHex(numb, valueString1);
        		decimalToOct(numb, valueString2);
       			decimalToBinary(numb, valueString);
			
	
			//asking the user if they want to save
			printf("\nSave to a file? (y/n): ");
			scanf("%s", save);
			

			//conditional for save being y
			if(*save=='y' || *save=='Y') {

				//requesting the file name of the user
				printf("\nEnter file name: ");
				scanf("%s", filename);
				
				//pointer file, opening for writing
				filePointer=fopen(filename, "w");
				
				//return an error message if the file doesn't open properly
				if(filePointer==NULL) {
					printf("Error opening file: %s\n", filename);
					return(1);
				}

				//output statements for the file
				fprintf(filePointer,"%s", named);
				fprintf(filePointer, "Today's date: %s\n", getDateAndTime());
				fprintf(filePointer, "Decimal: %d\n", numb);
				fprintf(filePointer, "Hexadecimal: %s\n", valueString1);
				fprintf(filePointer, "Octal: %s\n", valueString2);
				fprintf(filePointer, "Binary: %s\n", valueString);	

			printf("File saved.\n");				
			}
		}
		else {
			break;
		}
		}	
	return (0);
}

//time function to return the current time
char *getDateAndTime() {
	time_t t;
	time(&t);
	return ctime(&t);
}

//function for getting integer from user
int getInteger() {

	
        char val1[100], brk[] = "X", brk1[] = "x";
        int urange = 1000000, lrange = 1, intval, result;

	//while loop
        while(lrange == 1) {
		//getting integer from the user
		printf("Enter an Integer (1-1000000) or type x to exit: ");
		fgets(val1, sizeof(val1), stdin);

		//conditionals breaking loop if loop isn't in range
		if(*val1 == 'x' || *val1 == 'X') { 
			break;
		}
		else if(*val1<lrange || *val1>urange) {
			break;
		}
		//otherwise turn the input to an integer
		else {
			intval = atoi(val1);
		}

		//conditional while intval is in range
		if(intval >= lrange && intval <= urange) {

			//print out value and break
			printf("\nDecimal: %d\n", intval);
			break;
              		 }
		else {
			//otherwise inform user the num it out of range
			printf("Error: %d is out of range\n", intval);
		}
        }
	return intval;
}


//decimal to binary
//i should not figured a way to use sprintf to get the output to binString
void decimalToBinary(int decValue, char binString[]) {
	
	char bin[80];
	int quotient, i = 1, j;
	quotient = decValue;

	//looping while quotient is greater than 0
	while(quotient != 0) {

		//convert binString to binary
		binString[i++] = quotient % 2;
		quotient = quotient / 2;
	}

	if(decValue>0)
		printf("Binary: ");

	//loop to print out binString
	for(j = i-1; j>0;j--)
		printf("%d", binString[j]);
	printf("\n");

	
}


//decimal to Hex
//Should have used sprintf to get the value to hexString
void decimalToHex(int decValue, char hexString[]) {
	long int quotient;
	int i = 1, j, temp;

	quotient = decValue;

	while(quotient!=0) {

		//turning temp into hexadecimal
		temp = quotient % 16;

		//convert integer into character
		if(temp<10)
			temp = temp + 48;
		else
			temp = temp + 55;
		//appending hexString
		hexString[i++] = temp;
		quotient = quotient / 16;
	}

	
	if(decValue>0)
		printf("Hexadecimal: ");

	//looping to output hexString
	for(j= i-1; j > 0; j--)
		printf("%c", hexString[j]);
	printf("\n");
}

//decimal to Octal
//Should have used sprintf to get output to octString
void decimalToOct(int decValue, char octString[]) {
	int quotient, i = 1, j, temp;

	quotient = decValue;
	
	//looping to convert to Octet
	while(quotient!=0) {

		//adding value to octet
		octString[i++] = quotient % 8;
		quotient = quotient / 8;
	}
	if(decValue>0)
                printf("Octal: ");

	//looping through octString to output value
        for(j = i-1; j>0;j--)
                printf("%d", octString[j]);
        printf("\n");
}

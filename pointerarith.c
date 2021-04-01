#include <stdio.h>

int main(void) {
	char str[24] = "192.168.6.3 alias";
	int b[4] = {0};
	char name[16];

	sscanf(str, "%d.%d.%d.%d  %s",b, b+1, b+2, b+3, name);

	printf("%d\n%d\n%d\n%d\n", b[0], b[1], b[2], b[3]);
	printf("%s", name);
	return 0;
}	

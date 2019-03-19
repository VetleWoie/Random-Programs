#include <stdio.h>
#include <stdlib.h>

#define USAGEERR "ERROR: Usage: %s number number", argv[0]

int main(int argc, char **argv){

	if(argc < 3){
		printf(USAGEERR);
		return 0;
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int tmp;

	while(b != 0){
		tmp = b;
		b = a % b;
		a = tmp;
	}

	printf("%d\n", a);
	return a;

}
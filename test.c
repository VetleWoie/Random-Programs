#include <stdio.h>
#include <stdlib.h>

int main(){
	int i = 0;
	char c;
	char input[10];
	
	scanf("%s",&input);
	while(input[i] != '\0'){
			i++;
	}
	int j;
	for(j = 0; j <= i; j++){
		printf("%c",input[j]);
	}
	//printf("hallais");
}
#include <stdio.h>

int main(){
	
	int i = 1;
	int j = 2;
	int k = 3;
	int input;

	printf("How many little indians? ");
	scanf("%d",&input);

	while(j <= input){
		if(i % 10 == 0){
			printf("%d little indians little\n", i);
			i++;
			j++;
			k++;
		}
		printf("%d and %d and %d little indians\n", i,j,k);
		i += 3;
		j += 3;
		k += 3;

	}
}
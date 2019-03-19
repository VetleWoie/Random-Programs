#include <stdio.h>

int main(){
	
	int input;
	int num;
	int num2;
	char charachter;
	int i;
	int scale = 1;


	printf("What number do you wan to convert? Number: ");
	scanf("%d", &input);


	while(input > 0){

		while(input-scale >= 0){
			scale *= 10;
		}
		scale /= 10;


		num = num2 = input / scale;
		
		if(1 % scale == 0){
			charachter = 'I';
			if(num >= 5){
				printf("V");
				num2 -= 5;
			}
		}else if(10 % scale == 0){
			charachter = 'X';
			if(num >= 5){
				printf("L");
				num2 -= 5;
			}
		}else if(100 % scale == 0){
			charachter = 'C';
			if(num >= 5){
				printf("D");
				num2 -= 5;
			}
		}else{
			charachter = 'M';
		}
		

		for(i = 0; i < num2; i++){
			printf("%c",charachter);
		}

		input = input - scale*num;
	}
	printf("\n");
}
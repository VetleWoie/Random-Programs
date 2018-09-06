#include <stdio.h>
#include <stdlib.h>

#define PRIMEERROR "Error: End of file reached! Not enough primes in file"
#define MEMERROR "Error: Couldnt allocate memory"
#define USAGEERROR "Error: Usage: %s primenumberfile number\n"

void addFactor(int **factors,int *numberOfFactors, int factor);

int main(int argc, char **argv){

    int input;
    int factor;
    int prime;
    int error;
    int **factors = (int **) malloc(sizeof(int *)); //Pointer to array
    if(factors == NULL){
        printf("MEMERROR");
        exit(1);
    }
	factors[0] = NULL;

    int numberOfFactors = 0; //Length of factors

    FILE *primes;

    if(argc < 3){
        printf(USAGEERROR, argv[0]);
        exit(1);
    }

    input = atoi(argv[2]);
    factor = input;
    primes = fopen(argv[1], "r");

    while(1){
        error = fscanf(primes,"%d",&prime);
        if(error == -1){
            printf(PRIMEERROR);
            exit(1);
        }
        if(factor == prime){
            addFactor(factors, &numberOfFactors, prime);
            break;
        }else if(factor % prime){
            continue;
        }else{
            factor = factor / prime;
            addFactor(factors, &numberOfFactors, prime);
            rewind(primes);
        }
    }

    printf("\n%d = ", input);
    int i;
    for(i = 0; i < numberOfFactors; i++){
        if(factors[i][1] > 1){
            printf("%d^%d ",factors[i][0], factors[i][1]);
        }else{
            printf("%d ", factors[i][0]);
        }
        if(i == numberOfFactors - 1){
            printf("\n");
        }else{
            printf("* ");
        }

        free(factors[i]);
    }

    free(factors);
}

void addFactor(int **factors,int *numberOfFactors, int factor){
    
    int i;

    if(factors[0] != NULL){
        for(i = 0; i < *numberOfFactors; i++){
            if(factors[i][0] == factor){
                factors[i][1]++;
                return;
            }
        }
        factors = realloc(factors, sizeof(int *));
        *numberOfFactors += 1;
        factors[*numberOfFactors - 1] = malloc(2 * sizeof(int));
        factors[*numberOfFactors - 1][0] = factor;
        factors[*numberOfFactors - 1][1] = 1;
        return;
    }else{
        factors[0] = (int *) malloc(2 *sizeof(int));
        if(factors[0] == NULL){
            printf("MEMERROR");
            exit(1);
        }
        factors[0][0] = factor;
        factors[0][1] = 1;
        //numberOfFactors = (int *) malloc(sizeof(int));

        *numberOfFactors += 1;
    }
}

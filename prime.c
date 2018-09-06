#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CHECKFILE(file) if(file == NULL){perror("Couldn't open file, %d"); exit(0); }

int main(int argc, char **argv){

    if(argc < 2){
        perror("Usage: ./prime maxnum");
        exit(0);
    }

    char* fileName = "primes.txt";
    
    FILE *primes = fopen(fileName, "w");
    CHECKFILE(primes);
    fprintf(primes, "2\n3\n5\n7\n");
    fclose(primes);

    int max = atoi(argv[1]);
    int i;
    int j;
    char prime[20];
    
    int isPrime;
    int numberOfPrimes = 0;

    for(i = 8; i < max; i++){
        primes = fopen(fileName, "r");
        
        CHECKFILE(primes);
        isPrime = 1;

        while(fgets(prime, 20, primes)){
            j = atoi(prime);
            if(i == j){
                continue;
            }else if(i % j == 0){
                isPrime = 0;
                break;
            }else if(j > sqrt(i)){
                break;
            }
        }
        fclose(primes);

        if(isPrime){
            primes = fopen(fileName, "a");
            CHECKFILE(primes);

            fprintf(primes,"%d \n",i);
            numberOfPrimes++;

            fclose(primes);
        }
    }

    printf("Number of primes found: %d",    numberOfPrimes);
}
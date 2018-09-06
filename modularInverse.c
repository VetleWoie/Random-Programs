#include <stdio.h>
#include <stdlib.h>

#define USAGEERR "ERROR: Usage %s inverseNumber modularNumber", argv[0]

int main(int argc, char **argv){
    if(argc < 3){
        printf(USAGEERR);
        exit(0);
    }

    int a = atoi(argv[1]);
    int b;
    int c = atoi(argv[2]);

    for(b = 0; b < c-1; b++){
        if((a*b) % c == 1){
            printf("%d^-1mod%d = %d\n", a,c,b);
            return 1;
        }else{
            continue;
        }
    }
    printf("There is no modular inverse\n");
}
#include <stdlib.h>
#include <stdio.h>

#define USAGEERR "ERROR: Usage %s [Number of congruenses] [congruense 1 congruense 2 ... congruense n]\n",argv[0]

int invmod(int a, int b);

int main(int argc, char **argv){
    if(argc < 2){
        printf(USAGEERR);
        return 0;
    }

    int noc = atoi(argv[1]);
    if(noc < 2){
        printf("Need at least to congruenses to use CRT\n");
        return 0;
    }

    int i;
    int j;
    int M = 1;
    int **congruence;
    int x = 0;

    congruence = (int **) malloc(sizeof(int *) * noc);
    j = 2;
    for(i = 0; i < noc; i++){
        congruence[i] = (int *) malloc(sizeof(int) * 3);
        congruence[i][0] = atoi(argv[j]);
        congruence[i][1] = atoi(argv[j+1]);
        M *= congruence[i][1];
        j += 2;
    }

    for(i = 0; i < noc; i++){
        congruence[i][2] = invmod(M / congruence[i][1], congruence[i][1]); 
        x += congruence[i][0]* (M / congruence[i][1]) *congruence[i][2];
    }
    
    if(x % M >= 0){
        printf("X = %d\n", x % M);
    }else{
        printf("X = %d\n",M + (x % M));
    }
    

    for(i = 0; i < noc; i++){
        free(congruence[i]);
    }
    free(congruence);

}

int invmod(int a, int b){
    int s1,s2;
    int t1,t2;
    int tmp;
    int q;

    s1 = 1; s2 = 0;
    t1 = 0; t2 = 1;

    while(b != 0){
        tmp = b;
        q = a / b;
        b = a % b;
        a = tmp;

        tmp = s2;
        s2 = s1 - (q * s2);
        s1 = tmp;

        tmp = t2;
        t2 = t1 - (q * t2);
        t1 = tmp;
    }

    return s1;
}
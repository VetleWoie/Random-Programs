#include <stdio.h>
#include <stdlib.h>

#define ERROR "Error: Usage %s a b -> a^-1 mod b\n"

int gcd(int a, int b);
int extendedEuclid(int a, int b);

int main(int argc, char **argv){

    if(argc < 3){
        printf(ERROR, argv[0]);
        return 0;
    }
    else if (argc > 3)
    {
        printf("Warning: to many arguments, will only use the two first ones");
    }
    

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    
    if (gcd(a,b) != 1) {
        printf("No modulo inverse, gcd(%d, %d) != 1", a, b);
        return 0;
    } 


    printf("%d inverse mod %d = %d", a, b , extendedEuclid(a,b));
}

int gcd(int a,int b){
    int tmp;

    if(a > b){
        tmp = a;
        a = b;
        b = tmp;
    }

    while(b != 0){
        tmp = b;
        b = a % b;
        a = tmp;
    }
    
    return a;
}

int extendedEuclid(int a, int b){
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
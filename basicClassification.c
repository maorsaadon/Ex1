#include <math.h>


int isPrime(int num){
    if (num == 0) return 0;
    int square = sqrt(num);
    for (int i = 2; i <= square; i++)
        if(num % i == 0) return 0;
    return 1;
}
int factorial(int num){
    if(num==0) return 1; 
    return num*factorial(num-1);
}
int isStrong(int num){
    if (num == 0) return 0;
    int sum = 0;
    for (int i = num; i > 0; i = i/10)
        sum += factorial(i % 10);
    return (sum == num ? 1 : 0);
}
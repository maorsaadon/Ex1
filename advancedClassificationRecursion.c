#include <math.h>

// int isArmstrongHelper(int num, int power){
//     if(num == 0) return 0;
//     return ((int)(pow((num % 10), power))) + isArmstrongHelper((num / 10), power);
// }

// int isArmstrong(int num){
//     int count = 0;
//     for (int i = num; i > 0; i = i / 10)
//         count++;
//     int ans = isArmstrongHelper(num, count);
//     return (num == ans ? 1 : 0);
// }

// int isPalindromeHelper(int num, int power){
//     if(num == 0) return 0;
//     return (num % 10) * pow(10, power-1) + isPalindromeHelper((num / 10), power-1);
// }

// int isPalindrome(int num){
//     int count = 0;
//     for (int i = num; i > 0; i = i / 10)
//         count++;
//     int ans = isPalindromeHelper(num, count);
//     return (num == ans ? 1 : 0);
// }

int NumberLength(int x)
{
    int length=0;
    while(x!=0)
    {
        length++;
        x=x/10;
    }
    return length;
}

int isPalindromeReverse(int num , int ReverseNum)
{
    if(NumberLength(num)==0){
        return ReverseNum;
    }
    ReverseNum=ReverseNum*10+num%10;
    return isPalindromeReverse(num/10, ReverseNum);
}

int isPalindrome(int OriginalNumber)
{   
    int ReverseOriginalNumber=isPalindromeReverse(OriginalNumber,0);

    return(ReverseOriginalNumber==OriginalNumber);
   
}

int isArmstongLength(int num, int length)
{   
    int changeOriginalNumber=num;
    if(changeOriginalNumber==0){
        return 0;
    }
    return pow(changeOriginalNumber%10,length)+isArmstongLength(changeOriginalNumber/10,length);
}


int isArmstrong(int OriginalNumber)
{
    int sum=isArmstongLength(OriginalNumber,NumberLength(OriginalNumber));

    if(sum==OriginalNumber)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#include <math.h>

int NumberLength(int num)
{
    int length=0;
    while(num!=0)
    {
        length++;
        num = num/10;
    }
    return length;
}

int isPalindromeReverse(int num , int ReverseNum)
{
    if(NumberLength(num)==0) return ReverseNum;
    ReverseNum=ReverseNum*10+num%10;
    return isPalindromeReverse(num/10, ReverseNum);
}

int isPalindrome(int num)
{   
    int ReverseOriginalNumber=isPalindromeReverse(num,0);

    return(ReverseOriginalNumber==num);
   
}

int isArmstongLength(int num, int length)
{   
    int changeOriginalNumber=num;
    if(changeOriginalNumber==0) return 0;
    return pow(changeOriginalNumber%10,length)+isArmstongLength(changeOriginalNumber/10,length);
}


int isArmstrong(int num)
{
    int sum=isArmstongLength(num,NumberLength(num));

    if(sum==num) return 1;
    else return 0;

}
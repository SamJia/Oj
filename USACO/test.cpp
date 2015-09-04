#include <stdio.h>  
#include <math.h>  
  
  
int Prime(int n)  
{  
    int i;  
    double k;  
    k=sqrt(n);  
    for(i=2;i<=k;i++)  
    {  
        if (n%i==0)  
        {  
            return 0;  
        }  
    }  
    return 1;  
}  
  
  
  
  
int Palindromes(int num)  
{  
    int sum = 0;  
    //关键代码  
    int temp = num;  
    while(temp)  
    {  
        sum = sum*10 + temp%10;  
        temp /= 10;  
    }  
    if (sum == num)  
    return 1;  
    else  
    return 0;  
}  
int main()  
{
    int num1= 0 ,num2 = 0;  
    while(scanf("%d %d",&num1,&num2)!=EOF)  
    {  
        int i = num1;  
        for(;i<=num2;i++)  
        {  
            if(Palindromes(i))  
            {  
                if(Prime(i))  
                printf("%d\n",i);  
            }  
  
  
        }  
    }  
    return 0;  
} 
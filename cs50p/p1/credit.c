#include <stdio.h>

int check_visa(unsigned long long n);

int main()
{
    unsigned long long number = 0;
    printf("what's your card number? ");
    scanf("%llu",&number);
    int len = 0;
    unsigned long long num = number;
    while(num >= 100)
    {
        num = num/10;//因为num是int类型，直接除以十就相当于把最后一位砍掉
        len++;
        printf("%llu\n",num);
    }
    len = len + 2;

    //if (num == 51 || num == 52 || num == 53 || num == 54 || num == 55)
    if (num >= 51 && num <= 55)//更聪明的写法
    {
        // Mastercard prefixes 51-55
        printf("mastercard\n");
    }
    //else if ((num - (num % 10))/10 == 4 && (len == 13 || len == 16))
    else if ((num/10) == 4 && (len == 13 || len == 16))
    {
        printf("it's visa maybe\n");
        if(check_visa(number) == 0)
        {
            printf("valid\n");
        }
        else
        {
            printf("invalid\n");
        }
    }
    else
    {
        printf("invalid\n");
    }
}

int check_visa(unsigned long long n)
{
    int sum = 0;
    for(int i = 0; n > 0 ; n = n/10, i++)//很细节，如果不用加初始化数据，也要保留原结构
    {
        int digit = n % 10;
        if (i%2 != 0)
        //因为这里才是真正的从倒数第二位开始
        {
            digit = digit * 2;
            if (digit >= 10)
            {
                sum = sum + (digit % 10);
                sum = sum + digit / 10;
            }
            else
            {
                sum = sum + digit ;
            }
        }
        else
        {
            sum = sum + digit;
        }
    }

    if (sum % 10 == 0)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}
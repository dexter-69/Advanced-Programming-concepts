// UCA Ques.
// A stream of bits is coming from user. After addition of each bit, tell if the resulting binary number is divisible by three or not.
// 0    (divisible)
// 01   (not divisible)
// 011  (divisible)
// 0110 (divisible)

#include <stdio.h>

int main()
{
    int Num, bit;    //Current number broken down to 0, 1 or 2 with mod. And current bit.
    
    Num = 0;    //Initialize Num with 0.
    printf("\nEnter bit by bit: \n");
    
    while(1)                    //For each incoming bit.
    {
        scanf("%d", &bit);
        
        if(bit == 0)        //(!bit && Num*=2) || (Num=Num*2+1)
            Num *= 2;
        else if(bit == 1)
            Num = (Num * 2) + 1;

        Num %= 3;               //Mod the resulting number with 3.

        if((Num % 3) == 0)
           printf("\n\tDivisible\n");
        else
           printf("\n\tNot Divisible\n");
    }

    return 0;
}


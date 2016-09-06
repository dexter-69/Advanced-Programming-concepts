// UCA Ques.
// A stream of bits is coming from user. After addition of each bit, tell if the resulting binary number is divisible by three or not.
// 0    (divisible)
// 01   (not divisible)
// 011  (divisible)
// 0110 (divisible)

#include <stdio.h>

int main()
{
    int div;    //Flag isDivisible.
    int Num;    //Current number converted down to 0, 1 or 2.
    int bit;    //Current bit.
    
    scanf("%d", &bit);
    while(bit == 0)       //For leading zeros.
    {
        Num = 0;
        div = 1;
        printf("\n\tDivisible | \tNum=%d\n", 0);
        
        scanf("%d", &bit);
    }
    Num = 1;
    div = 0;
    printf("\n\tNot Divisible | \t1Num=%d\n", Num);  //For first high (1) bit.
    
    
    scanf("%d", &bit);
    if(bit == 0)                  //Means 10 i.e. 2
    {
        Num = 2;
        div = 0;
        printf("\n\tNot Divisible | \t10Num=%d\n", Num);
    }
    else                        //Means 11 i.e. 3 (converted to 0).
    {
        Num = 0;
        div = 1;
        printf("\n\tDivisible | \t11Num=%d\n", Num);
    }
    
    while(1)                    //For subsequent bits.
    {
        scanf("%d", &bit);
        
        if(div && bit==0)
        {
            Num = 0;
            div = 1;
            printf("\n\tDivisible | \t@Num=%d\n", Num);
        }
        else if(div && bit==1)
        {
            Num = 1;
            div = 0;
            printf("\n\tNot Divisible | \t#Num=%d\n", Num);
        }
        else if( !div && bit==0)
        {
            if((Num-1)%3 == 0)  Num = 2;
            else                Num = 1;
            
            div = 0;
            printf("\n\tNot Divisible | \t*Num=%d\n", Num);
        }
        else if( !div && bit==1)
        {
            if((Num-1)%3 == 0)
            {
                Num = 0;
                div = 1;
                printf("\n\tDivisible | \t)Num=%d\n", Num);
            }
            else
            {
                Num = 2;
                div = 0;
                printf("\n\tNot Divisible | \tNum=%d\n", Num);
            }
        }
    }

}


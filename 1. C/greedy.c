/*
 *  A simple program which asks the user how much change is owed
 *  and then spits out the minimum number of coins with which said 
 *  change can be made
 *
 *	Full specifications can be found at:
 *  http://d2o9nyf4hwsci4.cloudfront.net/2013/fall/psets/1/pset1/pset1.html
 *
 *  Written by Johann Nel
 */
 
#include <cs50.h>
#include <math.h>
#include <stdio.h>
 
int main(void)
{
    float   change_req;
    int     cents;
    int     min_coins = 0;
    
    printf("Oh hai! How much change is owed? ");
    
    for (;;)
    {
        change_req = GetFloat();
            
        if (change_req > 0)
            break;
        
        printf("How much change is owed?\n");
    }

    change_req *= 100;
    cents = (int)round(change_req);
    
    while (cents > 0)
    {
        while (cents >= 25)
        {
            cents -= 25;
            min_coins++;
        }
        
        while (cents >= 10)
        {
            cents -= 10;
            min_coins++;
        }
        
        while (cents >= 5)
        {
            cents -= 5;
            min_coins++;
        }
        
        while (cents >= 1)
        {
            cents -= 1;
            min_coins++;
        }
    }
    
    printf("%d\n", min_coins);
}
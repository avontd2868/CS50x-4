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
#include <stdio.h>
 
int main(void)
{
    float   change_req;
    
    printf("Oh hai! How much change is owed? ");
    
    for (;;)
    {
        change_req = GetFloat();
            
        if (change_req > 0)
            break;
        
        printf("How much change is owed?\n");
    }
 
}
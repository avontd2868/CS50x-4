/*
 *  A simple program that recreates a half-pyramid as seen in
 *  Nintendo's Super Mario Brothers, making use of hashes(#) for blocks
 *
 *  Full specifications can be found at:
 *  http://d2o9nyf4hwsci4.cloudfront.net/2013/fall/psets/1/pset1/pset1.html
 *
 *  Written by Johann Nel
 */
 
 #include <cs50.h>
 #include <stdio.h>
 
 int main(void)
 {
    int height = 0;
    
    for (;;)
    {
        printf("Please enter the height of the half-pyramid: ");
        height = GetInt();
        
        if (height >= 0 && height <= 23)
            break;
        
        printf("Height: %d\n", height);
    }
  
 }

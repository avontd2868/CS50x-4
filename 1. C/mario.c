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
    int blocks = 1;
   
    /*
     *  Prompt the user to specify the height of the half-pyramid
     *  If the height is less than 0 or more than 23 it will print
     *  a message i.e. "Height: -1" and re-prompt the user to specify
     *  the height of the half-pyramid. Will only break out of the forever
     *  loop if the height is between 0 and 23
     */
    for (;;)
    {
        printf("Please enter the height of the half-pyramid: ");
        height = GetInt();
       
        if (height >= 0 && height <= 23)
            break;
       
        printf("Height: %d\n", height);
    }
   
    /*
     *  Print the half pyramid of height the user specified earlier
     *  First print the approriate amount of spaces
     *  Then print the approriate amount of blocks ('#')
     *  Finally print the new line character and move onto the next row
     *  Will continue doing this until specified height is reached
     */    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - blocks; j++)
        {
            printf(" ");
        }
       
        for (int k = 0; k < blocks + 1; k++)
        {
            printf("#");
        }
       
        blocks++;
        printf("\n");
   }  
 }
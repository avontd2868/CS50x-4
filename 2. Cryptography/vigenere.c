/*
 *  A program to do Vigenere Cipher
 *
 *  Full Specifications can be found at:
 *  http://d2o9nyf4hwsci4.cloudfront.net/2014/x/psets/2/pset2/pset2.html
 *
 *  By Johann Nel
 */
 
 int ascii_alpha(char letter, int ascii_value);
 
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please execute with only one argument!\n");
        return 1;
    }
    else
    {   
        // Check whether keyword only contains alphabetically letters
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Use a alphabetically letters only for keyword!\n");
                return 1;
            }
        }
        
        string p_text       = GetString();
        string keyword      = argv[1];
        int    keyword_len  = strlen(keyword);
    }
}

/*
 *  ======================================================
 *  A function to convert from ASCII to alphabetical index
 *  'A' and 'a' = 0
 *  'Z' and 'z' = 25
 *  ======================================================
 */
int ascii_alpha(char letter, int ascii_value)
{
    int result;
    return result = letter - ascii_value;
}
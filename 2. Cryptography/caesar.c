/*
 *  A simple program to do Caesar Cipher
 *
 *  Full Specifications can be found at:
 *  http://d2o9nyf4hwsci4.cloudfront.net/2014/x/psets/2/pset2/pset2.html
 *
 *  By Johann Nel
 */
 
 void cipher_text(char p_text, int ascii_value, int key);
 
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define UPPER_CASE 65   // ASCII value of 'A'
#define LOWER_CASE 97   // ASCII value of 'a'

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please execute with only one argument!\n");
        return 1;
    }
    else
    {   
        int key = atoi(argv[1]);
        
        string p_text = GetString();
        
        // Loop through each character and check whether alphabetical character
        // If it is, check whether upper/lower case and print ciphertext
        // Else print non-alphabetical character
        for (int i = 0, n = strlen(p_text); i < n; i++)
        {
            if (isalpha(p_text[i]))
            {
                if (isupper(p_text[i]))
                    cipher_text(p_text[i], UPPER_CASE, key);
                                
                if (islower(p_text[i]))
                    cipher_text(p_text[i], LOWER_CASE, key);         
            }
            else
                printf("%c", p_text[i]);
        }
        printf("\n");
    }
}

/*
 *  A simple function to convert from ASCII to alphabetical order
 *  and will wrap around and then convert back to ASCII.
 *  This is to ensure that only alphabetical letters are printed
 *  Will print cipherText
 *  This will be zero indexed i.e. 0 = 'A', 25 = 'Z'
 */
void cipher_text(char p_text, int ascii_value, int key)
{
    int result = p_text - ascii_value;
    int wrap = (result + key) % 26;
    
    printf("%c", wrap + ascii_value);
}

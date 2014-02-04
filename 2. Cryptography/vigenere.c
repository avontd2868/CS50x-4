/*
 *  A program to do Vigenere Cipher
 *
 *  Full Specifications can be found at:
 *  http://d2o9nyf4hwsci4.cloudfront.net/2014/x/psets/2/pset2/pset2.html
 *
 *  By Johann Nel
 */
 
 int ascii_alpha(char letter, int ascii_value);
 void vigenere(char p_text, char keyword, int ascii_value);
 
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
      
        // Loop through each character and check whether alphabetical character
        // If it is, check whether upper/lower case and print ciphertext
        // Else print non-alphabetical character
        int j = 0;

        for (int i = 0, n = strlen(p_text); i < n; i++)
        {
            if (isalpha(p_text[i]))
            {
                if (isupper(p_text[i]))
                    vigenere(p_text[i], keyword[j % keyword_len], UPPER_CASE);
                           
                if (islower(p_text[i]))
                    vigenere(p_text[i], keyword[j % keyword_len], LOWER_CASE);
                
                if (!isspace(p_text[i]))
                    j++;
            }
            else
                printf("%c", p_text[i]);    
        }
        printf("\n");
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

/*
 *  ======================================================
 *  A function that does the vigenere cipher
 *  Check whether keyword is upper/lower case and find
 *  corresponding key value to be used
 *  ======================================================
 */
 
void vigenere(char p_text, char keyword, int ascii_value)
{
    int key;
                
    if (isupper(keyword))
        key = ascii_alpha(keyword, UPPER_CASE);
                   
    if (islower(keyword))
        key = ascii_alpha(keyword, LOWER_CASE);
        
    int result = ascii_alpha(p_text, ascii_value);
    int wrap = (result + key) % 26;
    
    printf("%c", wrap + ascii_value);
}

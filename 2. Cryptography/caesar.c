/*
 *  A simple program to do Caesar Cipher
 *
 *  Full Specifications can be found at:
 *  http://d2o9nyf4hwsci4.cloudfront.net/2014/x/psets/2/pset2/pset2.html
 *
 *  By Johann Nel
 */
 
 #include <cs50.h>
 #include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc, string argv[])
 {
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        
        string p_text = GetString();
          
        for (int i = 0, n = strlen(p_text); i < n; i++)
        {
            if (isalpha(p_text[i]))
            {
                if (isupper(p_text[i]))
                {
                    // Convert to alphabetical order, zero indexed
                    // Where 0 = 'A' and 25 = 'Z'
                    int result = p_text[i] - 65;
                    int wrap = (result + key)%26;
                    // Convert back to ASCII
                    printf("%c",wrap+65);
                }
                
                if (islower(p_text[i]))
                {
                    // Convert to alphabetical order, zero indexed
                    // Where 0 = 'a' and 25 = 'z'
                    int result = p_text[i] - 97;
                    int wrap = (result + key)%26;
                    // Convert back to ASCII
                    printf("%c",wrap+97);
                }
            }
            else
                printf("%c", p_text[i]);
        }
        printf("\n");
    }
    else
    {   
        printf("Please execute with only one argument!\n");
        return 1;
    }
 }

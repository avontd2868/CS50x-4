/*
 *  A simple program to do Caesar Cipher
 *
 *  Full Specifications can be found at:
 *  http://d2o9nyf4hwsci4.cloudfront.net/2014/x/psets/2/pset2/pset2.html
 *
 *  By Johann Nel
 */
 
 #include <cs50.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc, string argv[])
 {
    if (argc == 2)
    {
        printf("%s\n", argv[1]);
        int key = atoi(argv[1]);  // Convert string to int
        
        string p_text = GetString();
        
    }
    else
    {   
        printf("Please execute with only one argument!\n");
        return 1;
    }
 }

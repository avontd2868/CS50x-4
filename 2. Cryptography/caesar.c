/*
 *  A simple program to do Caesar Cipher
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
    }
    else
    {   
        printf("Please execute with only one argument!\n");
        return 1;
    }
 }

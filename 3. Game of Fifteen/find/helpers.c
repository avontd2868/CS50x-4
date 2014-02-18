/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/*
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Look at each element in the "haystack"
    // If values[i] is equal to the value we are looking for
    // return true
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
            return true;
    }
    
    // Return false
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
	// TODO: implement an O(n^2) sorting algorithm
    return;  
}

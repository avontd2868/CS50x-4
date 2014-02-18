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
 * Bubble Sort
 */
void sort(int values[], int n)
{
    // Iterate over list
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            // Compare adjacent elements
            // Largest Element will 'bubble' to the end
            if (values[j] > values[j + 1])
            {  
                // Swap elements that are in the wrong order
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
    
}

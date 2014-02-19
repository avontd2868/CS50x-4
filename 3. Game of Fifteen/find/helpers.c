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
 * Binary Search
 */
bool search(int value, int values[], int n)
{
    int lower_bound = 0;
    int upper_bound = n - 1;
    int mid_point;
    
    // while length of list > 0
    while (lower_bound <= upper_bound)
    {
        // look at middle of list
        mid_point = (lower_bound +  upper_bound) / 2;
        
        // if number found, return true
        if (values[mid_point] == value)
        {
            return true;
        }
        // else if number higher, search left
        else if (values[mid_point] > value)
        {
            upper_bound = mid_point - 1;
        }
        // else if number lower, search right
        else if (values[mid_point] < value)
        {
            lower_bound = mid_point + 1;
        }
    }
    
    // return false if number not found
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

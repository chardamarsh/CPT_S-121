/*Programmer: Charles Marshall
*
  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 8: 

  Date: 10-10-2021

  Description:  This file contains the headers for the functions which do the following:

  1. String concatenation
  2. Binary Search (without <string.h> functions)
  3. Bubble Sort (without strcpy() )
  4. String Palindrome Checker
  5. Sum of prime numbers between 1 and a selected number
  6. Determine the most frequent character in a string

				
  */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct occurrences
{
	int num_occurrences;
	double frequency;
}Occurrences;

/**************************************************************************************************************
  * Function:              my_str_n_cat()                                                                     *
  * Date Created:          12/6/2021                                                                          *
  * Date Last Modified:    12/10/2021                                                                         *
  * Description:		   concatenates a source string to the end of a destination string.                   *
  * Input parameters:      destination string, source string, integer equal to length of destination string   *
  * Returns:               a pointer to the concatenated string.                                              *
  * Preconditions:         none                                                                               *
  * Postconditions:        the destination string will be a concatenation of the two strings.                 *
  *************************************************************************************************************/
char* my_str_n_cat(char* source, char* destination, int n);

/*******************************************************************************************************************
  * Function:              binary_search()                                                                         *
  * Date Created:          12/6/2021                                                                               *
  * Date Last Modified:    12/6/2021                                                                               *
  * Description:		   Finds a target value within an array of integers and returns the target value index.    *
  * Input parameters:      List of integers, target value, and size of the list                                    *
  * Returns:               an integer correspoding to the target values index.                                     *
  * Preconditions:         The target value must exist within the list of integers.                                *
  * Postconditions:        none                                                                                    *
  ******************************************************************************************************************/
int binary_search(int* list, int target, int n);

/******************************************************************************************************************
  * Function:              bubble_sort()                                                                          *
  * Date Created:          12/7/2021                                                                              *
  * Date Last Modified:    12/7/2021                                                                              *
  * Description:		   Sorts a list of strings from smallest to largest.                                      *
  * Input parameters:      Unsorted list of strings, length of list array.                                        *
  * Returns:               sorted list of strings                                                                 *
  * Preconditions:         none                                                                                   *
  * Postconditions:        the list of strings passed into the function will be sorted from smallest to largest.  *
  *****************************************************************************************************************/
void bubble_sort(char* list[], int n);

/**************************************************************************************************************
  * Function:              is_palindrome()                                                                    *
  * Date Created:          12/7/2021                                                                          *
  * Date Last Modified:    12/7/2021                                                                          *
  * Description:		   Checks if a string is a palindrome.                                                *
  * Input parameters:      String, string length                                                              *
  * Returns:               1 if the string is a palindome, 0 otherwise.                                       *
  * Preconditions:         none                                                                               *
  * Postconditions:        none                                                                               *
  *************************************************************************************************************/
int is_palindrome(char* string, int length);

/**************************************************************************************************************
  * Function:              sum_primes()                                                                       *
  * Date Created:          12/7/2021                                                                          *
  * Date Last Modified:    12/7/2021                                                                          *
  * Description:		   Finds the sum of the prime numbers from 1 to n.                                    *
  * Input parameters:      An unsigned positive integer.                                                      *
  * Returns:               The sum of all prime numbers from 1 to n.                                          *
  * Preconditions:         none                                                                               *
  * Postconditions:        none                                                                               *
  *************************************************************************************************************/
int sum_primes(unsigned int n);

/******************************************************************************************************************************
  * Function:              maximum_occurrences()                                                                              *
  * Date Created:          12/8/2021                                                                                          *
  * Date Last Modified:    12/8/2021                                                                                          *
  * Description:		   Finds the most frequent character in a given string.                                               *
  * Input parameters:      string, array of Occurrences structs, pointer to a integer, pointer to a char                      *
  * Returns:               a pointer to the most frequent character, its number of occurrences, and its freqency percentage.  *
  * Preconditions:         none                                                                                               *
  * Postconditions:        the destination string will be a concatenation of the two strings.                                 *
  *****************************************************************************************************************************/
void maximum_occurrences(char* string, Occurrences occur[], int* n, char* ch);


#endif
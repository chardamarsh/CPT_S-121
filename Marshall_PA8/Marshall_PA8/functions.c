/*Programmer: Charles Marshall
*
  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 8:

  Date: 10-10-2021

  Description:  This file contains the definitions for the functions used to do the following:

  1. String concatenation
  2. Binary Search (without <string.h> functions)
  3. Bubble Sort (without strcpy() )
  4. String Palindrome Checker
  5. Sum of prime numbers between 1 and a selected number
  6. Determine the most frequent character in a string


  */

#include "functions.h"
char* my_str_n_cat(char* source, char* destination, int n)
{
	int chars = 0;
	while (destination[chars] != '\0') //find the length of the first string
	{
		chars++;
	}
	for (int i = 0; i < n; i++)
	{
		if (source[i] != '\0')
		{
			(destination[i+chars]) = (source[i]); //add the characters of the second string to the end of the first string
		}
	}
	
	return destination;
}

int binary_search(int *list, int target, int n)
{
	int found = 0, left = 0, right = n-1, mid = 0, targetindex = -1;
	while (found == 0 && left <= right)
	{
		mid = (left + right) / 2;
		if (target == list[mid])
		{
			targetindex = mid;
			found = 1;
		}
		if (target < list[mid])
		{
			right = mid - 1;
		}
		if (target > list[mid])
		{
			left = mid + 1;
		}
	}
	return targetindex;
}

void bubble_sort(char* list[], int n)
{
	int i = n, j = 0;
	char* tempstr = NULL;
	while (i > 1)
	{
		j = 1;
		while (j < i)
		{
			if (strlen(list[j]) < strlen(list[j - 1]))
			{
				tempstr = list[j];
				list[j] = list[j - 1];
				list[j - 1] = tempstr;
			}
			j++;
		}
		i--;
	}
}

int is_palindrome(char* string, int length)
{
	int check = 0, constlength = strlen(string), left = 0;

	--length; //reduce length for next recursive iteration and also skip check of null character
	left = constlength - length - 1;
	while (string[left] == ' ')//ignore spaces
	{
		left++;
	}
	while (string[length] == ' ')
	{
		length--;
	}
	if (length <= (constlength / 2)) //if the length reaches the midpoint of the string, the string is a palindrome 
	{
		return 1;
	}
	if (string[left] == string[length])
	{	
		check = is_palindrome(string, length);//check the next two left and right chars for equivalence
	}	

	return check;
}

int sum_primes(unsigned int n)
{
	int num = 0;
	int sum = 0;
	int check = 0;
	int i = n;

	while (i > 1) //checks if n can be divided by any value from 2 to n-1.
	{
		--i;
		if (n % i != 0) // if n % i is zero, n is not a prime number.
		{
			num++;
		}
	}
	if (num == n - 2) //if n cannot be divided by of the values from 2 to n-1, num == n - 2.
	{
		check = 1;
		sum += n;
	}
	n--; //reduce n by 1 for the next recursive iteration.

	if(n > 2)
	{
		sum += sum_primes(n);
	}
	if (n == 2)
	{
		sum += 2;
	}
	return sum;
}


void maximum_occurrences(char* string, Occurrences occurrence[], int* n, char* ch)
{
	int length = strlen(string);
	int i = 0;
	int a = 0;
	int ascii = 0;
	for (; i < length; i++) // for each char in the array, find its integer value and add 1 to the corresponding cell in the occurrence struct array.
	{
		ascii = (int)string[i];
		occurrence[ascii].num_occurrences += 1;
		occurrence[ascii].frequency = occurrence[ascii].num_occurrences / length;
	}
	for (; a < 128; a++)
	{
		if (occurrence[a].num_occurrences > *n) //find the char with the maximum occurrences and pass them to the char and int pointers.
		{
			*n = occurrence[a].num_occurrences;
			*ch = (char)a;
		}
	}
	return;
}
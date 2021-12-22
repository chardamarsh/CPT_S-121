/*Programmer: Charles Marshall
*
  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 8:

  Date: 10-10-2021

  Description:  This file demonstrates the operation of the functions found in "functions.h" and "functions.c".

  1. String concatenation
  2. Binary Search (without <string.h> functions)
  3. Bubble Sort (without strcpy() )
  4. String Palindrome Checker
  5. Sum of prime numbers between 1 and a selected number
  6. Determine the most frequent character in a string


  */

#include "functions.h"
int main()
{
	//problem #1
	char str1[20] = "COUGARS";
	char str2[20] = "GO ";
	char* ptr2;
	ptr2 = my_str_n_cat(str1, str2, 8);
	printf("1. my_str_n_cat:  %s\n\n", ptr2);
	
	//problem #2
	int list[10] = { 1, 12, 23, 26, 34, 39, 42, 89 };
	int target = 39;
	int targetindex = 0;
	targetindex = binary_search(list, target, 10);
	printf("2. Binary Search target index: %d\n", targetindex);

	//problem #3
	char* strlist[] = { "asdfghjk", "asd", "as", "a", "qwerty"};
	bubble_sort(strlist, 5);
	printf("\n3. Bubble sort results:\n\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", strlist[i]);
	}

	//problem #4
	char* str3 = "RACECAR";
	char* str4 = "RACE CAR";
	char* str5 = "never odd or even";
	char* str6 = "this is not a palindome";
	int check = 2;
	check = is_palindrome(str3, 7);
	printf("\n4. Palindrome Checker:\n\nRACECAR: %d\n", check);
	check = is_palindrome(str4, 8);
	printf("RACE CAR: %d\n", check);
	check = is_palindrome(str5, 17);
	printf("never odd or even: %d\n", check);
	check = is_palindrome(str6, 23);
	printf("this is not a palindrome: %d\n", check);

	//problem #5
	int n = 17;
	int sum = 0;
	sum = sum_primes(n);
	printf("\n5. Sum of prime numbers in the range 1 to %d : %d\n", n, sum);

	//problem 6
	char* str7 = "test string";
	Occurrences occur[128] = { {0, 0.0} };
	int number = 0;
	char ch;
	maximum_occurrences(str7, occur, &number, &ch);
	printf("\n6. Maximum Occurrences: The character %c occurs the most often in the string with %d occurrences.\n", ch, number);


	return 0;
}
/*
Programmer: Charles Marshall
Class: CptS 121, Fall 2021, Lab Section 11
Programming Assignment: PA 2
Date: September 15, 2021
Description: This program contains a variety of different mathematical functions. The original code from PA 1 has now been adapted to fit the rubric for PA 2, which requires a header file and two source files.
*/

#include "equations.h"

// 1. Series Resistance
int calculate_series_resistance(int R1, int R2, int R3)
{
	return R1 + R2 + R3;
}

// 2. Total Sales Tax
double calculate_total_sales_tax(double sales_tax_rate, double item_cost)
{
	double calculate_total_sales_tax = (sales_tax_rate / 100) * item_cost;
	return calculate_total_sales_tax;
}

// 3. Pyramid volume
double calculate_pyramid_volume(double l, double w, double h)
{
	double calculate_pyramid_volume = ((l * w * h) / 3);
	return calculate_pyramid_volume;
}

// 4. Total parallel resistance
double calculate_parallel_resistance(double PR1, double PR2, double PR3)
{
	double calculate_parallel_resistance = 1 / ((1 / PR1) + (1 / PR2) + (1 / PR3));
	return calculate_parallel_resistance;
}

// 5. ASCII character encoding
char return_encoded_character(char plaintext_character, int shift)
{
	char return_encoded_character = (plaintext_character + shift);
	return return_encoded_character;
}

// 6. Distance between two points(x, y coordinates)
double calculate_distance_value(int x1, int x2, int y1, int y2)
{
	double calculate_distance_value = (sqrt(pow(x1 - x2, 2) + (pow(y1 - y2, 2))));
	return calculate_distance_value;
}

// 7. General algebraic equation
double calculate_y(int a, double x, double y, double z)
{
	double calculate_y = ((-3.0 / 14.0) * (-z + x / (a % 2) + PI));
	return calculate_y;
}
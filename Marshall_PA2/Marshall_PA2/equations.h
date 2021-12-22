/*
Programmer: Charles Marshall
Class: CptS 121, Fall 2021, Lab Section 11
Programming Assignment: PA 2
Date: September 15, 2021
Description: This program contains a variety of different mathematical functions.  The original code from PA 1 has now been adapted to fit the rubric for PA 2, which requires a header file and two source files.
*/


#ifndef EQUATIONS_H
#define EQUATIONS_H
#define _CRT_SECURE_NO_WARNINGS 

#define PI 3.14159

#include <stdio.h> 

#include <math.h>
//1. Series Resistance
int calculate_series_resistance(int R1, int R2, int R3);

//2. Sales Tax Rate
double calculate_total_sales_tax(double sales_tax_rate, double item_cost);

//3. Pyramid volume
double calculate_pyramid_volume(double l, double w, double h);

//4. Total parallel resistance
double calculate_parallel_resistance(double PR1, double PR2, double PR3);

//5. ASCII character encoding
char return_encoded_character(char plaintext_character, int shift);

//6. Distance between two points(x, y coordinates)
double calculate_distance_value(int x1, int x2, int y1, int y2);

//7. General algebraic equation
double calculate_y(int a, double x, double y, double z);

#endif

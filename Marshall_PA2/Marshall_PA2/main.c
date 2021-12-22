/*
Programmer: Charles Marshall
Class: CptS 121, Fall 2021, Lab Section 11
Programming Assignment: PA 2
Date: September 15, 2021
Description: This program contains a variety of different mathematical functions. The original code from PA 1 has now been adapted to fit the rubric for PA 2, which requires a header file and two source files.
*/

#include "equations.h"

int main(void)

{
    // #1: Total series resistance: series_resistance = R1 + R2 + R3, for 3 resistors. R1, R2, and R3 are integers.

    int R1 = 0, R2 = 0, R3 = 0, series_resistance = 0;


    printf("1. Please enter the values of three resistors as integers: ");
    scanf("%d%d%d", &R1, &R2, &R3);

    series_resistance = calculate_series_resistance(R1 , R2 , R3);

    printf("\nThe total series resistance is: %d", series_resistance);



    // #2: Sales tax: total_sales_tax = sales_tax_rate * item_cost

    double total_sales_tax = 0, sales_tax_rate = 0, item_cost = 0;

    printf("\n\n2. This function finds the total sales tax of an item based on the items' cost and sales tax rate. \nPlease enter the item cost in dollars and cents: ");
    scanf("%lf", &item_cost);

    printf("\nNext, please enter the sales tax rate percentage:");
    scanf("%lf", &sales_tax_rate);

    total_sales_tax = calculate_total_sales_tax(sales_tax_rate, item_cost);

    printf("\nThe total sales tax is: $ %0.3f", total_sales_tax); //"%0.3f" is used to set the precision of the displayed floating points reults to the thousandths place, as per assignment requirements.



    // #3. Volume of a right rectangular pyramid: volume_pyramid = (l * w * h) / 3, where l and w are the length and width of the base, respectively, and h is the height of the pyramid.

    double l = 0, w = 0, h = 0, volume_pyramid = 0;

    printf("\n\n3. This function finds the volume of a right rectangular pyramid. \nFirst, please enter the length of the pyramid:");
    scanf("%lf", &l);
    printf("\nNext, please enter the width of the pyramid:");
    scanf("%lf", &w);
    printf("\nFinally, enter the height of the pyramid:");
    scanf("%lf", &h);

    volume_pyramid = calculate_pyramid_volume(l, w, h);

    printf("\nthe volume of the pyramid is: %0.3f", volume_pyramid);



   // #4. Total parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3), for 3 resistors.

    double PR1 = 0, PR2 = 0, PR3 = 0, parallel_resistance = 0;

    printf("\n\n4. This function finds the total parallel resistance of three resistors.");
    printf("\nPlease enter the values for resistor 1: ");
    scanf("%lf", &PR1);
    printf("\nPlease enter the values for resistor 2: ");
    scanf("%lf", &PR2);
    printf("\nPlease enter the values for resistor 3: ");
    scanf("%lf", &PR3);

    parallel_resistance = calculate_parallel_resistance(PR1, PR2, PR3);

    printf("\nThe total parallel resistance is: %0.3f", parallel_resistance);



    //#5. Character encoding: encoded_character = (plaintext_character – 'a') + 'A' - shift; shift is an integer

    char plaintext_character = '\0', encoded_character = '\0';
    int shift = 0;

    printf("\n\n5. This function encodes a user defined alphabetical character by shifting the ASCII number values of the character by a user defined integer, which may be positive or negative.");
    printf("\nPlease enter an alphabetical character: ");
    scanf(" %c", &plaintext_character);
    printf("\nPlease input the desired shift integer: ");
    scanf("%d", &shift);

    encoded_character = return_encoded_character(plaintext_character, shift);

    printf("\nThe encoded character is:  %c", encoded_character);



    //#6. Distance between two points: distance = square root of ((x1 - x2)2 + (y1 - y2)2)

    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    double distance_value = 0;

    printf("\n\n6. This function finds the distance between two (x,y) coordinates.");
    printf("\nPlease enter the first x coodinate:");
    scanf("%d", &x1);
    printf("\nPlease enter the first y coodinate:");
    scanf("%d", &y1);
    printf("\nPlease enter the second x coodinate:");
    scanf("%d", &x2);
    printf("\nPlease enter the second y coodinate:");
    scanf("%d", &y2);

    distance_value = calculate_distance_value(x1, x2, y1, y2);

    printf("\nThe distance between the two points is: %0.3f", distance_value);



    //#7. General equation: y = y / (3 / 17) - z + x / (a % 2) + PI
    //Note: For this function, I decided to simplify the equation so that y would only appear on the left side of the equation. The resulting equation is : y =  (-3/14)*(- z + x / (a % 2) + PI).

    int a = 0;
    double x = 0, y = 0, z = 0;

    printf("\n\nThis function solves the equation y = y / (3 / 17) - z + x / (a (modulo) 2) + pi.\n     x, z, and a will be defined by the user.");
    printf("\nPlease enter a value for the variable x:");
    scanf("%lf", &x);
    printf("\nPlease enter a value for the variable z:");
    scanf("%lf", &z);
    printf("\nPlease enter a value for the variable a:");
    scanf("%d", &a);

    y = calculate_y(a, x, y, z);

    printf("\nThe solution for the equation is y = %0.3f", y);
    

    return 0;

}
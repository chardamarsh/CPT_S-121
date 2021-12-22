/*Programmer: Charles Marshall
*
  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 3: Statistical Analysis of Student Records

  Date: 9-21-2021

  Description:  This file Reads five records from the input file (input.dat). Using the equation protoypes in the header file, and the function definitions in the equations source file, the program does the following:

				Calculates the sum of the GPAs;
				Calculates the sum of the class standings;
				Calculates the sum of the ages;

				Calculates the mean of the GPAs, writing the result to the output file (output.dat);
				Calculates the mean of the class standings, writing the result to the output file (output.dat);
				Calculates the mean of the ages, writing the result to the output file (output.dat);

				Calculates the deviation of each GPA from the mean (Hint: need to call calculate_deviation ( ) 5 times)
				Calculates the variance of the GPAs
				Calculates the standard deviation of the GPAs, writing the result to the output file (output.dat);

				Determines the min of the GPAs, writing the result to the output file (output.dat);
				Determines the max of the GPAs, writing the result to the output file (output.dat);

				Closes the input and output files (i.e. input.dat and output.dat)

  */
	
#include "pa3equations.h"

int main(void)
{

		FILE* infile = NULL, * outfile = NULL; // file pointer declarations, initally set to NULL


		//variable declarations for the program
		int id_number1 = 0, id_number2 = 0, id_number3 = 0, id_number4 = 0, id_number5 = 0;// Student ID numbers (8 integer number)
			//number_of_students = 0; //total number of students

		int class_standing1 = 0, class_standing2 = 0, class_standing3 = 0, class_standing4 = 0, class_standing5 = 0,  // Class standings from 1(freshman) to 4(senior)
			sum_class_standing = 0;

		double mean_class_standing = 0.0; //note: Although class standings are integers, the mean class standing was set to a double precision number for accuracy.

		double age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0, //age of students in years, as a floating point value
			age_sum = 0.0, mean_age = 0.0;

		double gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0, //Student GPA (0.0 - 4.0)
			max_gpa = 0.0, min_gpa = 0.0; // minimum and maximum GPA

		double gpa_deviation1 = 0.0, gpa_deviation2 = 0.0, gpa_deviation3 = 0.0, gpa_deviation4 = 0.0, gpa_deviation5 = 0.0; // GPA deviation

		double gpa_variance = 0.0, gpa_sum = 0.0, gpa_mean = 0.0, gpa_standard_deviation = 0.0; // GPA variance, sum, mean, and standard deviation

		infile = fopen("input.dat", "r"); // opens input file for read mode.
		outfile = fopen("output.dat", "w"); // opens output file for write mode.

	if ((infile == NULL) || (outfile == NULL))
		{
			printf("%s could not be opened for reading, or %s could not be opened for writing.\n", "input.dat", "output.dat");
			printf("Exiting program...");
		}
	else
	{
		printf("Statistical Analysis of student records completed.\n");


		//read information for Student 1 from input.dat
		id_number1 = read_integer(infile);
		gpa1 = read_double(infile);
		class_standing1 = read_integer(infile);
		age1 = read_double(infile);

		//read information for Student 2 from input.dat
		id_number2 = read_integer(infile);
		gpa2 = read_double(infile);
		class_standing2 = read_integer(infile);
		age2 = read_double(infile);

		//read information for Student 3 from input.dat
		id_number3 = read_integer(infile);
		gpa3 = read_double(infile);
		class_standing3 = read_integer(infile);
		age3 = read_double(infile);

		//read information for Student 4 from input.dat
		id_number4 = read_integer(infile);
		gpa4 = read_double(infile);
		class_standing4 = read_integer(infile);
		age4 = read_double(infile);

		//read information for Student 5 from input.dat
		id_number5 = read_integer(infile);
		gpa5 = read_double(infile);
		class_standing5 = read_integer(infile);
		age5 = read_double(infile);

		//calculate the sum of all GPAs
		gpa_sum = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);

		//calculate sum of all ages
		age_sum = calculate_sum(age1, age2, age3, age4, age5);

		//calculate sum of all class standings
		sum_class_standing = calculate_sum(class_standing1, class_standing2, class_standing3, class_standing4, class_standing5);

		//calculate and print mean of all GPAs and print the mean to output.dat
		gpa_mean = calculate_mean(gpa_sum, 5);
		//printf("%lf", gpa_mean);
		print_double(outfile, gpa_mean);

		//calculate and print mean of all class standings
		mean_class_standing = calculate_mean(sum_class_standing, 5);
		print_double(outfile, mean_class_standing);

		//calculate mean of all ages
		mean_age = calculate_mean(age_sum, 5);
		print_double(outfile, mean_age);

		//calculate deviation of each GPA from mean
		gpa_deviation1 = calculate_deviation(gpa1, gpa_mean);

		gpa_deviation2 = calculate_deviation(gpa2, gpa_mean);

		gpa_deviation3 = calculate_deviation(gpa3, gpa_mean);

		gpa_deviation4 = calculate_deviation(gpa4, gpa_mean);

		gpa_deviation5 = calculate_deviation(gpa5, gpa_mean);

		//calculate GPA variance

		gpa_variance = calculate_variance(gpa_deviation1, gpa_deviation2, gpa_deviation3, gpa_deviation4, gpa_deviation5, 5);

		//calculate and print the GPA standard deviation

		gpa_standard_deviation = calculate_standard_deviation(gpa_variance);
		print_double(outfile, gpa_standard_deviation);

		//calculate and print the minimum GPA
		min_gpa = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);
		print_double(outfile, min_gpa);

		//calculate and print the maximum GPA
		max_gpa = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);
		print_double(outfile, max_gpa);

		//close infile (input.dat) and close outfile (output.dat)
		fclose(infile);
		fclose(outfile);
	}
	return 0;
}
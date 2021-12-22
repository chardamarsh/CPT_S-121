/*Programmer: Charles Marshall

  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 4: A Game of Chance "Craps"

  Date: 10-12-2021

  Description:  This file contains the function protoypes necessary to do the following:

		Gives the user 3 options:
			1. Print the rules of Craps;
			2. Play the game of Craps;
			3. Exit the program.

		The second option does the following in order:
			Prompts the user to enter an initial bank balance;
			Prompts the user to enter a wager that is not greater than the set bank balance;
			Returns the sum of two randomly rolled 6-sided dice;
			Checks the sum of the first dice roll:
				If the sum is 7 or 11, the player wins and the wager is added to their bank balance.
				If the sum is 2, 3, or 12, the player loses and the wager is deducted from their bank balance.
				If the sum is not 2, 3, 11, or 12, the player's point is set:
					If a 7 is rolled before rolling the player's point, the player loses and the wager is deducted from their bank balance.
					If the player's point is rolled before rolling a 7, the player wins and the wager is added to their bank balance.
			After each round, the player is given the option to play another round with their updated bank balance, or exit the program.
  */
#define _CRT_SECURE_NO_WARNINGS

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void print_menu(void); //Prints out the rules of the game of "craps". Displays options 1-3.

int get_option(void); //Prompts uer to select a menu option 1-3.

int print_and_validate(void); //Initiates an option 1-3 based on user input. 

void print_rules(); // Prints the rules of Craps if option 1 is selected.

int roll_die(void); //Rolls one die. This function should randomly generate a value between 1 and 6, inclusively. Returns the value of the die.

int calculate_sum_dice(int die1_value, int die2_value); //Sums together the values of the two dice and returns the result.Note: this result may become the player's point in future rolls.

void display_dice(int die1, int die2); //displays the value of the two rolled dice.

double get_bank_balance(void); //Prompts the player for an initial bank balance from which wagering will be added or subtracted. The player entered bank balance (in dollars, i.e. $100.00) is returned.

double get_wager_amount(void); //Prompts the player for a wager on a particular roll. The wager is returned.

int check_wager_amount(double wager_amount, double bank_balance); //Checks to see if the wager is within the limits of the player's available balance.
// If the wager exceeds the player's allowable balance, then 0 is returned; otherwise 1 is returned.

int is_win_loss_or_point(int point_value, double wager); // Determines the result of the first dice roll.If the sum is 7 or 11 on the roll, the player wins and 1 is returned.
//If the sum is 2, 3, or 12 on the first throw (called "craps"), the player loses(i.e.the "house" wins) and 0 is returned.If the sum is 4, 5, 6, 8, 9, or 10 on the first throw,
//then the sum becomes the player's "point" and -1 is returned.

int is_point_loss_or_neither(int dice_sum, int point_value, double wager); // Determines the result of any successive roll after the first roll.If the sum of the roll is the point_value, then 1 is returned.
// If the sum of the roll is a 7, then 0 is returned.Otherwise, -1 is returned.

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract); // If add_or_subtract is 1, then the wager amount is added to the bank_balance.
//If add_or_subtract is 0, then the wager amount is subtracted from the bank_balance.Otherwise, the bank_balance remains the same.The bank_balance result is returned.

int display_total_rolls(int die_rolls);  // Prints a message stating the number of rolls taken so far by the player for each round.

int replay_game(int continue_game); //prompts the user to enter 0 to play another round, or enter 1 to exit the program.

#endif
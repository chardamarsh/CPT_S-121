/*Programmer: Charles Marshall

  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 4: A Game of Chance "Craps"

  Date: 10-12-2021

  Description:  This file contains the definitions of functions needed to do the following:

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
#include "functions.h"

void print_menu(void) //Prints the main menu, giving the user the option to display the rules of craps, play the game, or exit the program.
{
printf("\n				Welcome to the Craps table!\n\n		   	   Please select one of following options:\n\n");
printf("					1. Display rules.\n");
printf("					2. Play game.\n");
printf("					3. Exit.\n");
}

int get_option(void) //Scans the user input for the desired option (must be 1-3).
{
	int option = 0;

	scanf("%d", &option);

	return option;
}

int print_and_validate(void) //Validates the user input and re-prints the menu if the user input is not 1-3.
{
	int option = 0;

	do
	{
		print_menu();
		option = get_option();
	} while (option < 1 || option > 3);

	return option;
}

void print_rules(void) //Displays the rules of Craps to the user if 1 is selected.
{
	printf("\n\n	RULES OF CRAPS:\n\n	A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.\n\n");
	printf("	- After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n\n");
	printf("	- If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw\n	(called Craps), the player loses (i.e. the house wins).\n\n");
	printf("	- If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point.\n\n");
	printf("	- To win, you must continue rolling the dice until the sum of the two dice match your point. The player\n	loses by rolling a 7 before making the point.\n\n");
}

int roll_die(void) //Rolls one die. This function should randomly generate a value between 1 and 6, inclusively. Returns the value of the die.
{
	return rand() % 6 + 1;
}

int calculate_sum_dice(int die1, int die2) //Sums together the values of the two dice and returns the result. Note: this result will become the player's point in future rolls if the player does not win or lose on the first roll.
{
	int sum_dice = 0;
	sum_dice = die1 + die2;
	printf("\n	Dice Sum: %d\n", sum_dice);
	return sum_dice;
}

void display_dice(int die1, int die2) //displays the value of the two dice after a roll.
{
	printf("\n	die1: %d\n	die2: %d\n", die1, die2);
}

double get_bank_balance(void) //Prompts the player for an initial bank balance from which wagering will be added or subtracted. The player entered bank balance (in dollars, i.e. $100.00) is returned.
{
	double balance = 0;
	printf("\n	Please enter your bank balance:\n");
	scanf("	%lf", &balance);
	printf("\n	Your bank balance of $ %.2lf has been set.\n", balance);
	return balance;
}

double get_wager_amount(void) //Prompts the player for a wager on a particular roll. The wager is returned.
{
	double wager = 0;
	printf("\n	How much do you want to wager?\n");
	scanf("	%lf", &wager);
	return wager;
}

int check_wager_amount(double wager_amount, double bank_balance) //Checks to see if the wager is within the limits of the player's available balance.
// If the wager exceeds the player's allowable balance, then 1 is returned; otherwise 2 is returned.
{
	
	if (wager_amount > bank_balance)
	{
		printf("\n	Your wager exceeds your bank account balance. Please enter a valid wager.\n");
		return 0;
	}
	else
	{
		printf("\n	Your wager of $ %.2lf has been set.\n", wager_amount);
		return 1;
	}
}

int is_win_loss_or_point(int point_value, double wager) // Determines the result of the first dice roll.If the sum is 7 or 11 on the roll, the player wins and 1 is returned.
//If the sum is 2, 3, or 12 on the first throw (called "craps"), the player loses(i.e.the "house" wins) and 0 is returned.If the sum is 4, 5, 6, 8, 9, or 10 on the first throw,
//then the sum becomes the player's "point" and -1 is returned.
{
	if ((point_value == 7) || (point_value == 11))
	{
		printf("\n	You Win! Your wager of $ %.2lf has been added to your bank account.\n", wager);
		return 1;
	}
	if ((point_value == 2) || (point_value == 3) || (point_value == 12))
	{
		printf("\n	Craps! You Lose. Your wager of $ %.2lf has been deducted from your bank account.\n", wager);
		return 0;
	}
	else
	{
		printf("\n	Your dice roll of %d has been established as your point. Roll a(n) %d again before rolling a 7 to win.\n", point_value, point_value);
		return -1;
	}
}
int is_point_loss_or_neither(int dice_sum, int point_value, double wager) // Determines the result of any successive roll after the first roll.If the sum of the roll is the point_value, then 1 is returned.
// If the sum of the roll is a 7, then 0 is returned.Otherwise, -1 is returned.
{
	if (dice_sum == point_value)
	{
		printf("\n	You Win! Your wager of $ %.2lf has been added to your bank account.\n", wager);
		return 1;
	}
	if (dice_sum == 7)
	{
		printf("\n	You Lose. Your wager of $ %.2lf has been deducted from your bank account.\n", wager);
		return 0;
	}
	else
	{
		printf("\n	Point not met.\n");
		return -1;
	}
}

double adjust_bank_balance(double bank_balance, double wager, int add_or_subtract) // If add_or_subtract is 1, then the wager amount is added to the bank_balance.
//If add_or_subtract is 0, then the wager amount is subtracted from the bank_balance.Otherwise, the bank_balance remains the same.The bank_balance result is returned.
{
	if (add_or_subtract == 1)
	{
		bank_balance = bank_balance + wager;
		printf("\n	your bank balance is now $ %.2lf.\n", bank_balance);
		return bank_balance;
	}
	if (add_or_subtract == 0)
	{
		bank_balance = bank_balance - wager;
		printf("\n	Your bank balance is now $ %.2lf.\n", bank_balance);
		return bank_balance;
	}
	else
	{
		printf("\n	Your bank balance is still $ %.2lf.\n", bank_balance);
		return bank_balance;
	}
}
int display_total_rolls(int die_rolls) // Prints a message stating the number of rolls taken so far by the player for each round.
{
	if (die_rolls != -1)
	{
		printf("\n	Total die rolls this round: %d\n", die_rolls);
		die_rolls++;
	}
	return die_rolls;
}

int replay_game(int continue_game) //prompts the user to enter 0 to play another round, or enter 1 to exit the program.
{
	printf("\n	Enter 0 to play another round with your updated bank balance, or 1 to exit the program.\n");
	scanf("	%d", &continue_game);
	return continue_game;
}
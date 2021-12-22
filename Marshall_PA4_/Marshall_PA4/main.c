/*Programmer: Charles Marshall

  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 4: A Game of Chance "Craps"

  Date: 10-12-2021

  Description:  This program is deisgned to simulate a game of Craps by doing the following:

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

int main(void)
{


	int option = 0, die1 = 0, die2 = 0, dice_sum = 0, add_or_subtract = 0, wager_check = 0, point_value = 0;
	double bank_balance = 0.0, wager_amount = 0.0;
	int continue_game = 0;
	char ch = NULL;

	srand((unsigned int)time(NULL));
	
		
	option = print_and_validate();

	switch (option)
		{

		case 1: // Prints the rules of Craps
		print_rules();
		break;


		case 2: // Play Craps

		bank_balance = get_bank_balance();

		while(continue_game == 0)
		{
			wager_amount = get_wager_amount();

			wager_check = check_wager_amount(wager_amount, bank_balance);

			while (wager_check != 1)
			{
				wager_amount = get_wager_amount();
				wager_check = check_wager_amount(wager_amount, bank_balance);
			}
			int die_rolls = 1;
			printf("\n	Press ENTER to roll the dice.\n");
			scanf("%c", &ch);
			scanf("%c", &ch);

			die1 = roll_die();
			die2 = roll_die();
			display_dice(die1, die2);
			point_value = calculate_sum_dice(die1, die2);
			die_rolls = display_total_rolls(die_rolls);
			add_or_subtract = is_win_loss_or_point(point_value, wager_amount);

			while (add_or_subtract == -1)
			{
				printf("\n	Press ENTER to roll the dice.\n");
				scanf("%c", &ch);
				die1 = roll_die();
				die2 = roll_die();
				display_dice(die1, die2);
				dice_sum = calculate_sum_dice(die1, die2);
				add_or_subtract = is_point_loss_or_neither(dice_sum, point_value, wager_amount);
				die_rolls = display_total_rolls(die_rolls);
			}
			bank_balance = adjust_bank_balance(bank_balance, wager_amount, add_or_subtract);
			continue_game = replay_game(continue_game);
		}
		
		
		break;


		case 3: // Exits the program
		break;
		}
			


		return 0;
}
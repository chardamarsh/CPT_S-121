/*Programmer: Charles Marshall

  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 5: Yahtzee

  Date: 10-27-2021

  Description:  This file uses a compilation of defined functions to play a game of Yahtzee.

  */
#include"functions.h"

int main(void)
{
	int option = 0;

	int dice[5] = { 0 };

	int categories1[13] = { 0 }, categories2[13] = { 0 };

	int scores1[13] = { 0 }, scores2[13] = { 0 };

	int player1 = 1, player2 = 2;

	int total_score1 = 0, total_score2 = 0;

	int grand_total1 = 0, grand_total2 = 0;


	

	srand((unsigned int)time(NULL));

	
	option = print_and_validate();

	while (option == 1  || option == 2)
	{
		while (option == 1)
		{
			print_rules();
			printf("\n\nEnter 1 to display the rules again, enter 2 to proceed to the game, or enter 3 to exit the program.\n");
			scanf("%d", &option);
			system("cls");
		}

		system("cls");

		while (option == 2)
		{
			int rounds = 1;
			for (rounds = 1; rounds < 14; rounds++) //set rounds < 14 to rounds < 2 to test printing the scores and the winner, as well as ability to replay game.
			{
				printf("\t\t\tROUND %d", rounds);
				printf("\t\t\tPLAYER %d", player1);
				roll_dice(dice, 5);
				print_dice(dice, 5);
				keep_or_reroll(dice, 5);
				choose_category(dice, categories1, scores1);
				grand_total1= print_scorecard(scores1, player1);

				system("pause");
				system("cls");

				printf("\t\t\tROUND %d", rounds);
				printf("\t\t\tPLAYER %d", player2);
				roll_dice(dice, 5);
				print_dice(dice, 5);
				keep_or_reroll(dice, 5);
				print_dice(dice, 5);
				choose_category(dice, categories2, scores2);
				grand_total2 = print_scorecard(scores2, player2);

				system("pause");
				system("cls");


			
			}
			determine_winner(grand_total1, grand_total2);
			scanf("%d", &option);
			system("cls");
		}
	}

	printf("\n\n\nGoodbye!\n\n\n");
	
	return 0;
}


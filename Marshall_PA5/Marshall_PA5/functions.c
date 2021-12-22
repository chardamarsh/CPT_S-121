/*Programmer: Charles Marshall

  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 5: Yahtzee

  Date: 10-27-2021

  Description:  This file contains the necessary functions for a game of Yahtzee.

  */
#include "functions.h"

void print_menu(void)
{
	printf("\n				Welcome to the Yahtzee!\n\n		   	   Please select one of following options:\n\n");
	printf("					1. Display rules.\n");
	printf("					2. Play game.\n");
	printf("					3. Exit.\n");
}

int get_option(void)
{
	int option = 0;

	scanf("%d", &option);

	return option;
}

int print_and_validate(void)
{
	int option = 0;

	do
	{
		print_menu();
		option = get_option();
	} while (option < 1 || option > 3);

	return option;
}

void print_rules(void)
{
	printf("\nHow to Play Yahtzee\n\n"


		"Beginning with the starting player, players will take turns one at a time.The game consists of thirteen rounds and at the end of the thirteenth round then the game will end.\n (All the categories on the players’ score cards will be completely filled in at that point.)\n\n"

		"At the start of a turn, the player takes all 5 dice and rolls them.They can then roll some or all of the dice up to two more times, setting aside any dice they’d like to keep and rerolling the rest.\nThe dice can be scored after any of the rolls, but scoring the dice ends the player’s turn.\nSetting dice aside after one roll does not prevent one or more of them from being rolled again on any subsequent roll if the player so chooses.\n\n"

		"Each player’s goal is to try and score as high as they can in one of the thirteen score categories.\n\n"

		"To score the dice, the player selects one of the score categories and writes the score into it. Each category can be scored only once per game(except for the Yahtzee category).\nCategories can be filled in any order. A player must score the dice on their turn even if it turns out that there are no good categories remaining to score in. Once a category is filled it may not be changed.\n\n"

		"A player may write a score of zero in any category if they have rolled no point - generating results or if they simply choose to do so.For example, a player could put a roll of 2 - 4 - 5 - 6 - 6 into the Ones category even though it would score zero points.\n\n"

		"After marking their score on their score card, the player’s turn endsand play proceeds to the player on their left.\n\n"

		"The categories on the score card are divided into two sections.The categories in the Upper Section are :\n\n"

		"Ones:\n"

		"\tHow many points are scored : Receive 1 point for each 1 rolled\n\n"
		"Twos:\n"

		"\tHow many points are scored : Receive 2 points for each 2 rolled\n\n"
		"Threes:\n"

		"\tHow many points are scored : Receive 3 points for each 3 rolled\n\n"
		"Fours:\n"

		"\tHow many points are scored : Receive 4 points for each 4 rolled\n\n"
		"Fives:\n"

		"\tHow many points are scored : Receive 5 points for each 5 rolled\n\n"
		"Sixes:\n"

		"\tHow many points are scored : Receive 6 points for each 6 rolled\n\n"
		"Ultimately, each player will want to tryand score a grand total of 63 or more points in the Upper Section by the end of the game.If they do so, they receive a 35 point bonus.\n\n"

		"The categories in the Lower Section are :\n\n"

		"Three of a Kind\n"
		"\tWhat is needed to score : Three dice of the same number\n"
		"\tHow many points are scored : Add up all the spots on all the dice. (For example, rolling 2 - 2 - 2 - 3 - 5 would score a total of 14 points.)\n\n"
		"Four of a Kind\n"
		"\tWhat is needed to score : Four dice of the same number\n"
		"\tHow many points are scored : Add up all the spots on all the dice\n\n"
		"Full House\n"
		"\tWhat is needed to score : Three dice showing the same number, and two dice showing another number.\n"
		"\tHow many points are scored : 25 points\n\n"
		"Small Straight\n"
		"\tWhat is needed to score : Any four consecutive numbers(for example, 3 - 4 - 5 - 6)\n"
		"\tHow many points are scored : 30 points\n\n"
		"Large Straight\n"
		"\tWhat is needed to score : Any five consecutive numbers(for example, 1 - 2 - 3 - 4 - 5)\n"
		"\tHow many points are scored : 40 points\n\n"
		"Yahtzee(or Five of a Kind)\n"
		"\tWhat is needed to score : All 5 dice showing the same number\n"
		"\tHow many points are scored : 50 points\n\n"
		"Chance\n"
		"\tWhat is needed to score : Any combination of dice\n"
		"\tHow many points are scored : Add up all the spots on all the dice\n\n"
		"It’s possible that a player will end up with a combination of dice that could be used in more than one category.\nFor example, a roll of 3 - 3 - 3 - 4 - 4 could be scored as threes or fours in the Upper Section, or as a Full House or a Three - Of - A - Kind, or Chance in the Lower Section.\nThe player has the option of scoring the dice in any one of those categories as long as they have not been used previously in the game.\n\n"

		"Special Yahtzee Scoring\n"
		"\tIf a player rolls a Yahtzee on their turn but they have already filled in the Yahtzee category in a previous turn, then special scoring rules apply :\n\n"

		"\tIf the player has already filled in their Yahtzee box with a score of 50, they receive a Yahtzee bonus of 100 additional points.However, if their Yahtzee box was previously filled in with a score of zero then they don’t receive the Yahtzee bonus.\n\n"

		"\tThe player then selects another category(other than the Yahtzee category) to score the dice as normal.\n\n"

		"\tIf the category in the Upper Section that corresponds to the numbers in the Yahtzee is unused, then the player must use that category.\n\n"
		"\tIf the corresponding box in the Upper Section has been used already then the player may choose to score one of the unused boxes in the Lower Section.\n\tIn this case, the Yahtzee that the player has rolled acts as a “Joker” so that it can be placed in the Full House, Small Straight,\n\t and Large Straight categories if the player so wishes, even though it may not meet the standard requirements for those categories.\n\n"
		"\tIf the player can’t use a box in either the upper or Lower Section, they score zero points.\n\n"

		"Winning\n"
		"\tOnce all players have taken thirteen turns(and subsequently filled in all the categories on their score card) the game ends.\n\n"

		"Players add up their scores in the following manner :\n\n"

		"\tUpper Section\n"
		"\t\tMark the total sum of the Upper Section score in the corresponding total score box.If a player scores 63 or more points in the Upper Section then they receive a 35 point bonus.\n\n"

		"\tLower Section\n"
		"\t\tMark the total sum of the Lower Section score in the corresponding total score box.Add 100 points for each check in the Yahtzee bonus box.\n\n"

		"\tGrand Total\n"
		"\t\tAdd the total sums of the upperand Lower Sections together.This is the player’s total score for the game.\n\n\n"

		"The player with the highest total score is the winner!In the case of a tie, all tied players share the victory.\n\n\n");

}

void roll_dice(int dice[5])
{
	int dice_index = 0;
	printf("\nPress any key to roll the dice.\n");
	system("pause");
	while (dice_index < 5)
	{
		dice[dice_index]= rand() % 6 + 1;
		dice_index++;
	}
}

void keep_or_reroll(int dice[5])
{
	int num_rolls = 1; //counts number of rerolls
	int dice_id = 0; //identifies which dice to reroll 1-5
	int num_dice = 0; //number of dice to reroll
	int reroll_check = 1; //used to loop dice reroll the for the number of dice selected
	char y_n = '\0'; //y or n used to determine if reroll or not
	while ((y_n != 'y') && (y_n != 'n'))
	{
		printf("\nDo you want to re-roll? Enter y or n.\n");
		scanf("%c", &y_n);
		scanf("%c", &y_n);
	}
	
	if (y_n == 'y')
	{
		while (num_rolls < 3)
		{
			reroll_check = 1;
			printf("\n\nHow many dice do you want to reroll?\n");
			scanf("%d", &num_dice);
			printf("\nChoose the dice you would like to re-roll by their identifying number (e.g enter 5 to reroll die 5). Enter one die at a time.\n");
			while (reroll_check <= num_dice)
			{
				printf("\nEnter a die to reroll:\n");
				scanf("%d", &dice_id);
				dice[dice_id-1] = rand() % 6 + 1;
				reroll_check++;
			}
			num_rolls++;
			print_dice(dice);
			if (num_rolls < 3)
			{
				printf("\nDo you want to reroll again? You have %d rerolls left.(y/n)\n", (3 - num_rolls));
				scanf("%c", &y_n);
				scanf("%c", &y_n);
			}
			if (y_n == 'n')
			{
				break;
			}
		} 
	}
	if (y_n == 'n')
	{
		return;
	}
}

void print_dice(int dice[5])
{
	printf("\nDie 1:\t%d\nDie 2:\t%d\nDie 3:\t%d\nDie 4:\t%d\nDie 5:\t%d\n", dice[0], dice[1], dice[2], dice[3], dice[4]);
}

void ones(int dice[5], int categories[13], int scores[13])
{
	int die_index = 0, sum = 0;
	if (categories[0] == 0)
	{
		categories[0] = 1;
		for (; die_index < 5; die_index++)
		{
			if (dice[die_index] == 1)
			{
				scores[0] = sum + 1;
			}
		}
	}
}

void twos(int dice[5], int categories[13], int scores[13])
{
	int die_index = 0, sum = 0;
	if (categories[1] == 0)
	{
		categories[1] = 1;
		for (; die_index < 5; die_index++)
		{
			if (dice[die_index] == 2)
			{
				scores[1] = sum + 2;
			}
		}
	}
}

void threes(int dice[5], int categories[13], int scores[13])
{
	int die_index = 0, sum = 0;
	if (categories[2] == 0)
	{
		categories[2] = 1;
		for (; die_index < 5; die_index++)
		{
			if (dice[die_index] == 3)
			{
				scores[2] = sum + 3;
			}
		}
	}
}

void fours(int dice[5], int categories[13], int scores[13])
{
	int die_index = 0, sum = 0;
	if (categories[3] == 0)
	{
		categories[3] = 1;
		for (; die_index < 5; die_index++)
		{
			if (dice[die_index] == 4)
			{
				scores[3] = sum + 4;
			}
		}
	}
}

void fives(int dice[5], int categories[13], int scores[13])
{
	int die_index = 0, sum = 0;
	if (categories[4] == 0)
	{
		categories[4] = 1;
		for (; die_index < 5; die_index++)
		{
			if (dice[die_index] == 5)
			{
				scores[4] = sum + 5;
			}
		}
	}
}

void sixes(int dice[5], int categories[13], int scores[13])
{
	int die_index = 0, sum = 0;
	if (categories[5] == 0)
	{
		categories[5] = 1;
		for (; die_index < 5; die_index++)
		{
			if (dice[die_index] == 6)
			{
				scores[5] = sum + 6;
			}
		}
	}
}

void three_of_a_kind(int dice[5], int categories[13], int scores[13])
{
	int dievalue = 1;
	if (categories[6] == 0)
	{
		for (; dievalue < 7; dievalue++)
		{
			int kind = 0;
			if (dice[0] == dievalue)
			{
				kind = kind + 1;
			}
			if (dice[1] == dievalue)
			{
				kind = kind + 1;
			}
			if (dice[2] == dievalue)
			{
				kind = kind + 1;
			}
			if (dice[3] == dievalue)
			{
				kind = kind + 1;
			}
			if (dice[4] == dievalue)
			{
				kind = kind + 1;
			}
			if (kind >= 3)
			{
				scores[6] = dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
				categories[6] = 1;
				break;
			}
			if (kind < 3 && categories[0] != 0 && categories[1] != 0 && categories[2] != 0 && categories[3] != 0 && categories[4] != 0 && categories[5] != 0)
			{
				scores[6] = 0;
				categories[6] = 1;
				break;
			}
		}
	}
}

void four_of_a_kind(int dice[5], int categories[13], int scores[13])
{
	int dievalue = 1;
	if (categories[7] == 0)
	{
		for (; dievalue < 7; dievalue++)
		{
			int kind = 0;
			if (dice[0] == dievalue)
			{
				kind = kind + 1;
			}
			if (dice[1] == dievalue)
			{
				kind = kind + 1;
			}
			if (dice[2] == dievalue)
			{
				kind = kind + 1;
			}
			if (dice[3] == dievalue)
			{
				kind = kind + 1;
			}
			if (dice[4] == dievalue)
			{
				kind = kind + 1;
			}
			if (kind >= 4)
			{
				scores[7] = dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
				categories[7] = 1;
				break;
			}
			if (kind < 4 && categories[0] != 0 && categories[1] != 0 && categories[2] != 0 && categories[3] != 0 && categories[4] != 0 && categories[5] != 0)
			{
				scores[7] = 0;
				categories[7] = 1;
				break;
			}
		}
	}
}

void full_house(int dice[5], int categories[13], int scores[13])
{
	int dievalue1 = 1, dievalue2 = 1;
	int kind1 = 0, kind2 = 0;

	if (categories[8] == 0)
	{
		for (; dievalue1 < 7; dievalue1++)
		{
			if (dice[0] == dievalue1)
			{
				kind1 = kind1 + 1;
			}
			if (dice[1] == dievalue1)
			{
				kind1 = kind1 + 1;
			}
			if (dice[2] == dievalue1)
			{
				kind1 = kind1 + 1;
			}
			if (dice[3] == dievalue1)
			{
				kind1 = kind1 + 1;
			}
			if (dice[4] == dievalue1)
			{
				kind1 = kind1 + 1;
			}

		}
		for (; dievalue2 < 7; dievalue2++)
		{
			if (dice[0] == dievalue2)
			{
				kind2 = kind2 + 1;
			}
			if (dice[1] == dievalue2)
			{
				kind2 = kind2 + 1;
			}
			if (dice[2] == dievalue2)
			{
				kind2 = kind2 + 1;
			}
			if (dice[3] == dievalue2)
			{
				kind2 = kind2 + 1;
			}
			if (dice[4] == dievalue2)
			{
				kind2 = kind2 + 1;
			}
			if (kind2 == 2 && kind1 == 3)
			{
				scores[8] = 25;
				categories[8] = 1;

			}
			if ((kind1 < 3 || kind2 < 2) && categories[0] != 0 && categories[1] != 0 && categories[2] != 0 && categories[3] != 0 && categories[4] != 0 && categories[5] != 0)
			{
				scores[6] = 0;
				categories[6] = 1;
			}
		}

	}
}

void small_straight(int dice[5], int categories[13], int scores[13])//uses selection_sort from SearchesSorts (In class example code)
{
	if (categories[9] == 0)
	{
		int temp = 0, passes = 0, index = 0, sum = 0;

		
		for (; passes < 4; ++passes) 
		{
			for (index = 0; index < 5 - passes - 1;
				++index)
			{
				
				if (dice[index] > dice[index + 1])
				{
					temp = dice[index];
					dice[index] = dice[index + 1];
					dice[index + 1] = temp;
				}
			}
		}
		for (index = 4; index > 0; index--)
		{
			if (dice[index] == (dice[index - 1] + 1))
			{
				sum++;
			}
		}
		if (sum >= 3)
		{
			scores[9] = 30;
			categories[9] = 1;
		}
		if (sum < 3 && categories[0] != 0 && categories[1] != 0 && categories[2] != 0 && categories[3] != 0 && categories[4] != 0 && categories[5] != 0)
		{
			scores[9] = 0;
			categories[9] = 1;
		}
	} 
	
}

void large_straight(int dice[5], int categories[13], int scores[13])
{
	if (categories[10] == 0)
	{	
		int temp = 0, passes = 0, index = 0, sum = 0;

		
		for (; passes < 4; ++passes)
		{
			for (index = 0; index < 5 - passes - 1;
				++index)
			{
			
				if (dice[index] > dice[index + 1])
				{
					temp = dice[index];
					dice[index] = dice[index + 1];
					dice[index + 1] = temp;
				}
			}
		}
		for (index = 4; index > 0; index--)
		{
			if (dice[index] == (dice[index - 1] + 1))
			{
				sum++;
			}
		}
		if (sum == 4)
		{
			scores[10] = 30;
			categories[10] = 1;
		}
		if (sum < 4 && categories[0] != 0 && categories[1] != 0 && categories[2] != 0 && categories[3] != 0 && categories[4] != 0 && categories[5] != 0)
		{
			scores[10] = 0;
			categories[10] = 1;
		}
	}

}

void chance(int dice[5], int categories[13], int scores[13])
{
	if (categories[11] == 0)
	{
		categories[11] = 1;
		scores[11] = dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
	}
}

void yahtzee(int dice[5], int categories[13], int scores[13])
{
	int dievalue = 1;
	
	for (; dievalue < 7; dievalue++)
	{
			int kind = 0;
			if (dice[0] == dievalue)
			{
				kind = kind + 1;
			}
			if (dice[1] == dievalue)
			{
				kind = kind + 1;
			}
			if (dice[2] == dievalue)
			{
				kind = kind + 1;
			}
			if (dice[3] == dievalue)
			{
				kind = kind + 1;
			}
			if (dice[4] == dievalue)
			{
				kind = kind + 1;
			}
			if (kind == 5 && categories[12] >= 1)
			{
				scores[12] = (scores[12] + 100);
			}
			if (kind == 5)
			{
				scores[12] = 50;
				categories[12] = 1;
			}
			if (kind < 5 && categories[0] != 0 && categories[1] != 0 && categories[2] != 0 && categories[3] != 0 && categories[4] != 0 && categories[5] != 0 && categories[12] == 0)
			{
				scores[12] = 0;
				categories[12] = 1;
			}
			
	}
	
}

void choose_category(int dice[5], int categories[13], int scores[13])
{
	int catgeory = 0;
	int choose_category = 0;
	while (choose_category < 1 || choose_category > 12)
	{
		printf("\nPlease choose scoring a category 1-13.\n");
		if (categories[0] == 0)
		{
			printf("\n1. ONES\n");
		}
		else
		{
			printf("\n\n1. *already used*\n");
		}
		if (categories[1] == 0)
		{
			printf("2. TWOS\n");
		}
		else
		{
			printf("2. *already used*\n");
		}
		if (categories[2] == 0)
		{
			printf("2. THREES\n");
		}
		else
		{
			printf("3. *already used*\n");
		}
		if (categories[3] == 0)
		{
			printf("4. FOURS\n");
		}
		else
		{
			printf("4. *already used*\n");
		}
		if (categories[4] == 0)
		{
			printf("5. FIVES\n");
		}
		else
		{
			printf("5. *already used*\n");
		}
		if (categories[5] == 0)
		{
			printf("6. SIXES\n");
		}
		else
		{
			printf("6. *already used*\n");
		}
		if (categories[6] == 0)
		{
			printf("7. THREE OF A KIND\n");
		}
		else
		{
			printf("7. *already used*\n");
		}
		if (categories[7] == 0)
		{
			printf("8. FOUR OF A KIND\n");
		}
		else
		{
			printf("8. *already used*\n");
		}
		if (categories[8] == 0)
		{
			printf("9. FULL HOUSE\n");
		}
		else
		{
			printf("9. *already used*\n");
		}
		if (categories[9] == 0)
		{
			printf("10. SMALL STRAIGHT\n");
		}
		else
		{
			printf("10. *already used*\n");
		}
		if (categories[10] == 0)
		{
			printf("11. LARGE STRAIGHT\n");
		}
		else
		{
			printf("11. *already used*\n");
		}
		if (categories[11] == 0)
		{
			printf("12. CHANCE\n");
		}
		else
		{
			printf("12. *already used*\n");
		}
		printf("13. YAHTZEE\n\n");

		scanf("%d", &choose_category);
	}
	switch (choose_category)
	{
	case 1:
		ones(dice, categories, scores);
		break;
	case 2:
		twos(dice, categories, scores);
		break;
	case 3:
		threes(dice, categories, scores);
		break;
	case 4:
		fours(dice, categories, scores);
		break;
	case 5:
		fives(dice, categories, scores);
		break;
	case 6:
		sixes(dice, categories, scores);
		break;
	case 7:
		three_of_a_kind(dice, categories, scores);
		break;
	case 8:
		four_of_a_kind(dice, categories, scores);
		break;
	case 9:
		full_house(dice, categories, scores);
		break;
	case 10:
		small_straight(dice, categories, scores);
		break;
	case 11:
		large_straight(dice, categories, scores);
		break;
	case 12:
		chance(dice, categories, scores);
		break;
	case 13:
		yahtzee(dice, categories, scores);
		break;
	}
}

int print_scorecard(int scores[13], int player)
{
	int upper_score = 0, upper_total = 0, bonus = 0, lower_total = 0;

	int grand_total = 0;

	upper_score = (scores[0] + scores[1] + scores[2] + scores[3] + scores[4] + scores[5]);

	if (upper_score >= 63)
	{
		bonus = 35;
	}

	upper_total = upper_score + bonus;

	lower_total = (scores[6] + scores[7] + scores[8] + scores[9] + scores[10] + scores[11] + scores[12]);

	grand_total = upper_total + lower_total;

	printf("\t\t\tPLAYER %d", player);

	printf("\tUPPER SECTION\n\n1. ONES:\t%d\n\n2. TWOS:\t%d\n\n3.THREES:\t%d\n\n4. FOURS:\t%d\n\n5. FIVES:\t%d\n\n6. SIXES:\t%d\n\nUPPER TOTAL:\t%d\n\nBONUS:\t%d\n\nTOTAL:\t%d\n\n", scores[0], scores[1], scores[2], scores[3], scores[4], scores[5], upper_score, bonus, upper_total);

	printf("\tLOWER SECTION\n\n7. THREE OF A KIND:\t%d\n\n8. FOUR OF A KIND:\t%d\n\n9. FULL HOUSE:\t%d\n\n10. SMALL STRAIGHT:\t%d\n\n11. LARGE STRAIGHT:\t%d\n\n12. CHANCE: %d\n\n13. YAHTZEE:\t%d\n\nLOWER TOTAL:\t%d\n\n", scores[6], scores[7], scores[8], scores[9], scores[10], scores[11], scores[12], lower_total);

	printf("\t\t\tGRAND TOTAL: %d\n\n", grand_total);

	return grand_total;
}

void determine_winner(int grand_total1, int grand_total2)
{
	printf("Player 1 final score: %d\n\nPlayer 2 final score: %d", grand_total1, grand_total2);

	if (grand_total1 > grand_total2)
	{
		printf("\n\nPlayer 1 wins!");
		printf("\n\n Press 1 to see the rules again, 2 to play again, or 3 to exit.");
	}
	if (grand_total2 > grand_total1)
	{
		printf("\n\n\nPlayer 2 wins!");
		printf("\n\n Press 1 to see the rules again, 2 to play again, or 3 to exit.");
	}
}




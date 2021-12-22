/*Programmer: Charles Marshall
*
  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 7: Five-Card-Draw Poker

  Date: 11-29-2021

  Description:  This file utilizes the functions defined in functions.c to do the following:

				Print the welcome/option screen;
				Print the rules of five card draw;
				Initialize an array containing a standard 52-card deck;
				Shuffle the deck array;
				Deal 5 cards to both the player and the dealer;
				Redeal cards selected by the player within their hand;
				Determine the frequency of each face and suit contained in a 5 card hand;
				Determine the rank of a given hand;
				Automate the evaluation of the dealer's hand to choose which, if any, cards to re-draw;
				Compare the rank of the players and the dealers hand to determine a winner(1 being the lowest, 10 the highest);
				Ask the player if they wish to play another hand, display the rules again, or exit the program.
  */
#include "functions.h"

void print_menu()
{
	printf("\t\t\t5-CARD-DRAW\n\n"
		"\t\t\tPlease make a selection 1-3:\n\n"
		"\t\t\t1. Display rules.\n\n"
		"\t\t\t2. Play Game.\n\n"
		"\t\t\t3. Exit program.\n\n");
}

int menu_selection()
{
	int option = 0;
	do
	{
		scanf("%d", &option);
	} while (option < 1 || option > 3);
	return option;
}

void print_rules()
{
	printf("RULES\n\n"
		"All players draw 5 cards from a shuffled standard 52-card deck.\n\n"
		"Each player may discard re-draw any number of the 5 cards in their deck once.\n\n"
		"A winner is determined by who has the highest ranking hand. The rankings are as follows:\n\n"
		"1. High card   2. Pair   3. Two Pairs   4. Three-Of-A-Kind   5. Straight\n\n"
		"6. Flush   7. Full House   8. Four-Of-A-Kind   9. Straight Flush   10. Royal Flush\n\n"
		"If both players have the same ranking hand, the player with the highest card wins.\n\n\n");
}



void shuffle(int wDeck[][13])
{
	int row = 0;
	int column = 0;
	int card = 0;

	for (card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		wDeck[row][column] = card;
	}
}

int deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], int topcard, Hand* player)
{
	int row = 0;   
	int column = 0; 
	int card = 0;  

	for (card = topcard + 1; card <= topcard + 5; card++)
	{
		for (row = 0; row <= 3; row++)
		{
			for (column = 0; column <= 12; column++)
			{
				if (wDeck[row][column] == card)
				{
					player->hand[card - topcard - 1].suit = row;
					player->hand[card - topcard - 1].face = column;
				}
			}
		}
	}

	int cardnumber = 0;
	while (cardnumber < 5)
	{
		printf("%d. %5s of %-8s\n\n", cardnumber + 1, wFace[player->hand[cardnumber].face], wSuit[player->hand[cardnumber].suit]);
		cardnumber++;
	}
	return card;
}

int redeal(const int wDeck[][13], const char* wFace[], const char* wSuit[], int topcard, Hand* player)
{
	int option = 0;
	printf("\n\nEnter 1 if you wish to exchange cards in your hand, or enter 2 to keep your current hand.\n\n");
	do
	{
		scanf("%d", &option);
	} while (option < 1 || option > 2);
	if (option == 1)
	{
		int i = 0;
		int selection = 1;
		printf("Enter the cards you wish to discard one at a time using the number to the left of each card.\nWhen you are done selecting cards, enter 0.\n\n");
		while (selection != 0 && selection < 6)
		{
			int row = 0, column = 0, card = 0;
			do
			{
				scanf("%d", &selection);
				if (selection < 0 || selection > 5) //validate selection
				{
					printf("\nInvalid selection. Please re-enter.\n");
				}
			} while (selection < 0 || selection > 5);

			if (selection > 0 && selection < 6)
			{
				i++;
				for (card = topcard + i; card <= topcard + i; card++)
				{
					for (row = 0; row <= 3; row++)
					{
						for (column = 0; column <= 12; column++)
						{
							if (wDeck[row][column] == card)
							{
								//change value of discarded card
								player->hand[selection - 1].suit = row;
								player->hand[selection - 1].face = column;
							}
						}
					}
				}
			}
		}
		
		printf("NEW HAND:\n\n");
		
		int cardnumber = 0;
		while (cardnumber < 5) //print new hand
		{
			printf("%d. %5s of %-8s\n\n", cardnumber + 1, wFace[player->hand[cardnumber].face], wSuit[player->hand[cardnumber].suit]);
			cardnumber++;
		}
		topcard = topcard + i; //sets top card in deck to new value based on amount of cards re-drawn.
		return topcard;
	}
	if (option == 2)
	{
		return topcard;
	}

}
void get_suits(Hand* player, int suits[])
{
	for (int i = 0; i < 5; i++)
	{
		for (int suit = 0; suit < 4; suit++)
		{
			if (player->hand[i].suit == suit)
			{
				suits[suit] += 1;
			}
		}
		
	}
	return;
}
void get_faces(Hand* player, int faces[])
{
	{
		for (int i = 0; i < 5; i++)
		{
			for (int face = 0; face < 13; face++)
			{
				if (player->hand[i].face == face)
				{
					faces[face] += 1;
				}
			}

		}
	}
	return;
}

void highcard(int faces1[], int faces2[], int* handrank1, int* handrank2, int* tiebreaker)
{
	int max1 = 0, max2 = 0;
	for (int i = 0; i < 13; i++)
	{
		if (faces1[i] > 0 && max1 != 13)
		{
			max1 = i;
		}
		if (faces1[0] > 0)
		{
			max1 = 13;
			break;
		}
	}
	
	for (int i = 0; i < 13; i++)
	{
		if (faces2[i] > 0 && max2 != 13)
		{
			max2 = i;
		}
		if (faces2[0] > 0)
		{
			max2 = 13;
			break;
		}
	}
	if (*handrank1 == *handrank2)
	{
		if (max1 > max2)
		{
			if (*handrank1 == 0 && *handrank2 == 0)
			{
				*handrank1 = 1;
				*handrank2 = 0;
			}
			*tiebreaker = 1;
		}
		if (max2 > max1)
		{
			if (*handrank1 == 0 && *handrank2 == 0)
			{
				*handrank1 = 0;
				*handrank2 = 1;
			}
			*tiebreaker = 0;
		}
	}
	return;
}

void pairs(int faces[], int* handrank)
{
	int check = 0;
	for(int i = 0; i < 13; i++)
	{
		if (faces[i] == 2)
		{
			check++;
			*handrank = 2;
		}
		if (check == 2)
		{
			*handrank = 3;
			break;
		}
	}
	return;
}

void three_of_a_kind(int faces[], int* handrank)
{
	for (int i = 0; i < 13; i++)
	{
		if (faces[i] == 3)
		{
			*handrank = 4;
			break;
		}
	}
	return;
}



void straight(int faces[], int* handrank)
{
	int sum = 0;
	for (int i = 0; i < 12; i++)
	{
		if (faces[i] == 1 && faces[i + 1] == 1)
		{
			sum++;
		}

	}
	if (faces[9] == 1 && faces[10] == 1 && faces[11] == 1 && faces[12] == 1 && faces[0] == 1)
	{
		sum += 1;
	}
	if (sum == 4)
	{
		*handrank = 5;
	}
	return;
}

void flush(int suits[], int* handrank)
{
	for (int i = 0; i < 4; i++)
	{
		if (suits[i] == 5)
		{
			*handrank = 6;
			break;
		}
	}
	return;
}

void full_house(int faces[], int* handrank)
{
	int pair = 0, triplet = 0;
	for (int i = 0; i < 13; i++)
	{
		if (faces[i] == 3)
		{
			triplet = 1;
		}
		if (faces[i] == 2)
		{
			pair = 1;
		}
	}
	if (triplet == 1 && pair == 1)
	{
		*handrank = 7;
	}
	return;
}

void four_of_a_kind(int faces[], int* handrank)
{
	for (int i = 0; i < 13; i++)
	{
		if (faces[i] == 4)
		{
			*handrank = 8;
			break;
		}
	}
	return;
}

void straight_flush(int faces[], int suits[], int* handrank)
{
	int flush = 0, straight = 0, royalflush = 0;
	for (int i = 0; i < 4; i++)
	{
		if (suits[i] == 5)
		{
			flush = 1;
		}
	}
	int sum = 0;
	for (int i = 0; i < 12; i++)
	{
		if (faces[i] == 1 && faces[i + 1] == 1)
		{
			sum++;
		}

	}
	if (faces[9] == 1 && faces[10] == 1 && faces[11] == 1 && faces[12] == 1 && faces[0] == 1)
	{
		royalflush = 1;
		sum += 1;
	}
	if (sum == 4)
	{
		straight = 1;
	}
	if (flush == 1 && straight == 1)
	{
		*handrank = 9;
	}
	if (flush == 1 && straight == 1 && royalflush == 1)
	{
		*handrank = 10;
	}

	return;
}

void cpu_redeal(const int wDeck[][13], const char* wFace[], const char* wSuit[], int faces[], int suits[], Hand* player, int topcard, int* handrank)
{
	if (*handrank >= 5) //keeps curent hand
	{
		return;
	}
	if (*handrank == 4) //If the hand contains a three of a kind, the two non-matching cards are re-drawn.
	{
		int b = 0;
		for (int i = 0; i < 13; i++)
		{
			if (faces[i] == 3)
			{
				for (int a = 0; a < 5; a++)
				{
					if (player->hand[a].face != i)
					{
						int row = 0, column = 0, card = 0;
						b++;
						for (card = topcard + b; card <= topcard + b; card++)
						{
							for (row = 0; row <= 3; row++)
							{
								for (column = 0; column <= 12; column++)
								{
									if (wDeck[row][column] == card)
									{
										player->hand[a].suit = row;
										player->hand[a].face = column;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (*handrank == 3) //If a hand contains two pairs, the non matching card is redrawn.
	{
		int b = 0;
		int pair1 = 0, pair2 = 0;
		for (int i = 0; i < 13; i++)
		{
			if (faces[i] == 2)
			{
				pair1 = i;
			}
			if (faces[i] == 2 && i != pair1)
			{
				pair2 = i;
			}

			for (int a = 0; a < 5; a++)
			{
					if (player->hand[a].face != pair1 && player->hand[a].face != pair2)
					{
						int row = 0, column = 0, card = 0;
						b++;
						for (card = topcard + b; card <= topcard + b; card++)
						{
							for (row = 0; row <= 3; row++)
							{
								for (column = 0; column <= 12; column++)
								{
									if (wDeck[row][column] == card)
									{
										player->hand[a].suit = row;
										player->hand[a].face = column;
									}
								}
							}
						}
					}
			}
			
		}
	}
	if (*handrank == 2) //If the hand contains a pair, the three non-matching cards are redrawn.
	{
		int b = 0;
		for (int i = 0; i < 13; i++)
		{
			if (faces[i] == 2)
			{
				for (int a = 0; a < 5; a++)
				{
					if (player->hand[a].face != i)
					{
						int row = 0, column = 0, card = 0;
						b++;
						for (card = topcard + b; card <= topcard + b; card++)
						{
							for (row = 0; row <= 3; row++)
							{
								for (column = 0; column <= 12; column++)
								{
									if (wDeck[row][column] == card)
									{
										player->hand[a].suit = row;
										player->hand[a].face = column;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (*handrank < 2) //Redraws all cards in the hand.
	{
		int b = 0;
		for (int i = 0; i < 13; i++)
		{
				for (int a = 0; a < 5; a++)
				{
					if (player->hand[a].face != i)
					{
						int row = 0, column = 0, card = 0;
						b++;
						for (card = topcard + b; card <= topcard + b; card++)
						{
							for (row = 0; row <= 3; row++)
							{
								for (column = 0; column <= 12; column++)
								{
									if (wDeck[row][column] == card)
									{
										player->hand[a].suit = row;
										player->hand[a].face = column;
									}
								}
							}
						}
					}
				}

		}
	}
	return;
}

void show_dealer_hand(const char* wFace[], const char* wSuit[], Hand* player)
{
	int cardnumber = 0;
	while (cardnumber < 5)
	{
		printf("%d. %5s of %-8s\n\n", cardnumber + 1, wFace[player->hand[cardnumber].face], wSuit[player->hand[cardnumber].suit]);
		cardnumber++;
	}
	return;
}

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
				Automate the evaluation of the dealer's hand to choose which, if any, cards to re-draw;
				Compare the rank of the players and the dealers hand to determine a winner(1 being the lowest, 10 the highest);
				Ask the player if they wish to play another hand, display the rules again, or exit the program.				
  */

#include "functions.h"

int main(void)
{
	//The commented out code below contains a test hand that can be manually changed to more easily evaluate the hand ranking functions.

	/*
	Hand test;
	test.hand[0].suit = 1;
	test.hand[1].suit = 2;
	test.hand[2].suit = 3;
	test.hand[3].suit = 2;
	test.hand[4].suit = 1;

	test.hand[0].face = 1;
	test.hand[1].face = 1;
	test.hand[2].face = 2;
	test.hand[3].face = 2;
	test.hand[4].face = 5;

	int faces3[13] = { 0 };
	int suits3[4] = { 0 };
	int handrank3 = 0;

	get_suits(&test, suits3);
	get_faces(&test, faces3);

	pairs(faces3, &handrank3);
	three_of_a_kind(faces3, &handrank3);
	straight(faces3, &handrank3);
	flush(suits3, &handrank3);
	full_house(faces3, &handrank3);
	four_of_a_kind(faces3, &handrank3);
	straight_flush(faces3, suits3, &handrank3);

	printf("\n%d\n", handrank3);

	return 0;
	*/
	
	
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	srand((unsigned)time(NULL)); 

	int option = 0;

	print_menu();

	option = menu_selection();
	while (option != 3)
	{
		if (option == 1)
		{
			print_rules();
			printf("Enter 1 to display the rules again, 2 to play, or 3 to exit the program.\n");
			option = menu_selection();
		}
		if (option == 2)
		{
			Hand dealer;
			Hand player;

			//The four arrays below index the frequency of each face and suit within a hand of 5 cards using get_suits() and get_faces(). (e.g. If all 5 cards are hearts, faces[0] = 5.)
			int faces1[13] = { 0 };
			int suits1[4] = { 0 };
			int faces2[13] = { 0 };
			int suits2[4] = { 0 };

			int deck[4][13] = { 0 };
			shuffle(deck);

			int topcard = 0; //used to keep track of the top card in the deck after each deal/redeal.
			int handrank1 = 0, handrank2 = 0;
			int tiebreaker = 2; //tiebreaker is used if both hands have the same rank.

			topcard = deal(deck, face, suit, topcard, &dealer);
			system("cls");
			printf("PLAYER'S HAND:\n\n");
			topcard = deal(deck, face, suit, topcard, &player);
			topcard = redeal(deck, face, suit, topcard, &player);

			//The code commented out directly below can be used to show the dealers hand before and after the cpu_redeal() function evaluates the dealers hand and selects which cards to re-draw.

			//printf("\nDEALER'S HAND:\n\n");
			//show_dealer_hand(face, suit, &dealer);

			get_suits(&player, suits1);
			get_faces(&player, faces1);

			pairs(faces1, &handrank1);
			three_of_a_kind(faces1, &handrank1);
			straight(faces1, &handrank1);
			flush(suits1, &handrank1);
			full_house(faces1, &handrank1);
			four_of_a_kind(faces1, &handrank1);
			straight_flush(faces1, suits1, &handrank1);


			get_suits(&dealer, suits2);
			get_faces(&dealer, faces2);

			pairs(faces2, &handrank2);
			three_of_a_kind(faces2, &handrank2);
			straight(faces2, &handrank2);
			flush(suits2, &handrank2);
			full_house(faces2, &handrank2);
			four_of_a_kind(faces2, &handrank2);
			straight_flush(faces2, suits2, &handrank2);

			
			cpu_redeal(deck, face, suit, faces2, suits2, &dealer, topcard, &handrank2);
			
			for (int i = 0; i < 13; i++) //for-loops used to reset face/suits frequency arrays after redeal
			{
				faces2[i] = 0;
			}
			for (int i = 0; i < 4; i++)
			{
				suits2[i] = 0;
			}

			get_suits(&dealer, suits2);
			get_faces(&dealer, faces2);

			pairs(faces2, &handrank2);
			three_of_a_kind(faces2, &handrank2);
			straight(faces2, &handrank2);
			flush(suits2, &handrank2);
			full_house(faces2, &handrank2);
			four_of_a_kind(faces2, &handrank2);
			straight_flush(faces2, suits2, &handrank2);


			highcard(faces1, faces2, &handrank1, &handrank2, &tiebreaker);

			printf("\nDEALER'S HAND:\n\n");
			show_dealer_hand(face, suit, &dealer);

			printf("Player's hand rank: %d\n", handrank1);
			printf("Dealer's hand rank: %d\n", handrank2);
			system("pause");

			if (handrank1 > handrank2)
			{
				printf("\nYou Win!\n\n");
			}
			if (handrank1 < handrank2)
			{
				printf("\nThe House Wins!\n\n");
			}
			if (handrank1 == handrank2)
			{
				if (tiebreaker == 1)
				{
					printf("\nYou Win!\n\n");
				}
				if (tiebreaker == 0)
				{
					printf("\nThe House Wins!\n\n");
				}
				if(tiebreaker == 2)
				{
					printf("\nIt's a Tie!\n\n");
				}
			}
			printf("Enter 1 to display the rules again, 2 to play another hand, or 3 to exit the program.\n");
			option = menu_selection();
			system("cls");
		}	
	}
	return 0;
}


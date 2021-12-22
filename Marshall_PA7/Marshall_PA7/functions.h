/*Programmer: Charles Marshall
*
  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 7: Five-Card-Draw Poker

  Date: 11-29-2021

  Description:  This file contains the headers and descriptions of the functions used to do the following:

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
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct card
{
	int face;
	int suit;
}Card;

typedef struct hand
{
	Card hand[5];
}Hand;

/***********************************************************************************************
  * Function:              print_menu()                                                          *
  * Description:		   Displays an option menu.                                              *
  * Input parameters:      none                                                                  *
  * Returns:               none                                                                  *
  * Preconditions:         none                                                                  *
  * Postconditions:        none                                                                  *
  ***********************************************************************************************/
void print_menu();

/***********************************************************************************************
  * Function:              welcome_screen ()                                                     *
  * Description:		   Displays a welcome screen.                                            *
  * Input parameters:      Integer from User input                                               *
  * Returns:               Integer 1-3.                                                          *
  * Preconditions:         none                                                                  *
  * Postconditions:        none                                                                  *
  ***********************************************************************************************/
int menu_selection();

/***********************************************************************************************
  * Function:              print_rules()                                                         *
  * Description:		   Displays the rules of five-card-draw poker.                           *
  * Input parameters:      none                                                                  *
  * Returns:               none                                                                  *
  * Preconditions:         none                                                                  *
  * Postconditions:        none                                                                  *
  ***********************************************************************************************/
void print_rules();

/***********************************************************************************************
  * Function:              shuffle()                                                             *
  * Description:		   randomly places each integer 1-52 within a 4 x 13 2D array.           *
  * Input parameters:      a 4 x 13 2D array (deck)                                              *
  * Returns:               A shuffled "deck" of cards                                            *
  * Preconditions:         Array must be declared prior.                                         *
  * Postconditions:        Each integer 1-52 will be randomly placed within the array.           *
  ***********************************************************************************************/
void shuffle(int wDeck[][13]);

/***********************************************************************************************************************************
  * Function:              deal()                                                                                                  *
  * Description:		   Deals 5 cards from the shuffled deck of cards.                                                          *
  * Input parameters:      shuffled deck array, face name array, suit name array, the top card in the deck, and destination hand.  *
  * Returns:               Sets the value of the 5 cards in the destination hand.                                                  *
  * Preconditions:         Deck must be shuffled.                                                                                  *
  * Postconditions:        The 5 cards in the destination hand will be set to the 5 cards drawn.                                   *
  **********************************************************************************************************************************/
int deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], int topcard, Hand* player);

/***********************************************************************************************************************************
  * Function:              redeal()                                                                                                *
  * Description:		   redeals the cards selected by the player.                                                               *
  * Input parameters:      shuffled deck array, face name array, suit name array, the top card in the deck, and destination hand.  *
  * Returns:               Sets the value of the 5 cards in the destination hand.                                                  *
  * Preconditions:         Deck must be shuffled.                                                                                  *
  * Postconditions:        The cards selected for discard will be re-dealt.                                                        *
  **********************************************************************************************************************************/
int redeal(const int wDeck[][13], const char* wFace[], const char* wSuit[], int topcard, Hand* player);

/***********************************************************************************************************************************
  * Function:              get_suits()                                                                                             *
  * Description:		   Determines the frequency of each suit type in a players hand.                                           *
  * Input parameters:      Player hand, suit frequency array.                                                                      *
  * Returns:               Frequency of each suit in the players hand stored in a 4-element array.                                 *
  * Preconditions:         The hand must have all five cards set.                                                                  *
  * Postconditions:        The frequency array is used to determine the hand's rank in following functions.                        *
  **********************************************************************************************************************************/
void get_suits(Hand* player, int suits[]);

/***********************************************************************************************************************************
  * Function:              get_faces()                                                                                             *
  * Description:		   Determines the frequency of each face type in a players hand.                                           *
  * Input parameters:      Player hand, face frequency array.                                                                      *
  * Returns:               Frequency of each face in the players hand stored in a 13-element array.                                *
  * Preconditions:         The hand must have all five cards set.                                                                  *
  * Postconditions:        The frequency array is used to determine the hand's rank in following functions.                        *
  **********************************************************************************************************************************/
void get_faces(Hand* player, int faces[]);

/***********************************************************************************************************************************
  * Function:              highcard()                                                                                              *
  * Description:		   Determines which player has the highest card in their hand.                                             *
  * Input parameters:      Player hand, rank, and face frequency array for both players.                                           *
  * Returns:               If both hands are rank 0, the hand with the highest card is given rank 1.                               *
  * Preconditions:         Both hands must have a set face frequency array.                                                        *
  * Postconditions:        if both hands have rank 0 or equal rank, this function determines the winner.                           *
  **********************************************************************************************************************************/
void highcard(int faces1[], int faces2[], int* handrank1, int* handrank2, int* tiebreaker);

/***********************************************************************************************************************************
  * Function:              pairs()                                                                                                  *
  * Description:		   Determines if a player has a pair in their hand.                                                         *
  * Input parameters:      Player hand, rank, face frequency array.                                                                 *
  * Returns:               If the hand contains a pair, the hand rank is set to 2. if it contains two pairs, hand rank is set to 3. *
  * Preconditions:         hand must have a set face frequency array.                                                               *
  * Postconditions:        The hand rank is used to determine a winner.                                                             *
  **********************************************************************************************************************************/
void pairs(int faces[], int* handrank);

/***********************************************************************************************************************************
  * Function:              three_of_a_kind()                                                                                       *
  * Description:		   Determines if a player has three cards of the same face in their hand.                                  *
  * Input parameters:      Player hand, rank, face frequency array.                                                                *
  * Returns:               If the hand contains a three-of-a-kind, the hand rank is set to 4.                                      *
  * Preconditions:         hand must have a set face frequency array.                                                              *
  * Postconditions:        The hand rank is used to determine a winner.                                                            *
  **********************************************************************************************************************************/
void three_of_a_kind(int faces[], int* handrank);

/***********************************************************************************************************************************
  * Function:              straight()                                                                                              *
  * Description:		   Determines if a player has 5 cards of consecutive face values in their hand.                            *
  * Input parameters:      Player hand, rank, face frequency array.                                                                *
  * Returns:               If the hand contains a straight, the hand rank is set to 5.                                             *
  * Preconditions:         hand must have a set face frequency array.                                                              *
  * Postconditions:        The hand rank is used to determine a winner.                                                            *
  **********************************************************************************************************************************/
void straight(int faces[], int* handrank);

/***********************************************************************************************************************************
  * Function:              flush()                                                                                                 *
  * Description:		   Determines if a player has 5 cards of the same suit in their hand.                                      *
  * Input parameters:      Player hand, rank, suit frequency array.                                                                *
  * Returns:               If the hand contains a flush, the hand rank is set to 6.                                                 *
  * Preconditions:         hand must have a set suit frequency array.                                                              *
  * Postconditions:        The hand rank is used to determine a winner.                                                            *
  **********************************************************************************************************************************/
void flush(int suits[], int* handrank);

/***********************************************************************************************************************************
  * Function:              full_house()                                                                                            *
  * Description:		   Determines if a player has a full house their hand.                                                     *
  * Input parameters:      Player hand, rank, face frequency array.                                                                *
  * Returns:               If the hand contains a full house, the hand rank is set to 7.                                           *
  * Preconditions:         hand must have a set face frequency array.                                                              *
  * Postconditions:        The hand rank is used to determine a winner.                                                            *
  **********************************************************************************************************************************/
void full_house(int faces[], int* handrank);

/***********************************************************************************************************************************
  * Function:              four_of_a_kind()                                                                                       *
  * Description:		   Determines if a player has three cards of the same face in their hand.                                  *
  * Input parameters:      Player hand, rank, face frequency array.                                                                *
  * Returns:               If the hand contains a three-of-a-kind, the hand rank is set to 4.                                      *
  * Preconditions:         hand must have a set face frequency array.                                                              *
  * Postconditions:        The hand rank is used to determine a winner.                                                            *
  **********************************************************************************************************************************/
void four_of_a_kind(int faces[], int* handrank);

/***********************************************************************************************************************************************************************
  * Function:              straight_flush()                                                                                                                            *
  * Description:		   Determines if a player has 5 cards of the same suit of consecutive face value in their hand. Also determines if a royal flush is present.   *
  * Input parameters:      Player hand, rank, suit and face frequency arrays.                                                                                          *
  * Returns:               If the hand contains a straight flush, the hand rank is set to 9, or 10 for a royal flush.                                                  *
  * Preconditions:         hand must have set suit and face frequency arrays.                                                                                          *
  * Postconditions:        The hand rank is used to determine a winner.                                                                                                *
  **********************************************************************************************************************************************************************/
void straight_flush(int faces[], int suits[], int* handrank);

/***********************************************************************************************************************************************************************
  * Function:              cpu_redeal()                                                                                                                                *
  * Description:		   Determines which, if any, cards to re-draw from the dealers hand based on the hand's rank.                                                  *
  * Input parameters:      Player hand, rank, deck, top card in deck, suit and face frequency arrays and name arrays.                                                  *
  * Returns:               redraws selected cards based on whether they contribute to the hand's rank.                                                                 *
  * Preconditions:         hand must be evaluated by hand ranking functions prior to using this function.                                                              *
  * Postconditions:        hand must be evaluated by hand ranking functions after using this function.                                                                 *
  **********************************************************************************************************************************************************************/
void cpu_redeal(const int wDeck[][13], const char* wFace[], const char* wSuit[], int faces[], int suits[], Hand* player, int topcard, int* handrank);

/***********************************************************************************************
  * Function:              show_dealer_hand()                                                   *
  * Description:		   Displays the dealers hand at the end of each round.                  *
  * Input parameters:      Dealer hand, face frequency arrays and name arrays.                  *
  * Returns:               none                                                                 *
  * Preconditions:         Dealer must have a set hand.                                         *
  * Postconditions:        none                                                                 *
  ***********************************************************************************************/
void show_dealer_hand(const char* wFace[], const char* wSuit[], Hand* player);
/*Programmer: Charles Marshall
*
  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 6: Battleship

  Date: 11-12-2021

  Description:  This file contains the headers and descriptions of the functions used to:

				Print the welcome screen;
				Initialize the game boards;
				Print the game boards;
				Choose to manually or randomly place ships;
				Randomly choose who takes the first turn;
				Accept a user input for a shot;
				Use basic AI in the computer's decision where to take a shot;
				Check if a player's ships are sunk;
				And verify if a player has won.

  */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10


typedef struct stats
{
	int hits;
	int misses;
	double shots;
	double h_m_ratio;
	char win_lose;
}Stats;


/***********************************************************************************************
  * Function:              welcome_screen ()                                                     *
  * Date Created:          11/6/2021                                                             *
  * Date Last Modified:    11/6/2021                                                             *
  * Description:		   Displays a welcome screen.                                            *
  * Input parameters:      none                                                                  *
  * Returns:               none                                                                  *
  * Preconditions:         none                                                                  *
  * Postconditions:        none                                                                  *
  ***********************************************************************************************/
void welcome_screen(void);

/***********************************************************************************************
  * Function:              init_board ()                                                         *
  * Date Created:          11/6/2021                                                             *
  * Date Last Modified:    11/6/2021                                                             *
  * Description:		   Initializes a 2-D, 10X10 battleship board.                            *
  * Input parameters:      Array definition, # of rows, and # of columns.                        *
  * Returns:               A populated 10X10 array.                                              *
  * Preconditions:         none                                                                  *
  * Postconditions:        none                                                                  *
  ***********************************************************************************************/
void init_board(char board[][MAX_COLS], int num_rows,
	int num_cols);

/*************************************************************************************************
  * Function:              print_board ()                                                        *
  * Date Created:          11/6/2021                                                             *
  * Date Last Modified:    11/6/2021                                                             *
  * Description:		   Displays a welcome screen.                                            *
  * Input parameters:      Array definition, # of rows, and # of columns.                        *
  * Returns:               A populated 10X10 array with numbered rows and columns.               *
  * Preconditions:         none                                                                  *
  * Postconditions:        none                                                                  *
  ***********************************************************************************************/
void print_board(char board[][MAX_COLS], int num_rows,
	int num_cols);

/********************************************************************************************************************
  * Function:              choose_placement ()                                                                      *
  * Date Created:          11/6/2021                                                                                *
  * Date Last Modified:    11/6/2021                                                                                *
  * Description:		   Allows the user to choose to randomly or manually place their ships on their game board. *
  * Input parameters:      User inputs an integer (1 or 2).                                                         *
  * Returns:               Returns the integer 1 or 2.                                                              *
  * Preconditions:         none                                                                                     *
  * Postconditions:        If 1 is selected, the player's ships are randomly placed, or manually if 2 is selected.  *
  *******************************************************************************************************************/
int choose_placement(void);

/****************************************************************************************************************
  * Function:              manual_placement ()                                                                  *
  * Date Created:          11/6/2021                                                                            *
  * Date Last Modified:    11/7/2021                                                                            *
  * Description:		   Utilizes user input to allow the manual placement of ships.                          *
  * Input parameters:      Array definition, ship length, ship symbol, and ship name.                           *
  * Returns:               Populates the users game board with the 5 types of ships.                            *
  * Preconditions:         choose_placement must return a value of 2 for this function to be initialized.       *
  * Postconditions:        One ship will be placed on the users game board each time this function is called.   *
  ***************************************************************************************************************/
void manual_placement(char board[][MAX_COLS], int ship_length, char ch, char ship_name[20]);

/**********************************************************************************************************************************************************************************************************
  * Function:              random_placement ()                                                                                                                                                            *
  * Date Created:          11/6/2021                                                                                                                                                                      *
  * Date Last Modified:    11/7/2021                                                                                                                                                                      *
  * Description:		   Traverses the game board array to allow the random placement of ships.                                                                                                         *
  * Input parameters:      Array definition, ship length, ship symbol, and ship name.                                                                                                                     *
  * Returns:               Populates the users game board with the 5 types of ships.                                                                                                                      *
  * Preconditions:         choose_placement must return a value of 1 for this function to be initialized by the user. This function is automatically used to place the ships of the computer(Player2).    *                                                                  *
  * Postconditions:        One ship will be placed on the users game board each time this function is called.                                                                                             *
  *********************************************************************************************************************************************************************************************************/
void random_placement(char board[][MAX_COLS], int ship_length, char ch);

/*********************************************************************************************************
  * Function:              first_move ()                                                                 *
  * Date Created:          11/7/2021                                                                     *
  * Date Last Modified:    11/7/2021                                                                     *
  * Description:		   Randomly chooses which player will take the first turn.                       *
  * Input parameters:      none                                                                          *
  * Returns:               0 or 1                                                                        *
  * Preconditions:         none                                                                          *
  * Postconditions:        If 0 is returned, player 2 goes first. If 1 is returned, player 1 goes first. *
  ********************************************************************************************************/
int first_move();
/************************************************************************************************
  * Function:              print_opponent_board ()                                              *
  * Date Created:          11/7/2021                                                            *
  * Date Last Modified:    11/7/2021                                                            *
  * Description:		   Prints a game board displaying the shots taken by a player.          *
  * Input parameters:      Array definition, # of rows, and # of columns.                       *
  * Returns:               none                                                                 *
  * Preconditions:         none                                                                 *
  * Postconditions:        none                                                                 *
  ***********************************************************************************************/
void print_opponent_board(char hit_board[][MAX_COLS], int num_rows,
	int num_cols);
/******************************************************************************************************************************************
  * Function:              take_shot ()                                                                                                   *
  * Date Created:          11/7/2021                                                                                                      *
  * Date Last Modified:    11/7/2021                                                                                                      *
  * Description:		   Takes user-entered coordinates and determines if the shot was a hit or miss.                                   *
  * Input parameters:      output file, player hits, player misses, opponent game board, user hit board, and player name.                 *
  * Returns:               Changes the value of the coordinate(cell) of the users hit board to either 'X' for a hit, or 'M' for a miss.   *
  * Preconditions:         The selected coordinate(cell) must not already contain 'X' or 'M'.                                             *
  * Postconditions:        The selected coordinate will either contain an 'X' or 'W'.                                                     *
  *****************************************************************************************************************************************/
void take_shot(FILE* outfile, int* p1_hits, int* p1_misses, char board[][MAX_COLS], char hit_board[][MAX_COLS], char player[20]);
/**********************************************************************************************************************************************************************************************************
  * Function:              cpu_shot ()                                                                                                                                                                    *
  * Date Created:          11/8/2021                                                                                                                                                                      *
  * Date Last Modified:    11/12/2021                                                                                                                                                                     *
  * Description:		   Uses basic AI to allow the computer(player2) to take an educated guess when taking a shot.                                                                                     *
								-If none of the hit board cells contains an 'X' the function randomly chooses a cell between (0,0) and (9,9).                                                             *
								-If a cell contains an 'X', and at least one of the cells adjacent to the 'X' are open, a cell above, below, left, or right of the cell is randomly chosen for the shot.  *
  * Input parameters:      output file, player hits, player misses, opponent game board, user hit board, and player name.                                                                                 *
  * Returns:               Changes the value of the coordinate(cell) of the users hit board to either 'X' for a hit, or 'M' for a miss.                                                                   *
  * Preconditions:         The selected coordinate(cell) must not already contain 'X' or 'M'.                                                                                                             *
  * Postconditions:        The selected coordinate will either contain an 'X' or 'W'.                                                                                                                     *
  *********************************************************************************************************************************************************************************************************/
void cpu_shot(FILE* outfile, int* cpu_hits, int* cpu_misses, char board[][MAX_COLS], char hit_board[][MAX_COLS], int num_rows,
	int num_cols, char player[20]);

/***************************************************************************************************************************************
  * Function:              check_if_sunk ()                                                                                            *
  * Date Created:          11/8/2021                                                                                                   *
  * Date Last Modified:    11/12/2021                                                                                                  *
  * Description:		   Uses the players hit board and the opponents game board to determine if a ship has been sunk.               *
  * Input parameters:      output file, opponent game board, user hit board, player name, and an integer for each ship type.           *
  * Returns:               If a ship has been sunk, a message is printed to the terminal and written to the output file stating such.  *
  * Preconditions:         none                                                                                                        *
  * Postconditions:        Once a ship has been sunk, the message stating such will only be displayed/written once for each ship.      *
  **************************************************************************************************************************************/
void check_if_sunk(FILE* outfile, char board[][MAX_COLS], char hit_board[][MAX_COLS], int* ships_sunk, int num_rows, int num_cols, char player[20], int* a, int* b, int* c, int* s, int* d);

/*************************************************************************************************************************
  * Function:              verify_winner ()                                                                              *
  * Date Created:          11/8/2021                                                                                     *
  * Date Last Modified:    11/10/2021                                                                                    *
  * Description:		   Uses the players hit board and the opponents game board to determine if a ship has been sunk. *
  * Input parameters:      Player game board, number of rows and columns in the game board.                              *
  * Returns:               Returns an integer equal to the amount of hits made by a player.                              *
  * Preconditions:         none                                                                                          *
  * Postconditions:        Once the amount of hits equals 17 (All ships sunk), the game ends.                            *
  ***********************************************************************************************************************/
int verify_winner(char board[][MAX_COLS], int num_rows,
	int num_cols);

#endif
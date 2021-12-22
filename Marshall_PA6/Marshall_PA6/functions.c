/*Programmer: Charles Marshall
*
  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 6: Battleship

  Date: 11-12-2021

  Description:  This file contains the functions used to:

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
#include "functions.h"

void welcome_screen()
{
	printf("\t\t\tWelcome to Battleship!\n\n"
		"Game Rules:\n\n"
		"1. \tThis is a two player game.\n\n"
		"2. \tPlayer1 is you and Player2 is the computer.\n\n"
		"3. \tEach player is given a 10 by 10 space grid on which to place 5 ships,a carrier(Denoted A, 5 spaces long),\n\tbattleship(B, 4), cruiser(C, 3), submarine(S, 3), and a destroyer(D, 2).\n\n"
		"4. \tYou may opt to have your ships placed manually, or have them automatically placed at random.\n\n"
		"5. \tWhen it is your turn, select a coordinate on the opponents grid to fire at. The computer will respond with\n\t'hit' or 'miss', and will display a 'X' for a hit or 'M' for a miss on the grid.\n\n"
		"6. \tOnce all of the spaces a ship occupies have been hit, that ship has been sunk.\n\tThe first player to sink all of their opponents ships wins!\n\n");
	system("pause");
	system("cls");
}

void init_board(char board[][MAX_COLS], int num_rows,
	int num_cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}
}

void print_board(char board[][MAX_COLS], int num_rows,
	int num_cols)
{
	int row_index = 0, col_index = 0;

	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for (; row_index < num_rows; ++row_index)
	{
		printf("%d ", row_index);
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			printf("%c ", board[row_index][col_index]);
		}
		putchar('\n');
	}

}



int choose_placement(void)
{
	int value = 0;
	printf("\n\nPlayer 1: Enter 1 to have your ships randomly placed, or press 2 to manually place your ships.");
		do
		{
			scanf("%d", &value);
		} while (value < 1 || value>2);
		return value;
}

void manual_placement(char board[][MAX_COLS], int ship_length, char ch, char ship_name[20])
{
	int row_index = 0, col_index = 0, sum = 0;
	//int row_check = 0, col_check = 0;
	printf("\n\nEnter the %d coordinates where you would like to place your %s. (Column, then row):\t", ship_length, ship_name);
	
		while (sum < ship_length)
		{
			sum++;
			scanf("%d%d", &col_index, &row_index);
			//scanf("%d", &col_index);
			//putchar(' ');
			if (board[row_index][col_index] != '~')
			{
				printf("\n\nThis coordinate is already occupied. Please re-enter the ship coordinates.");
				sum -=1;
			}
			if (row_index < 0 || row_index >9 || col_index < 0 || row_index >9)
			{
				printf("\n\nThe entered coordinate is out of bounds. Please re-enter the ship coordinates.");
				sum -= 1;
			}
			if (board[row_index][col_index] == '~')
			{
				board[row_index][col_index] = ch;
			}
			
		}
		printf("\n\nYour %s has been placed.\n\n", ship_name);


}


void random_placement(char board[][MAX_COLS], int ship_length, char ch)
{

	int index = 0, row_index = 0, col_index = 0, sum = 0;
	int index_test = 0, row_index_test = 0, col_index_test = 0;

		int direction = rand() % 2;
		if (direction == 0)//horizontal
		{
			row_index = rand() % 10;
			col_index = rand() % (10 - ship_length);
			col_index_test = col_index;
			while (sum < ship_length)
			{
				while (index_test < ship_length)
				{
					if (board[row_index][col_index_test] == '~')
					{
						sum++;
					}
					index_test++;
					col_index_test++;
				}
				if (sum == ship_length)
				{
					while (index < ship_length)
					{	
						board[row_index][col_index] = ch;
						index++;
						col_index++;
					}
				}
				if (sum != ship_length)
				{
					sum = 0;
					index_test = 0;
					row_index = rand() % 10;
					col_index = rand() % (10 - ship_length);
					col_index_test = col_index;
				}
			}
		}
		if (direction == 1)//vertical
		{
			{
				row_index = rand() % (10 - ship_length);
				col_index = rand() % 10;
				row_index_test = row_index;
				while (sum < ship_length)
				{
					while (index_test < ship_length)
					{
						if (board[row_index_test][col_index] == '~')
						{
							sum++;
						}
						index_test++;
						row_index_test++;
					}
					if (sum == ship_length)
					{
						while (index < ship_length)
						{
							board[row_index][col_index] = ch;
							index++;
							row_index++;
						}
					}
					if (sum != ship_length)
					{
						sum = 0;
						index_test = 0;
						row_index = rand() % (10 - ship_length);
						col_index = rand() % 10;
						row_index_test = row_index;
					}
				}
			}
		}

}



int first_move(void)
{
	int num = rand() % 2;
	if (num == 0)
	{
		return 0;
	}
	if (num == 1)
	{
		return 1;
	}
}

void print_opponent_board(char hit_board[][MAX_COLS], int num_rows,
	int num_cols)
{
	int row_index = 0, col_index = 0;

	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for (; row_index < num_rows; ++row_index)
	{
		printf("%d ", row_index);
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			printf("%c ", hit_board[row_index][col_index]);
		}
		putchar('\n');
	}

}

void take_shot(FILE* outfile, int* p1_hits, int* p1_misses, char board[][MAX_COLS], char hit_board[][MAX_COLS], char player[20])
{
	int row_index = 0, col_index = 0;
	printf("\n\nEnter the coordinates of where you wish to fire(row, then column):");
	do
	{
		scanf("%d%d", &row_index, &col_index);
		if (hit_board[row_index][col_index] == 'M' || hit_board[row_index][col_index] == 'X' || row_index < 0 || col_index < 0 || row_index > 9 || col_index > 9)
		{
			printf("\n\nThe coordinate you have selected is invalid or has already been chosen. Please re-enter a coordinate.");
		}
	} while (hit_board[row_index][col_index] == 'M' || hit_board[row_index][col_index] == 'X' || row_index < 0 || col_index < 0 || row_index > 9 || col_index > 9);

	if (board[row_index][col_index] == '~')
	{	
		system("cls");
		hit_board[row_index][col_index] = 'M';
		printf("\n\n%s Miss! (%d,%d)\n\n", player, row_index, col_index);
		*p1_misses += 1;
		fprintf(outfile, "Player 1 (%d,%d): Miss\n", row_index, col_index);
	}
	if (board[row_index][col_index] != '~' && hit_board[row_index][col_index] != 'M' && hit_board[row_index][col_index] != 'X')
	{
		system("cls");
		hit_board[row_index][col_index] = 'X';
		printf("\n\n%s Hit! (%d,%d)\n\n", player, row_index, col_index);
		*p1_hits += 1;
		fprintf(outfile, "Player 1 (%d,%d): Hit\n", row_index, col_index);
	}
}

void cpu_shot(FILE* outfile, int* cpu_hits, int* cpu_misses, char board[][MAX_COLS], char hit_board[][MAX_COLS],  int num_rows,
	int num_cols, char player[20])
{
	int row_index = 0, col_index = 0, sum = 0, hitcheck = 0;
	int updown = 0, leftright = 0;


	for (; row_index < num_rows; ++row_index)
	{

		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			if (hit_board[row_index][col_index] == 'X')
			{
				sum++;
			}
		}
	}
	if (sum > 0)
	{
		do
		{
			hitcheck = 0;
			col_index = rand() % 8 + 1;
			row_index = rand() % 8 + 1;
			if (hit_board[row_index][col_index] == 'X' && hit_board[row_index + 1][col_index] != '~')
			{
				hitcheck++;
			}
			if (hit_board[row_index][col_index] == 'X' && hit_board[row_index - 1][col_index] != '~')
			{
				hitcheck++;
			}
			if (hit_board[row_index][col_index] == 'X' && hit_board[row_index][col_index +1] != '~')
			{
				hitcheck++;
			}
			if (hit_board[row_index][col_index] == 'X' && hit_board[row_index][col_index - 1] != '~')
			{
				hitcheck++;
			}
			if (hitcheck > 3)
			{
				sum = 0;
				break;			
			}			
		} while ( hit_board[row_index][col_index] != 'X');

		if (sum >0)
		{			
			do
			{
				updown = ((rand() % 3) - 1);
				leftright = ((rand() % 3) - 1);
			} while ((abs(updown) == abs(leftright) || (row_index + updown) < 0) || ((col_index + leftright) < 0) || (row_index + updown > 9) || (col_index + leftright > 9) || hit_board[row_index + updown][col_index + leftright] != '~');
			if (board[row_index + updown][col_index + leftright] == '~')
			{
				int modcol = col_index + leftright;
				int modrow = row_index + updown;
				printf("\n\n%s Miss! (%d,%d)\n\n", player, modrow, modcol);
				*cpu_misses += 1;
				hit_board[row_index + updown][col_index + leftright] = 'M';
				fprintf(outfile, "Player 2 (%d,%d): Miss\n", modrow, modcol);
			}		
			if (board[row_index + updown][col_index + leftright] != '~')
			{
				int modcol = col_index + leftright;
				int modrow = row_index + updown;
				printf("\n\n%s Hit! (%d,%d)\n\n", player, modrow, modcol);
				*cpu_hits += 1;
				hit_board[row_index + updown][col_index + leftright] = 'X';
				fprintf(outfile, "Player 2 (%d,%d): Hit\n", modrow, modcol);
			}			
		}
	}
	if (sum == 0)
	{
		do
		{
			col_index = rand() % 10;
			row_index = rand() % 10;
		} while (hit_board[row_index][col_index] == 'M' || hit_board[row_index][col_index] == 'X');
		if (board[row_index][col_index] == '~')
		{
			printf("\n\n%s Miss! (%d,%d)\n\n", player, row_index, col_index);
			*cpu_misses += 1;
			hit_board[row_index][col_index] = 'M';
			fprintf(outfile, "Player 2 (%d,%d): Miss\n", row_index, col_index);
		}
		if (board[row_index][col_index] != '~')
		{
			printf("\n\n%s Hit! (%d,%d)\n\n", player, row_index, col_index);
			*cpu_hits += 1;
			hit_board[row_index][col_index] = 'X';
			fprintf(outfile, "Player 2 (%d,%d): Hit\n", row_index, col_index);
		}
	}	
}

void check_if_sunk(FILE* outfile, char board[][MAX_COLS], char hit_board[][MAX_COLS], int* ships_sunk, int num_rows, int num_cols, char player[20], int* a, int* b, int* c, int* s, int* d)
{

	int row_index = 0, col_index = 0;
	int aa = 0, bb = 0, cc = 0, ss = 0, dd = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols;
			++col_index)
		{
			if ((board[row_index][col_index] == 'A') && (hit_board[row_index][col_index] == 'X'))
			{
				aa += 1;
			}
			if ((board[row_index][col_index] == 'B') && (hit_board[row_index][col_index] == 'X'))
			{
				bb += 1;
			}
			if ((board[row_index][col_index] == 'C') && (hit_board[row_index][col_index] == 'X'))
			{
				cc += 1;
			}
			if ((board[row_index][col_index] == 'S') && (hit_board[row_index][col_index] == 'X'))
			{
				ss += 1;
			}
			if ((board[row_index][col_index] == 'D') && (hit_board[row_index][col_index] == 'X'))
			{
				dd += 1;
			}
		}
	}

	if (aa == 5 && *a == 0)
	{
		printf("\n\n%s Carrier has been sunk.\n", player);
		fprintf(outfile, "%s Carrier has been sunk.\n", player);
		*a = 1;
	}
	if (bb == 4 && *b == 0)
	{
		printf("\n\n%s Battleship has been sunk.\n", player);
		fprintf(outfile, "%s Battleship has been sunk.\n", player);
		*b = 1;
	}
	if (cc == 3 && *c == 0)
	{
		printf("\n\n%s Cruiser has been sunk.\n", player);
		fprintf(outfile, "%s Cruiser has been sunk.\n", player);
		*c = 1;
	}
	if (ss == 3 && *s == 0)
	{
		printf("\n\n%s Submarine has been sunk.\n", player);
		fprintf(outfile, "%s Submarine has been sunk.\n", player);
		*s = 1;
	}
	if (dd == 2 && *d == 0)
	{
		printf("\n\n%s Destroyer has been sunk.\n", player);
		fprintf(outfile, "%s Destroyer has been sunk.\n", player);
		*d = 1;
	}

}

int verify_winner(char hit_board[][MAX_COLS], int num_rows,
	int num_cols)
{

	int row_index = 0, col_index = 0, sum = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols;
			++col_index)
		{
			if (hit_board[row_index][col_index] == 'X')
			{
				sum += 1;
			}
		}
	}

	return sum;
}




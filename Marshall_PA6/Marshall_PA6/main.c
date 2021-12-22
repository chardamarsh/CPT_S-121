/*Programmer: Charles Marshall
*
  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 6: Battleship

  Date: 11-12-2021

  Description:  This file utilizes the functions defined in functions.c to do the following:

				Opens the output file <Battleship.log> for writing;
				Randomly or manually place ships on a players board;
				Randomly select player 1 or player 2 to go first;
				Allows both players to take one shot per turn, writing the coordinates of the shot and whether it was a hit or a miss to <Battleship.log>;
				Loops through each players turn until one player has sunk all of the other player's ships;
				After a winner is determined, the statistics of the game are written to <battleship.log>;
				Closes <Battleship.log> and exits the program.
  */
#include "functions.h"

int main(void)
{
	FILE* outfile = NULL;
	outfile = fopen("Battleship.log", "w");



	srand(time(NULL));
	char p1_game_board[MAX_ROWS][MAX_COLS];
	char cpu_game_board[MAX_ROWS][MAX_COLS];
	char cpu_hit_board[MAX_ROWS][MAX_COLS];
	char p1_hit_board[MAX_ROWS][MAX_COLS];
	int firstmove = 0, p1_wincheck = 0, cpu_wincheck = 0, winner = 0, placement = 0, round = 1;
	int p1_hits = 0, p1_misses = 0, p1_ships_sunk = 0;
	int cpu_hits = 0, cpu_misses = 0, cpu_ships_sunk = 0;
	int p1a = 0, p1b = 0, p1c = 0, p1s = 0, p1d = 0, p2a = 0, p2b = 0, p2c = 0, p2s = 0, p2d = 0; //used to make sure a ship sinking is only printed once to battleship.log.
	Stats p1_stats;
	Stats cpu_stats;

	welcome_screen();
	init_board(p1_game_board, MAX_ROWS, MAX_COLS);
	init_board(cpu_game_board, MAX_ROWS, MAX_COLS);
	init_board(cpu_hit_board, MAX_ROWS, MAX_COLS);
	init_board(p1_hit_board, MAX_ROWS, MAX_COLS);

	placement = choose_placement();

	if (placement == 1)
	{
		random_placement(p1_game_board, 5, 'A');
		random_placement(p1_game_board, 4, 'B');
		random_placement(p1_game_board, 3, 'C');
		random_placement(p1_game_board, 3, 'S');
		random_placement(p1_game_board, 2, 'D');
		printf("\n\nPlayer 1 game board:\n");
		print_board(p1_game_board, MAX_ROWS, MAX_COLS);
	}
	if (placement == 2)
	{
		manual_placement(p1_game_board, 5, 'A', "Carrier");
		print_board(p1_game_board, MAX_ROWS, MAX_COLS);
		manual_placement(p1_game_board, 4, 'B', "Battleship");
		print_board(p1_game_board, MAX_ROWS, MAX_COLS);
		manual_placement(p1_game_board, 3, 'C', "Cruiser");
		print_board(p1_game_board, MAX_ROWS, MAX_COLS);
		manual_placement(p1_game_board, 3, 'S', "Submarine");
		print_board(p1_game_board, MAX_ROWS, MAX_COLS);
		manual_placement(p1_game_board, 2, 'D', "Destroyer");
		printf("\n\nPlayer 1 game board:\n");
		print_board(p1_game_board, MAX_ROWS, MAX_COLS);
	}

	random_placement(cpu_game_board, 5, 'A');
	random_placement(cpu_game_board, 4, 'B');
	random_placement(cpu_game_board, 3, 'C');
	random_placement(cpu_game_board, 3, 'S');
	random_placement(cpu_game_board, 2, 'D');

	firstmove = first_move();
	if (firstmove == 0)
	{
		printf("\n\nPlayer 2 has been randomly selected to take the first turn.\n\n");
		system("pause");
		system("cls");
		while (p1_wincheck != 17 && cpu_wincheck !=17)
		{
			printf("\t\tROUND %d: Player 2's Turn\n\n", round);
			cpu_shot(outfile, &cpu_hits, &cpu_misses, p1_game_board, cpu_hit_board, MAX_ROWS, MAX_COLS, "Player 2");
			print_board(p1_game_board, MAX_ROWS, MAX_COLS);
			print_opponent_board(cpu_hit_board, MAX_ROWS, MAX_COLS);
			check_if_sunk(outfile, p1_game_board, cpu_hit_board, &cpu_ships_sunk, MAX_ROWS, MAX_COLS, "Player 1", &p1a, &p1b, &p1c, &p1s, &p1d);
			system("pause");
			system("cls");
			printf("\t\tROUND %d: Player 1's Turn\n\n", round);
			print_opponent_board(p1_hit_board, MAX_ROWS, MAX_COLS);
			take_shot(outfile, &p1_hits, &p1_misses, cpu_game_board, p1_hit_board, "Player 1");
			print_opponent_board(p1_hit_board, MAX_ROWS, MAX_COLS);
			check_if_sunk(outfile, cpu_game_board, p1_hit_board, &p1_ships_sunk, MAX_ROWS, MAX_COLS, "Player 2", &p2a, &p2b, &p2c, &p2s, &p2d);
			p1_wincheck = verify_winner(p1_hit_board, MAX_ROWS, MAX_COLS);
			cpu_wincheck = verify_winner(cpu_hit_board, MAX_ROWS, MAX_COLS);
			system("pause");
			system("cls");
			round++;
		}
		if (p1_wincheck == 17)
		{
			printf("\n\nYou win! Take a look at the file <output.log> to see the stats from this game.");
		}
		if (cpu_wincheck == 17)
		{
			printf("\n\nPlayer 2 wins! Take a look at the file <output.log> to see the stats from this game.");
			winner = 1;
		}
	}
	if (firstmove == 1)
	{
		printf("\n\nPlayer 1 has been randomly selected to take the first turn.\n\n");
		system("pause");
		system("cls");
		while (p1_wincheck != 17 && cpu_wincheck != 17)
		{
			printf("\t\tROUND %d: Player 1's Turn\n\n", round);
			print_opponent_board(p1_hit_board, MAX_ROWS, MAX_COLS);
			take_shot(outfile, &p1_hits, &p1_misses, cpu_game_board, p1_hit_board, "Player 1");
			print_opponent_board(p1_hit_board, MAX_ROWS, MAX_COLS);
			check_if_sunk(outfile, cpu_game_board, p1_hit_board, &p1_ships_sunk, MAX_ROWS, MAX_COLS, "Player 2", &p2a, &p2b, &p2c, &p2s, &p2d);
			system("pause");
			system("cls");
			printf("\t\tROUND %d: Player 2's Turn\n\n", round);
			cpu_shot(outfile, &cpu_hits, &cpu_misses, p1_game_board, cpu_hit_board, MAX_ROWS, MAX_COLS, "Player 2");
				print_board(p1_game_board, MAX_ROWS, MAX_COLS);
			print_opponent_board(cpu_hit_board, MAX_ROWS, MAX_COLS);
			check_if_sunk(outfile, p1_game_board, cpu_hit_board, &cpu_ships_sunk, MAX_ROWS, MAX_COLS, "Player 1", &p1a, &p1b, &p1c, &p1s, &p1d);
			p1_wincheck = verify_winner(p1_hit_board, MAX_ROWS, MAX_COLS);
			cpu_wincheck = verify_winner(cpu_hit_board, MAX_ROWS, MAX_COLS);
			system("pause");
			system("cls");
			round++;
		}
		if (p1_wincheck == 17)
		{
			printf("\n\nYou win! Take a look at the file <output.log> to see the stats from this game.");
		}
		if (cpu_wincheck == 17)
		{
			printf("\n\nPlayer 2 wins! Take a look at the file <output.log> to see the stats from this game.");
			winner = 1;
		}
	}
	if (cpu_wincheck == 17 || p1_wincheck == 17)
	{
		p1_stats.hits = p1_hits;
		p1_stats.misses = p1_misses;
		p1_stats.shots = (p1_hits + p1_misses);
		p1_stats.h_m_ratio = p1_hits / p1_stats.shots;
		if (winner == 0)
		{
			p1_stats.win_lose = 'Y';
			cpu_stats.win_lose = 'N';
		}
		cpu_stats.hits = cpu_hits;
		cpu_stats.misses = cpu_misses;
		cpu_stats.shots = (cpu_hits + cpu_misses);
		cpu_stats.h_m_ratio = cpu_hits / cpu_stats.shots;
		if (winner == 1)
		{
			cpu_stats.win_lose = 'Y';
			p1_stats.win_lose = 'N';
		}

		fprintf(outfile, "\n\n\n\t\t\tPLAYER 1 STATS\n\nHits: %d\nMisses: %d\nTotal Shots: %.0f\nHit-Miss Ratio: %.3f\nWinner: %c", p1_stats.hits, p1_stats.misses, p1_stats.shots, p1_stats.h_m_ratio, p1_stats.win_lose);
		fprintf(outfile, "\n\n\n\t\t\tPLAYER 2 STATS\n\nHits: %d\nMisses: %d\nTotal Shots: %.0f\nHit-Miss Ratio: %.3f\nWinner: %c", cpu_stats.hits, cpu_stats.misses, cpu_stats.shots, cpu_stats.h_m_ratio, cpu_stats.win_lose);
		fclose(outfile);
	}
	return 0;
}

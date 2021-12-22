/*Programmer: Charles Marshall

  Class: CPTS 121; Lab section 11

  Programming Assignment: PA 5: Yahtzee

  Date: 10-27-2021

  Description:  This file contains the headers for the functions used in this program.

  */
#define _CRT_SECURE_NO_WARNINGS

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void print_menu(void);


int get_option(void);

int print_and_validate(void);

void print_rules(void);

void roll_dice(int dice[5]);

void keep_or_reroll(int dice[5]);

void print_dice(int dice[5]);

void ones(int dice[5], int categories[13], int scores[13]);

void twos(int dice[5], int categories[13], int scores[13]);

void threes(int dice[5], int categories[13], int scores[13]);

void fours(int dice[5], int categories[13], int scores[13]);

void fives(int dice[5], int categories[13], int scores[13]);

void sixes(int dice[5], int categories[13], int scores[13]);

void three_of_a_kind(int dice[5], int categories[13], int scores[13]);

void four_of_a_kind(int dice[5], int categories[13], int scores[13]);

void full_house(int dice[5], int categories[13], int scores[13]);

void small_straight(int dice[5], int categories[13], int scores[13]);

void large_straight(int dice[5], int categories[13], int scores[13]);

void chance(int dice[5], int categories[13], int scores[13]);

void yahtzee(int dice[5], int categories[13], int scores[13]);

void choose_category(int dice[5], int categories[13], int scores[13]);

int print_scorecard(int scores[13], int player);

void determine_winner(int grand_total1, int grand_total2);

#endif
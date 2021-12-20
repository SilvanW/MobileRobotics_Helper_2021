/*
 ============================================================================
 Name        : Projektarbeit
 Author      : Luca Bargetzi, Florian Büttiker, Samuel Schwitter
 Version     :
 Copyright   : Your copyright notice
 Description : Projektarbeit
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void names(char player1[], char player2[]);
void drawing(int Input[]);
void val_input(int Input[], char player1[], char player2[]);
int check(int Input[]);




int TicTacToe(void)
{
	char player1[20];
	char player2[20];
	int Input[9] = {};
	int win = 0;
	
	names(player1, player2);
	
	
	
	while(win == 0)
	{
		val_input(Input,player1,player2);
		win = check(Input);
	}
	
	if (win == 1)
	{
		printf("Gratullation %s hat gewonnen\n", player1);
		drawing(Input);	
	}
	else
	{
		printf("Gratullation %s hat gewonnen\n", player2);
		drawing(Input);
	}
	
	return EXIT_SUCCESS;
	
	
}
void names(char player1[], char player2[])
{
	printf("Wie heisst Spieler 1?\n");
	scanf("%19s", player1);
	printf("Und Spieler 2?\n");
	scanf("%19s", player2);
	
}

void drawing(int Input[])
{
	static char drawing_position[] = {'1','2','3','4','5','6','7','8','9'};
	
	for (int i = 0; i < 9; i++)
	{
		if (Input[i] == 1)
		{
			drawing_position[i] = 'X';
		}
		else if (Input[i] == 2)
		{
			drawing_position[i] = 'O';
		}
	}
	
	printf("	%c	|	%c	|	%c	\n", drawing_position[0], drawing_position[1], drawing_position[2]);
	printf("--------------------------------------------------\n");
	printf("	%c	|	%c	|	%c	\n", drawing_position[3], drawing_position[4], drawing_position[5]);
	printf("--------------------------------------------------\n");
	printf("	%c	|	%c	|	%c	\n", drawing_position[6], drawing_position[7], drawing_position[8]);
}

void val_input(int Input[], char player1[], char player2[])
{
	int player_input = 0;
	char player_names[2][20];
	static int player_id = 1;
	
	strcpy(player_names[0], player1);
	strcpy(player_names[1], player2);	
	

	drawing(Input);
	
	
	
	printf("Du bist dran %s\n", player_names[player_id-1]);
	

	scanf("%d", &player_input);
	
	while ((player_input < 1 || player_input > 9)||(Input[player_input-1] != 0)) //Wird ausgeführt bis beide sicher erfüllt sind
	{
		
		while (player_input < 1 || player_input > 9)
		{
			printf("Bitte geben Sie einen Wert zwischen 1 und 9 an\n");
			scanf("%d", &player_input);
		}
		
		while (Input[player_input-1] != 0)
		{
			printf("Dieses Feld ist schon beschrieben, bitte waehlen Sie ein anderes\n");
			scanf("%d", &player_input);
			
		}
	}
	
	Input[player_input-1] = player_id;
	
	if (player_id == 1)
	{
		player_id++;
	}
	else
	{
		player_id--;
	}
	
	return;
}

int check(int Input[]) //noch schauen WER gewinnt
{

	if (Input[0] == Input[1] && Input[1] == Input[2] && Input[0] != 0)
	{
		return Input[0];
	}
	else if (Input[3] == Input[4] && Input[4] == Input[5] && Input[3] != 0)
	{
		return Input[3];
	}
	else if (Input[6] == Input[7] && Input[7] == Input[8] && Input[6] != 0)
	{
		return Input[6];
	}
	else if (Input[0] == Input[3] && Input[3] == Input[6] && Input[0] != 0)
	{
		return Input[0];
	}
	else if (Input[1] == Input[4] && Input[4] == Input[7] && Input[1] != 0)
	{
		return Input[1];
	}
	else if (Input[2] == Input[5] && Input[5] == Input[8] && Input[2] != 0)
	{
		return Input[2];
	}
	else if (Input[0] == Input[4] && Input[4] == Input[8] && Input[0] != 0)
	{
		return Input[0];
	}
	else if (Input[2] == Input[4] && Input[4] == Input[6] && Input[2] != 0)
	{	
		return Input[2];
	}
	else
	{
		return  0;
	}	
}
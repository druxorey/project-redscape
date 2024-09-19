#include <iostream>
#include "include/cutscenes.hpp"
#include "include/cards.hpp"

// given a number of appearances, an "is_special" flag, and a pointer to an int, 
// adds the corresponding number of points (based on the number of appearances,
// and whether they're special or not) onto the integer pointer, and returns
// a pointer to a string literal containing a dialogue for the number of points.
const char *get_points(int appearances, bool is_special, int *points);

int main() {
	int i;
	/* const char *hint = "(Presiona ENTER para que se mueva el muñeco)";
	scene cutscene[] = {
		{"assets/loading/1.txt", hint},
		{"assets/loading/2.txt", hint},
		{"assets/loading/3.txt", hint},
		{"assets/loading/4.txt", hint},
		{"assets/loading/3.txt", hint},
		{"assets/loading/2.txt", hint},
	};
	i = 3;
	while(i--)
		print_cutscene(cutscene, 6); */
	
	// initialization of the game
	card deck[DECKSIZE];
	initialize_deck(deck);

	card player_hand[HANDSIZE];
	card enemy_hand[HANDSIZE];	

	generate_hand(deck, player_hand);
	generate_hand(deck, enemy_hand);

	// rendering of the current state
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE);

	// asking the user to pick cards
	char c, pick_cards_dialogue[100];
	sprintf(pick_cards_dialogue, "%s%d%s", "Selecciona una carta que quieras cambiar (1 ... ", HANDSIZE, "). Presiona ENTER/ANY cuando estés listo/a");
	print_dialogue(pick_cards_dialogue);

	while ((c = getchar()) != EOF && c != '\n' && c >= '1' && c <= HANDSIZE + '0') {
		i = atoi(&c) - 1;
		player_hand[i].chosen = !player_hand[i].chosen;

		print_cards(player_hand, HANDSIZE);
		print_dialogue(pick_cards_dialogue);
		getchar();
	}
	
	// swapping the chosen cards
	int card_i;
	for (i = 0; i < HANDSIZE; i++)
		if (player_hand[i].chosen) {
			card_i = get_card(deck);
			if (card_i == -1) {
				fprintf(stderr, "%s", "The deck ran out of cards. (unintended behavior)");
				return -1;
			}
			player_hand[i].type = deck[card_i].type;
			player_hand[i].value = deck[card_i].value;
			player_hand[i].chosen = false;
		}

	for(i = 0; i < HANDSIZE; i++)
		printf("\n%d JUGADOR: value: %d, type: %d\n", i + 1, player_hand[i].value, player_hand[i].type);

	// BEGIN COMPARISON OF YOUR CARDS AND ENEMY'S. THE ONE WITH MORE POINTS WINS THE ROUND.
	
	int normal[TYPENUM] = {0};
	int special[DECKSIZE / TYPENUM + 1] = {0};

	for (i = 0; i < HANDSIZE; i++) {
		normal[player_hand[i].type]++;
		special[player_hand[i].value]++;
	}
	
	printf("%s\n", "NORMAL APEARANCES (NOT REPETITIONS)");
	for (i = 0; i < TYPENUM; i++)
		printf("\"%d\" ", normal[i]);
	printf("\n%s\n", "SPECIAL APEARANCES (NOT REPETITIONS)");
	for (i = 1; i < DECKSIZE / TYPENUM + 1; i++)
		printf("\"%d\" ", special[i]);
	printf("\n");

	// This version doesn't work, but it was supposed to waste less memory
	// Couldn't make it run though.
	// But I will, I don't give up, and I won't run away. That's my nindo, my ninja way.
	// (Nah, I actually won't, it might waste more memory, but it's less computing intensive
	// which's better for a videogame)

	// Garbage code, needs refactoring

	/*bool t0, t1, t2, t3; // type 0, 1 .. 3
	t0 = t1 = t2 = t3 = false;
	
	for (i = 0; i < HANDSIZE; i++)
	{
		for (int j = (i + 1), specials = 0, normals = 0; j < HANDSIZE; j++)
		{
			if (player_hand[i].type == player_hand[j].type)
			{
				if (player_hand[i].value == player_hand[j].value)
				{
					special[player_hand[i].type]++;
					specials++;
				}
				normal[player_hand[i].type]++;
				normals++;
			}
		}
	}*/

	// EOF (End Of Fucked up nonsense)


	int total_points = 0;
	for (i = 0; i < TYPENUM; i++)
		if (special[i] == 5) {
			printf("%s\n", "Quíntuple especial, 12 puntos");
			total_points += 12;
		}
		else if (special[i] == 4) {
			printf("%s\n", "Cuádruple especial, 10 puntos");
			total_points += 10;
		}
		else if (special[i] == 3) {
			printf("%s\n", "Triple especial, 7 puntos");
			total_points += 7;
		}
		else if (normal[i] == 5) {
			printf("%s\n", "Quíntuple, 7 puntos");
			total_points += 7;
		}
		else if (special[i] == 2) {
			printf("%s\n", "Pareja especial, 5 puntos");
			total_points += 5;
		}
		else if (normal[i] == 4) {
			printf("%s\n", "Cuádruple, 5 puntos");
			total_points += 5;
		}
		else if (normal[i] == 3) {
			printf("%s\n", "Triple, 3 puntos");
			total_points += 3;
		}
		else if (normal[i] == 2) {
			printf("%s\n", "Pareja, 2 puntos");
			total_points += 2;
		}

	printf("%s %d\n", "Total:", total_points);
	
	return 0;
}

// given a number of appearances, an "is_special" flag, and a pointer to an int, 
// adds the corresponding number of points (based on the number of appearances,
// and whether they're special or not) onto the integer pointer, and returns
// a pointer to a string literal containing a dialogue for the number of points.
const char *get_points(int appearances, bool is_special, int *points) {
	if (is_special && appearances == 5) {
		*points += 12;
		return "¡Quíntuple especial, 12 puntos (Máximo puntaje)!";
	}
	else if (is_special && appearances == 4) {
		*points += 10;
		return "¡Cuádruple especial, 10 puntos!";
	}
	else if (is_special && appearances == 3) {
		*points += 7;
		return "¡Triple especial, 7 puntos!";
	}
	else if (appearances == 5) {
		*points += 7;
		return "¡Quíntuple, 7 puntos!";
	}
	else if (is_special && appearances == 2) {
		*points += 5;
		return "Pareja especial, 5 puntos.";
	}
	else if (appearances == 4) {
		*points += 5;
		return "Cuádruple, 5 puntos.";
	}
	else if (appearances == 3) {
		*points += 3;
		return "Triple, 3 puntos.";
	}
	else if (appearances == 2) {
		*points += 2;
		return "Pareja, 2 puntos.";
	}
	return NULL;
}

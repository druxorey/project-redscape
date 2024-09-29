#include <iostream>
#include <string>
#include "include/cutscenes.hpp"
#include "include/cards.hpp"
#include "include/utils.hpp"
#include "include/engine.hpp"

char first_character_matrix[HEIGHT_SCREEN][WIDTH_SCREEN];
char second_character_matrix[HEIGHT_SCREEN][WIDTH_SCREEN];
char dialog_matrix[HEIGHT_SCREEN][WIDTH_SCREEN];


int tutorial();


int main() {
	initialize_matrix(first_character_matrix);
	initialize_matrix(second_character_matrix);
	initialize_matrix(dialog_matrix);

	clear();

	process_title("assets/configuration-screen");
	std::cin.get();
	clear();
	process_title("assets/title_screen_1.txt");
	refresh(2000);
	process_title("assets/title_screen_2.txt");

	std::cin.get();

	clear();

	process_prologue(dialog_matrix, 2);

	clear();
	refresh(1000);

	for (int i = 3; i <= 19; i++) {
		process_prologue(dialog_matrix, i);
	}

	clear();
	process_dialog_scene("assets/daniel/daniel", 20, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 21, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/daniel/daniel", 22, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/daniel/daniel", 23, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 24, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/daniel/daniel", 25, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	bool userWon = tutorial();
	
	if (userWon) {
		process_dialog_scene("assets/daniel/daniel", 26, 'd', second_character_matrix, dialog_matrix);
	} else {
		process_dialog_scene("assets/daniel/daniel", 27, 'd', second_character_matrix, dialog_matrix);
	}

	refresh(2500);
	process_dialog_scene("assets/daniel/daniel", 28, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	for (int i = 29; i <= 33; i++) {
		process_prologue(dialog_matrix, i);
	}

	process_dialog_scene("assets/el-general", 34, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 35, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/el-general", 36, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 37, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/el-general", 38, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/el-general", 39, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 40, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/el-general", 41, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	// HERE STARTS THE FIRST FIGHT

	process_dialog_scene("assets/el-general", 42, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	for (int i = 43; i <= 58; i++) {
		process_prologue(dialog_matrix, i);
	}

	process_dialog_scene("assets/roberto", 59, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 60, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 61, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	for (int i = 62; i <= 63; i++) {
		process_prologue(dialog_matrix, i);
	}

	process_dialog_scene("assets/roberto", 64, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 65, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 66, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	for (int i = 67; i <= 70; i++) {
		process_prologue(dialog_matrix, i);
	}

	process_dialog_scene("assets/prisioner-1", 71, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/prisioner-1", 72, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 73, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/prisioner-1", 74, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/prisioner-1", 75, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	for (int i = 76; i <= 78; i++) {
		process_prologue(dialog_matrix, i);
	}

	// Frome here, the user has to fight 4 times, each time has to return a boolean to determine the dialogue and if it fails is a game over
	
	// HERE STARTS THE SECOND FIGHT

	process_dialog_scene("assets/prisioner-1", 79, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/prisioner-1", 80, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	// HERE STARTS THE THIRD FIGHT

	process_dialog_scene("assets/prisioner-2", 81, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/prisioner-2", 82, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	
	// HERE STARTS THE FOURTH FIGHT

	process_dialog_scene("assets/prisioner-3", 83, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/prisioner-3", 84, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	// HERE STARTS THE FIFTH FIGHT

	process_dialog_scene("assets/prisioner-4", 85, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/prisioner-4", 86, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	process_dialog_scene("assets/roberto", 87, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 88, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 89, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 90, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 91, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 92, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	for (int i = 93; i <= 97; i++) {
		process_prologue(dialog_matrix, i);
	}

	process_dialog_scene("assets/roberto", 98, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 99, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 100, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 101, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 102, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 103, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 104, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 105, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 106, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 107, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 108, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 109, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 110, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 111, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 112, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);


	for (int i = 113; i <= 114; i++) {
		process_prologue(dialog_matrix, i);
	}

	process_dialog_scene("assets/aleajandro", 115, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/aleajandro", 116, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 117, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/aleajandro", 118, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 119, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);

	// HERE STARTS THE SIXTH FIGHT

	for (int i = 120; i <= 124; i++) {
		process_prologue(dialog_matrix, i);
	}

	process_dialog_scene("assets/prisioner-5", 125, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	for (int i = 126; i <= 128; i++) {
		process_prologue(dialog_matrix, i);
	}

	process_dialog_scene("assets/la-vaca", 129, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 130, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/la-vaca", 131, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/la-vaca", 132, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 133, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/la-vaca", 134, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/la-vaca", 135, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/la-vaca", 136, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/la-vaca", 137, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 138, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/la-vaca", 139, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/la-vaca", 140, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	// HERE STARTS THE SEVENTH FIGHT

	for (int i = 141; i <= 142; i++) {
		process_prologue(dialog_matrix, i);
	}

	process_dialog_scene("assets/roberto", 143, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 144, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 145, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/roberto", 146, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	for (int i = 147; i <= 149; i++) {
		process_prologue(dialog_matrix, i);
	}

	process_dialog_scene("assets/barbara", 150, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 151, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/barbara", 152, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 153, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/barbara", 154, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/barbara", 155, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 156, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);

	for (int i = 157; i <= 160; i++) {
		process_prologue(dialog_matrix, i);
	}

	// HERE STARTS THE EIGHTHT FIGHT

	for (int i = 161; i <= 168; i++) {
		process_prologue(dialog_matrix, i);
	}

	process_dialog_scene("assets/jueza", 169, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 170, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/jueza", 171, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/el-general", 172, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/el-general", 173, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/jueza", 174, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/jueza", 175, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/el-general", 176, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 177, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/jueza", 178, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	// HERE STARTS THE NINTH FIGHT

	process_dialog_scene("assets/el-general", 179, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/mary/mary", 180, 'd', first_character_matrix, dialog_matrix);
	refresh(2500);
	process_dialog_scene("assets/jueza", 181, 'd', second_character_matrix, dialog_matrix);
	refresh(2500);

	for (int i = 182; i <= 184; i++) {
		process_prologue(dialog_matrix, i);
	}

	return 0;
}


int tutorial() {
	// initialization of the game
	card deck[DECKSIZE];
	initialize_deck(deck);

	card player_hand[HANDSIZE];
	card enemy_hand[HANDSIZE];
	card example_hand[HANDSIZE];

	generate_hand(deck, player_hand);
	generate_hand(deck, enemy_hand);

	// rendering of the current state
	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("FRIEND_NAME: Cada uno tiene una mano aleatoria de cartas.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("FRIEND_NAME: Tienes que fijarte en que tengas varias cartas del mismo tipo, y/o con el mismo número.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	example_hand[0] = {0, 3, 0};
	example_hand[1] = {0, 12, 0};
	print_cards(example_hand, 2, true);
	print_dialogue("FRIEND_NAME: Por ejemplo, si tienes 2 cartas con el mismo tipo, se considera una pareja.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	example_hand[0] = {3, 11, 0};
	example_hand[1] = {1, 11, 0};
	print_cards(example_hand, 2, true);
	print_dialogue("FRIEND_NAME: Pero si tienen el mismo número, es una pareja especial, y vale más prestigio.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("FRIEND_NAME: Ya que tienes tus cartas, puedes decidir si cambiar algunas de ellas, o no.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("FRIEND_NAME: Por supuesto, con el riesgo de que te toquen cartas peores. Pero solo puedes cambiarlas una vez.");
	enter();

	// asking the user to pick cards
	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	char c, pick_cards_dialogue[93];
	sprintf(pick_cards_dialogue, "%s%d%s", "Selecciona una carta que quieras cambiar (1 ... ", HANDSIZE, "). Presiona ENTER cuando estés listo/a");
	print_dialogue(pick_cards_dialogue);

	int i;
	while ((c = getchar()) != EOF && c != '\n' && c >= '1' && c <= HANDSIZE + '0') {
		i = atoi(&c) - 1;
		player_hand[i].chosen = !player_hand[i].chosen;
		
		clear();
		print_rcards(HANDSIZE);
		print_cards(player_hand, HANDSIZE, true);
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

	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("FRIEND_NAME: Ahora es momento de revelar cuantos puntos tiene cada uno.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("FRIEND_NAME: El que tenga más puntos se queda con esa misma cantidad de prestigio del rival.");
	enter();
		
	// BEGIN COMPARISON OF YOUR CARDS AND ENEMY'S. THE ONE WITH MORE POINTS WINS THE ROUND.
	int special[DECKSIZE / TYPENUM + 1] = {0};
	int normal[TYPENUM] = {0};

	for (i = 0; i < HANDSIZE; i++) {
		special[player_hand[i].value]++;
		normal[player_hand[i].type]++;
	}

	// NOTE: It can only happen that an appearance is whether normal or special
	// NOT both at the same time, since 2 cards can't share the same type and number
	int points = 0;
	const char *points_dialogue;
	for (i = 1; i < (DECKSIZE / TYPENUM + 1); i++) {
		if ((points_dialogue = get_points(special[i], true, &points)) != NULL) {
			clear();
			print_rcards(HANDSIZE);
			print_cards(player_hand, HANDSIZE, true);
			print_dialogue(points_dialogue);
			enter();
		}
	}
	for (i = 0; i < TYPENUM; i++) {
		if ((points_dialogue = get_points(normal[i], false, &points)) != NULL) {
			clear();
			print_rcards(HANDSIZE);
			print_cards(player_hand, HANDSIZE, true);
			print_dialogue(points_dialogue);
			enter();
		}
	}

	char total_points_dialogue[9];
		
	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);

	sprintf(total_points_dialogue, "Total: %d", points);
	print_dialogue(total_points_dialogue);

	// Calculate enemy's points
	for (i = 0; i < HANDSIZE; i++)
		normal[i] = special[i] = 0;

	for (i = 0; i < HANDSIZE; i++) {
		special[enemy_hand[i].value]++;
		normal[enemy_hand[i].type]++;
	}

	// NOTE: It can only happen that an appearance is whether normal or special
	// NOT both at the same time, since 2 cards can't share the same type and number

	int enemy_points = 0;
	for (i = 1; i < (DECKSIZE / TYPENUM + 1); i++)
		get_points(special[i], true, &enemy_points);
	for (i = 0; i < TYPENUM; i++)
		get_points(normal[i], false, &enemy_points);

	// Reveal enemy's cards
	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("FRIEND_NAME: El que tenga más puntos se queda con esa misma cantidad de prestigio del rival.");
	enter();

	const char *card_reveal_dialogue;
	if (points < enemy_points)
		card_reveal_dialogue = "FRIEND_NAME: Bueno, pareciera que aún se te da bien, menos mal porque TU VIDA DEPENDE DE EL JUEGO. Bueno, nos vamos ya? Te dejo en tu casa.";
	else
		card_reveal_dialogue = "FRIEND_NAME: Tienes que estar más atenta, recuerda que TU VIDA DEPENDE DE EL JUEGO. Bueno, nos vamos ya? Te dejo en tu casa.";
	
	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue(card_reveal_dialogue);
	enter();

	return 0;
}

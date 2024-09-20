#include <iostream>
#include "include/cutscenes.hpp"
#include "include/cards.hpp"
#include "include/utils.hpp"

int main() {
	int i;
	
	// initialization of the game
	card deck[DECKSIZE];
	initialize_deck(deck);

	card player_hand[HANDSIZE];
	card enemy_hand[HANDSIZE];	

	generate_hand(deck, player_hand);
	generate_hand(deck, enemy_hand);

	// rendering of the current state
	clear();
	print_rcards(HANDSIZE);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n"); // this should be done on a better way
	print_cards(player_hand, HANDSIZE, true);

	// asking the user to pick cards
	char c, pick_cards_dialogue[93];
	sprintf(pick_cards_dialogue, "%s%d%s", "Selecciona una carta que quieras cambiar (1 ... ", HANDSIZE, "). Presiona ENTER cuando estés listo/a");
	print_dialogue(pick_cards_dialogue);

	while ((c = getchar()) != EOF && c != '\n' && c >= '1' && c <= HANDSIZE + '0') {
		i = atoi(&c) - 1;
		player_hand[i].chosen = !player_hand[i].chosen;
		
		clear();
		print_rcards(HANDSIZE);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n"); // this should be done on a better way
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
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n"); // this should be done on a better way
	print_cards(player_hand, HANDSIZE, true);
		
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
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n"); // this should be done on a better way
			print_cards(player_hand, HANDSIZE, true);
			print_dialogue(points_dialogue);
			getchar();
		}
	}
	for (i = 0; i < TYPENUM; i++) {
		if ((points_dialogue = get_points(normal[i], false, &points)) != NULL) {
			clear();
			print_rcards(HANDSIZE);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n"); // this should be done on a better way
			print_cards(player_hand, HANDSIZE, true);
			print_dialogue(points_dialogue);
			getchar();
		}
	}

	char total_points_dialogue[9];
		
	clear();
	print_rcards(HANDSIZE);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n"); // this should be done on a better way
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

	const char *card_reveal_dialogue;
	if (points < enemy_points)
		card_reveal_dialogue = "Muajuajuajuajuajuajua... You're so noob lmao I've won, retire or something";
	else
		card_reveal_dialogue = "Alright, let's see...";
	
	clear();
	print_rcards(HANDSIZE);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n"); // this should be done on a better way
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue(card_reveal_dialogue);

	clear();
	print_cards(enemy_hand, HANDSIZE, false);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n"); // this should be done on a better way
	print_cards(player_hand, HANDSIZE, true);
	
	return 0;
}

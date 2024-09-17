#include <iostream>
#include "../include/cards.hpp"

void initialize_deck(card *deck) {
	for (int i = 0, j = DECKSIZE / TYPENUM; i < j; i++) {
		for (int k = 0; k < 4; k++) {
			deck[i + j * k].type = k;
			deck[i + j * k].value = i + 1;
			deck[i + j * k].chosen = false;
		}
	}
}

void generate_hand(card *deck, card *hand) {
	int randcard;
	for (int i = 0; i < HANDSIZE; ) {
		randcard = rand() % DECKSIZE;
		if (deck[randcard].chosen == false) {
			hand[i].type = deck[randcard].type;
			hand[i].value = deck[randcard].value;
			hand[i].chosen = false;
			deck[randcard].chosen = true;
			i++;
		}
	}
}

int get_card(card *deck) {
	int randcard = rand() % DECKSIZE;
	if (deck[randcard].chosen == false) {
		deck[randcard].chosen = true;
		return randcard;
	}
	return -1;
}


void print_card(card c) {
	printf("%s\n", "┌──────────────┐");
	printf("%s %d %-10s %s\n",    "│", c.value, c.type, "│");
	printf("%s %-12d %s\n",       "│", c.value,         "│");
	for (int j = 0; j < 7; j++)
		printf("%s\n", "│              │");
    	printf("%s",   "└──────────────┘");
}

void print_cards(card cards[], unsigned int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%s", "┌──────────────┐    ");
	printf("%c", '\n');
	for (i = 0; i < n; i++)
		printf("%s %d %-10s %s", "│", cards[i].value, cards[i].type, "│    ");
	printf("%c", '\n');
	for (i = 0; i < n; i++)
		printf("%s %-12d %s",    "│", cards[i].value, "│    ");
	printf("%c", '\n');
	for (int j = 0; j < 7; j++) {
		for (i = 0; i < n; i++)
		    printf("%s", "│              │    ");
		printf("%c", '\n');
	}
	for (i = 0; i < n; i++)
		printf("%s", "└──────────────┘    ");
}

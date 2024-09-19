#include <iostream>
#include <string>
#include "../include/cards.h"

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

const char *to_symbol(int type) {
	if (type == 0)
		return "♣";
	else if (type == 1)
		return "♦";
	else if (type == 2)
		return "♥";
	else
		return "♠";
} 

const char *to_letter(int n) {
	// XD what is this implementation, for god's sake
	if (n == 1)
		return "1";
	else if (n == 2)
		return "2";
	else if (n == 3)
		return "3";
	else if (n == 4)
		return "4";
	else if (n == 5)
		return "5";
	else if (n == 6)
		return "6";
	else if (n == 7)
		return "7";
	else if (n == 8)
		return "8";
	else if (n == 9)
		return "9";
	else if (n == 10)
		return "10";
	else if (n == 11)
		return "J";
	else if (n == 12)
		return "Q";
	else if (n == 13)
		return "K";
	else
		return "A";
}

void print_card(card c) {
	const char *n = to_letter(c.value);
	const char *s = to_symbol(c.type);
	int p = c.value != 10;

	printf("%s %s %s%*s         %s         %2s %s %s",
	"┌──────────────┐\n"
	"│", n,s,p,"", "│\n"
	"│  ┌────────┐  │\n"
	"│  │        │  │\n"
	"│  │        │  │\n"
	"│  │        │  │\n"
	"│  │        │  │\n"
	"│  │        │  │\n"
	"│  │        │  │\n"
	"│  └────────┘  │\n"
	"│",     n, s, "│\n"
	"└──────────────┘\n"
	);
}

void print_rcard() {
	printf("%s",
	"┌──────────────┐\n"
	"│# # # # # # # │\n"
	"│ # # # # # # #│\n"
	"│# # # # # # # │\n"
	"│ # # # # # # #│\n"
	"│# # # # # # # │\n"
	"│ # # # # # # #│\n"
	"│# # # # # # # │\n"
	"│ # # # # # # #│\n"
	"│# # # # # # # │\n"
	"│ # # # # # # #│\n"
	"└──────────────┘\n"
	);
}

void print_cards(card c[], unsigned int n) {
	int i, j, p;

	for (i = 0; i < n; i++)
		printf("%s ", "┌──────────────┐");
	printf("\n");
	for (i = 0; i < n; i++) {
		p = c[i].value != 10;
		printf("%s %s %s%*s         %s ", "│", to_letter(c[i].value), to_symbol(c[i].type), p, "", "│");
	}
	printf("\n");
	for (i = 0; i < n; i++)
		printf("%s ", "│  ┌────────┐  │");
	printf("\n");
	for (i = 0; i < 6; i++) {
		for (j = 0; j < n; j++)
			printf("%s ", "│  │        │  │");
		printf("\n");
	}
	for (i = 0; i < n; i++)
		printf("%s ", "│  └────────┘  │");
	printf("\n");
	for (i = 0; i < n; i++)
		printf("%s         %2s %s %s ", "│", to_letter(c[i].value), to_symbol(c[i].type), "│");
	printf("\n");
	for (i = 0; i < n; i++)
		printf("%s ", "└──────────────┘");
	printf("\n");
}

void print_rcards(unsigned int n) {
	int i, j;

	for (i = 0; i < n; i++)
		printf("%s ", "┌──────────────┐");
	printf("\n");
	for (i = 0; i < 10; i ++) {
		for (j = 0; j < n; j++)
			if (i % 2)
				printf("%s ", "│ # # # # # # #│");
			else
				printf("%s ", "│# # # # # # # │");
		printf("\n");
	}
	for (i = 0; i < n; i++)
		printf("%s ", "└──────────────┘");
	printf("\n");
}

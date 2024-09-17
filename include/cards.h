#pragma once

// The size of a deck, a hand, and the number of card types, change wisely.
#define DECKSIZE 52
#define HANDSIZE 7
#define TYPENUM 4

typedef struct {
	int type;  // 0 ... 3: clubs, diamonds, hearts and spades (Not necessarily those in the final version)
	int value; // 1 .. 13: 1, 2 ... 10, J, Q, K, A.	
	bool chosen; // In the deck context, it means it's been taken by someone.
		     // In the hand context, it means it's been picked for swap.
} card;

// given a deck, initializes it with ordered cards (ej. clubs 0 ... 12, diamonds 13 ... 26, hearts 27 ... 40, spades 41 ... 51)
// no error detection, the deck MUST have enough space for the cards.
void initialize_deck(card *deck);

// takes a deck, and puts {HANDSIZE} of its available cards onto the hand.
void generate_hand(card *deck, card *hand);

// given a deck, return an input to an available card
int get_card(card *deck);

// prints the given card in the screen, without line feed character
void print_card(card);

// prints the given cards horizontally in the screen, without line feed character
// the second arguments is the number of cards inside the array
void print_cards(card [], unsigned int);


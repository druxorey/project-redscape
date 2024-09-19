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

// given a type (0 .. 3), returns a pointer to string literal containing the symbol of the type
const char *to_symbol(int type);
//
// given a card number value (1 .. 13), returns a pointer to string literal containing the number or the letter of the card
const char *to_letter(int n);

/* prints the given card in the screen, with this format:
┌──────────────┐
│ 10 ♣         │
│  ┌────────┐  │
│  │        │  │
│  │        │  │
│  │        │  │
│  │        │  │
│  │        │  │
│  │        │  │
│  └────────┘  │
│         ♣ 10 │
└──────────────┘

*/
void print_card(card);

/* prints a reversed card in the screen, with this format:
┌──────────────┐
│# # # # # # # │
│ # # # # # # #│
│# # # # # # # │
│ # # # # # # #│
│# # # # # # # │
│ # # # # # # #│
│# # # # # # # │
│ # # # # # # #│
│# # # # # # # │
│ # # # # # # #│
└──────────────┘

*/
void print_rcard();

// prints the given cards horizontally in the screen
// the second arguments is the number of cards inside the array
void print_cards(card [], unsigned int);

// prints the given number of reversed cards horizontally in the screen
void print_rcards(unsigned int);


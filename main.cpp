#include <iostream>
#include "include/cards.hpp"

int main() {
	card deck[DECKSIZE];
	initialize_deck(deck);

	card player_hand[HANDSIZE];
	card enemy_hand[HANDSIZE];	

	srand(time(NULL));
	generate_hand(deck, player_hand);
	generate_hand(deck, enemy_hand);

	int i;
	for(i = 0; i < HANDSIZE; i++)
		printf("ENEMIGO: value: %d, type: %d\n", enemy_hand[i].value, enemy_hand[i].type);

	for(i = 0; i < HANDSIZE; i++)
		printf("JUGADOR: value: %d, type: %d\n", player_hand[i].value, player_hand[i].type);

	printf("%s%d%s\n", "Selecciona una carta que quieras cambiar (1 ... ", HANDSIZE, "). Presiona ENTER/ANY cuando estés listo/a");
	
	char c;
	while ((c = getchar()) != EOF && c != '\n' &&
		c >= '1' && c <= HANDSIZE + '0')
	{
		i = atoi(&c);
		player_hand[i - 1].chosen = !player_hand[i - 1].chosen;
		printf("%s%d%s\n", "Selecciona una carta que quieras cambiar (1 ... ", HANDSIZE, "). Presiona ENTER/ANY cuando estés listo/a");
		printf("%s", "Ya escogidas: ");

		for (i = 0; i < HANDSIZE; i++)
			if (player_hand[i].chosen)
				printf("%d, ", i + 1);
		printf("%c", '\n');
		getchar(); // skip newline
	}
	
	for (i = 0; i < HANDSIZE; i++)
		if (player_hand[i].chosen) {
			int card_i = get_card(deck);
			if (card_i == -1) {
				fprintf(stderr, "%s", "The deck ran out of cards. (unintended behavior)");
				return -1;
			}
			player_hand[i].type = deck[card_i].type;
			player_hand[i].value = deck[card_i].value;
			player_hand[i].chosen = false;
		}


	// BEGIN COMPARISON OF YOUR CARDS AND ENEMY'S. THE ONE WITH MORE POINTS WINS THE ROUND.

	return 0;
}

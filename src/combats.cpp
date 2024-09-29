#include "../include/cards.hpp"
#include "../include/cutscenes.hpp"
#include "../include/utils.hpp"
#include "../include/combats.hpp"

bool tutorial() {
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
	print_dialogue("DANIEL: Cada uno tiene una mano aleatoria de cartas.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("DANIEL: Tienes que fijarte en que tengas varias cartas del mismo tipo, y/o con el mismo número.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	example_hand[0] = {0, 3, 0};
	example_hand[1] = {0, 12, 0};
	print_cards(example_hand, 2, true);
	print_dialogue("DANIEL: Por ejemplo, si tienes 2 cartas con el mismo tipo, se considera una pareja.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	example_hand[0] = {3, 11, 0};
	example_hand[1] = {1, 11, 0};
	print_cards(example_hand, 2, true);
	print_dialogue("DANIEL: Pero si tienen el mismo número, es una pareja especial, y vale más prestigio.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("DANIEL: Ya que tienes tus cartas, puedes decidir si cambiar algunas de ellas, o no.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("DANIEL: Por supuesto, con el riesgo de que te toquen cartas peores. Pero solo puedes cambiarlas una vez.");
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
	print_dialogue("DANIEL: Ahora es momento de revelar cuantos puntos tiene cada uno.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("DANIEL: El que tenga más puntos se queda con esa misma cantidad de prestigio del rival.");
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
	print_dialogue("DANIEL: El que tenga más puntos se queda con esa misma cantidad de prestigio del rival.");
	enter();

	return (points < enemy_points) ? true : false;
}

bool first_combat() {

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
	print_dialogue("DANIEL: Cada uno tiene una mano aleatoria de cartas.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("DANIEL: Tienes que fijarte en que tengas varias cartas del mismo tipo, y/o con el mismo número.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	example_hand[0] = {0, 3, 0};
	example_hand[1] = {0, 12, 0};
	print_cards(example_hand, 2, true);
	print_dialogue("DANIEL: Por ejemplo, si tienes 2 cartas con el mismo tipo, se considera una pareja.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	example_hand[0] = {3, 11, 0};
	example_hand[1] = {1, 11, 0};
	print_cards(example_hand, 2, true);
	print_dialogue("DANIEL: Pero si tienen el mismo número, es una pareja especial, y vale más prestigio.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("DANIEL: Ya que tienes tus cartas, puedes decidir si cambiar algunas de ellas, o no.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("DANIEL: Por supuesto, con el riesgo de que te toquen cartas peores. Pero solo puedes cambiarlas una vez.");
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
	print_dialogue("DANIEL: Ahora es momento de revelar cuantos puntos tiene cada uno.");
	enter();

	clear();
	print_rcards(HANDSIZE);
	print_cards(player_hand, HANDSIZE, true);
	print_dialogue("DANIEL: El que tenga más puntos se queda con esa misma cantidad de prestigio del rival.");
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
	print_dialogue("DANIEL: El que tenga más puntos se queda con esa misma cantidad de prestigio del rival.");
	enter();

	return (points < enemy_points) ? true : false;


}
#include <iostream>
#include "include/utils.hpp"
#include "include/engine.hpp"
#include "include/combats.hpp"
#include "include/cutscenes.hpp"

char first_character_matrix[HEIGHT_SCREEN][WIDTH_SCREEN];
char second_character_matrix[HEIGHT_SCREEN][WIDTH_SCREEN];
char dialog_matrix[HEIGHT_SCREEN][WIDTH_SCREEN];

int main() {
	initialize_matrix(first_character_matrix);
	initialize_matrix(second_character_matrix);
	initialize_matrix(dialog_matrix);

	clear();
	process_title("assets/configuration-screen_1");
	refresh(2000);
	process_title("assets/configuration-screen_2");
	enter

	clear();
	process_title("assets/title_screen_1.txt");
	refresh(2000);
	process_title("assets/title_screen_2.txt");
	enter

	clear();
	process_prologue(dialog_matrix, 2);

	clear();
	refresh(1000);

	for (int i = 3; i <= 19; i++) {
		process_prologue(dialog_matrix, i);
	}

	clear();
	process_dialog_scene("assets/daniel/daniel_r", 20, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_l", 21, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/daniel/daniel_r", 22, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/daniel/daniel_o_r", 23, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_o_l", 24, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/daniel/daniel_o", 25, 'd', second_character_matrix, dialog_matrix);

	if (tutorial()) {
		process_dialog_scene("assets/daniel/daniel_r", 26, 'd', second_character_matrix, dialog_matrix);
	}
	else {
		process_dialog_scene("assets/daniel/daniel_r", 27, 'd', second_character_matrix, dialog_matrix);
	}

	refresh(3600);
	process_dialog_scene("assets/daniel/daniel_o_r", 28, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);

	for (int i = 29; i <= 33; i++) {
		process_prologue(dialog_matrix, i);
	}

	refresh(3600);
	process_dialog_scene("assets/el-general/el-general", 34, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_o", 35, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/el-general/el-general", 36, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary", 37, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/el-general/el-general", 38, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/el-general/el-general_o", 39, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_o", 40, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/el-general/el-general", 41, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);

	// HERE STARTS THE FIRST FIGHT
	scombat(false, "EL GENERAL: Sabes, no llegue hasta aqui perdiendo partidas.", "EL GENERAL: Veamos que tienes...", "el General");
	process_dialog_scene("assets/el-general/el-general", 42, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);

	for (int i = 43; i <= 58; i++) {
		process_prologue(dialog_matrix, i);
	}

	refresh(3600);
	process_dialog_scene("assets/roberto/roberto", 59, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_o", 60, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto", 61, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);

	for (int i = 62; i <= 63; i++) {
		process_prologue(dialog_matrix, i);
	}

	refresh(3600);
	process_dialog_scene("assets/roberto/roberto", 64, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_o", 65, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto", 66, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);


	for (int i = 67; i <= 70; i++) {
		process_prologue(dialog_matrix, i);
	}

	refresh(3600);
	process_dialog_scene("assets/prisioners/prisioner-1", 71, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/prisioners/prisioner-1", 72, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_o", 73, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/prisioners/prisioner-1", 74, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/prisioners/prisioner-1", 75, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);

	for (int i = 76; i <= 78; i++) {
		process_prologue(dialog_matrix, i);
	}

	if (combat("MARCELO: Vas a caer, mierda.", "MARCELO: Veamos que sacaste...", "Marcelo"))
		process_dialog_scene("assets/prisioners/prisioner-1", 79, 'd', second_character_matrix, dialog_matrix);
	else 
		process_dialog_scene("assets/prisioners/prisioner-1", 80, 'd', second_character_matrix, dialog_matrix);

	refresh(3600);

	if (combat("PEPE: Ahora si te voy a partir, vas a ver.", "PEPE: Adivina adivinador...", "Pepe"))
		process_dialog_scene("assets/prisioners/prisioner-2", 81, 'd', second_character_matrix, dialog_matrix);
	else
		process_dialog_scene("assets/prisioners/prisioner-2", 82, 'd', second_character_matrix, dialog_matrix);

	refresh(3600);

	if (combat("SERGIO: No hay manera de que puedas conmigo.", "SERGIO: Que cartas tienes...", "Sergio"))
		process_dialog_scene("assets/prisioners/prisioner-3", 83, 'd', second_character_matrix, dialog_matrix);
	else
		process_dialog_scene("assets/prisioners/prisioner-3", 84, 'd', second_character_matrix, dialog_matrix);

	refresh(3600);

	if (combat("LUCAS: De esta no te escapas.", "LUCAS: Veamos que cartas sacaste...", "Lucas"))
		process_dialog_scene("assets/prisioners/prisioner-4", 85, 'd', second_character_matrix, dialog_matrix);
	else
		process_dialog_scene("assets/prisioners/prisioner-4", 86, 'd', second_character_matrix, dialog_matrix);

	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_r", 87, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_o_r", 88, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_l", 89, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_o_l", 90, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_r", 91, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_o_r", 92, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);

	for (int i = 93; i <= 97; i++) {
		process_prologue(dialog_matrix, i);
	}

	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_r", 98, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_l", 99, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_r", 100, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_o_r", 101, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_o", 102, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_o_r", 103, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_r", 104, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_l", 105, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_r", 106, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_o_r", 107, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_r", 108, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_o_r", 109, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_o_l", 110, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_r", 111, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_o_r", 112, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);

	for (int i = 113; i <= 114; i++) {
		process_prologue(dialog_matrix, i);
	}

	refresh(3600);
	process_dialog_scene("assets/alejandro-baas/alejandro_baas", 115, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/alejandro-baas/alejandro_baas", 116, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary", 117, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/alejandro-baas/alejandro_baas_r", 118, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_l", 119, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);

	// HERE STARTS THE SIXTH FIGHT
	if (!combat("ALEXANDRA BAAS: No va a ser normal esta humillacion.", "ALEXANDRA BAAS: jajajaja...", "Baas")) {
		process_title("assets/game_over");
		return 0;
	}
	refresh(3600);

	for (int i = 120; i <= 124; i++) {
		process_prologue(dialog_matrix, i);
	}

	refresh(3600);
	process_dialog_scene("assets/prisioners/prisioner-5", 125, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);

	for (int i = 126; i <= 128; i++) {
		process_prologue(dialog_matrix, i);
	}

	refresh(3600);
	process_dialog_scene("assets/la-vaca/la-vaca", 129, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_o_l", 130, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/la-vaca/la-vaca", 131, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/la-vaca/la-vaca_o", 132, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_l", 133, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/la-vaca/la-vaca", 134, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/la-vaca/la-vaca_o", 135, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/la-vaca/la-vaca", 136, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/la-vaca/la-vaca_o", 137, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_l", 138, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/la-vaca/la-vaca", 139, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/la-vaca/la-vaca_o", 140, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);

	// HERE STARTS THE SEVENTH FIGHT
	if (!combat("LA VACA: Que comience el juego!", "LA VACA: La vida o la muerte, que sera?", "La Vaca")) {
		process_title("assets/game_over");
		refresh(3600);
		return 0;
	}

	for (int i = 141; i <= 142; i++) {
		process_prologue(dialog_matrix, i);
	}

	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_l", 143, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_r", 144, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_l", 145, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/roberto/roberto_o_l", 146, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);

	for (int i = 147; i <= 149; i++) {
		process_prologue(dialog_matrix, i);
	}

	refresh(3600);
	process_dialog_scene("assets/arantxa/arantxa_l", 150, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_o_r", 151, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/arantxa/arantxa_l", 152, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_r", 153, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/arantxa/arantxa", 154, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/arantxa/arantxa_o", 155, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary", 156, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);

	for (int i = 157; i <= 160; i++) {
		process_prologue(dialog_matrix, i);
	}

	// HERE STARTS THE EIGHTHT FIGHT
	if (!combat("ARANTXA: Te voy a destruir.", "ARANTXA: penoso...", "Arantxa")) {
		process_title("assets/game_over");
		refresh(3600);
		return 0;
	}

	for (int i = 161; i <= 168; i++) {
		process_prologue(dialog_matrix, i);
	}

	refresh(3600);
	process_dialog_scene("assets/jueza/jueza", 169, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary", 170, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/jueza/jueza", 171, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/el-general/el-general", 172, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/el-general/el-general", 173, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/jueza/jueza", 174, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/jueza/jueza", 175, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/el-general/el-general", 176, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_o", 177, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/jueza/jueza", 178, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);

	// HERE STARTS THE NINTH FIGHT
	if (!combat("JUEZA: Una mocosa como tu no le va a ganar al gran general.", "GENERAL: ...", "el general")) {
		process_title("assets/game_over");
		refresh(3600);
		return 0;
	}

	refresh(3600);
	process_dialog_scene("assets/el-general/el-general", 179, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/mary/mary_o", 180, 'd', first_character_matrix, dialog_matrix);
	refresh(3600);
	process_dialog_scene("assets/jueza/jueza", 181, 'd', second_character_matrix, dialog_matrix);
	refresh(3600);

	for (int i = 182; i <= 184; i++) {
		process_prologue(dialog_matrix, i);
	}

	return 0;
}

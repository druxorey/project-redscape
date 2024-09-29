#include <iostream>
#include <string>
#include "include/cutscenes.hpp"
#include "include/cards.hpp"
#include "include/utils.hpp"
#include "include/engine.hpp"
#include "include/combats.hpp"

char first_character_matrix[HEIGHT_SCREEN][WIDTH_SCREEN];
char second_character_matrix[HEIGHT_SCREEN][WIDTH_SCREEN];
char dialog_matrix[HEIGHT_SCREEN][WIDTH_SCREEN];

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

#pragma once

#include <iostream>
#include <string>
#include <cmath>

const int WIDTH_SCREEN = 150;
const int HEIGHT_SCREEN = 49;

// Ininitialize a character array with spaces
void initialize_matrix(char matrix[HEIGHT_SCREEN][WIDTH_SCREEN]);

// Gets the dialog on the line specified by dialog_index from the file '../assets/dialogue.txt'
std::string get_dialog(int dialog_index);

// Gets the contents of a scene file specified by file_location
std::string get_cutscene(std::string file_location);

// Convert a scene text string to a character array
// The scene text string is passed as cutscene and the character array as matrix
void cutscene_to_matrix(const std::string& cutscene, char matrix[HEIGHT_SCREEN][WIDTH_SCREEN]);

// Overwrite the target matrix with the overlay matrix
// '_' characters in overlay_matrix become ' ' in target_matrix
// ' ' characters in overlay_matrix are ignored and do not override the corresponding characters in target_matrix
void overwrite_matrix(char target_matrix[HEIGHT_SCREEN][WIDTH_SCREEN], char overlay_matrix[HEIGHT_SCREEN][WIDTH_SCREEN]);

// Print a character array to the console
// If use_escape_codes is true, escape codes are used to format the text making the background white and the text black
void print_matrix(char matrix[HEIGHT_SCREEN][WIDTH_SCREEN], bool use_escape_codes = false);

// Draw a dialog in a character array
// The dialog is passed as a text string and the position of the dialog is specified with a character ('u' for up, 'm' for middle, 'd' for down)
void draw_dialog(char matrix[HEIGHT_SCREEN][WIDTH_SCREEN], std::string dialog, char position);

// Process a dialogue scene
// The scene is specified with a file, the dialog is obtained with an index, the dialog position is specified with a character
// The principal_matrix and dialog_matrix are used to draw the scene and dialogue
// If use_escape_codes is true, escape codes are used to format the text making the background white and the text black
void process_dialog_scene(const std::string& scene_file, int dialog_index, char dialog_position, char principal_matrix[HEIGHT_SCREEN][WIDTH_SCREEN], char dialog_matrix[HEIGHT_SCREEN][WIDTH_SCREEN], bool use_escape_codes = false);

// Process a visual scene
// The scene is specified with a file and the parentMatrix is used to draw the scene
// If use_escape_codes is true, escape codes are used to format the text making the background white and the text black
void process_visual_scene(const std::string& scene_file, char principal_matrix[HEIGHT_SCREEN][WIDTH_SCREEN], bool use_escape_codes = false);

// Process a prologue scene
void process_prologue(char dialog_matrix[HEIGHT_SCREEN][WIDTH_SCREEN], char main_matrix[HEIGHT_SCREEN][WIDTH_SCREEN], int dialog_index);


/* MAIN EXAMPLE

int main() {
	refresh(1000);
	char matrix[HEIGHT_SCREEN][WIDTH_SCREEN];
	char overlay_matrix[HEIGHT_SCREEN][WIDTH_SCREEN];

	while (true) {
        process_dialog_scene("../assets/main-frame_1.txt", 1, 'd', matrix, overlay_matrix);
        refresh(2500);
        process_dialog_scene("../assets/main-frame_2.txt", 2, 'd', matrix, overlay_matrix);
        refresh(2500);
        process_dialog_scene("../assets/main-frame_3.txt", 3, 'd', matrix, overlay_matrix);
        refresh(3000);
        process_dialog_scene("../assets/main-frame_3.txt", 3, 'd', matrix, overlay_matrix);
        refresh(2000);
        process_visual_scene("../assets/main-frame_3.txt", matrix);
        refresh(2000);
        process_visual_scene("../assets/main-frame_4.txt", matrix, true);
        refresh(250);
        process_dialog_scene("../assets/main-frame_4.txt", 4, 'd', matrix, overlay_matrix);
        refresh(3000);
	}

    return 0;
}

*/

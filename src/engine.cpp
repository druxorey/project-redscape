#include <iostream>
#include <string>
#include <cmath>
#include "engine.hpp"

std::string get_dialog(int dialog_index) {
    FILE* file = fopen("../assets/dialogue.txt", "r");
	char line[128];
    int target_line = dialog_index, current_line = 0;

    if (file) {
        while (fgets(line, sizeof(line), file)) {
            current_line++;
            if (current_line == target_line) {
                return line;
            }
        }
        fclose(file);
    } else {
		return "Unable to open file";
    }

    return "Line not found";
}


std::string get_cutscene(std::string file_location) {
    FILE* file = fopen(file_location.c_str(), "r");
    std::string content;
    char c;

    if (file) {
        while ((c = fgetc(file)) != EOF) {
            content += c;
        }
        fclose(file);
        return content;
    } else {
		return "Unable to open file";
    }
}


void cutscene_to_matrix(const std::string& cutscene, char matrix[HEIGHT_SCREEN][WIDTH_SCREEN]) {
    int row = 0, column = 0;

	for (char actual_character : cutscene) {
		if (actual_character == '\n') {
			++row;
			column = 0;
		} else {
			if (column < WIDTH_SCREEN) {
				matrix[row][column] = actual_character;
				++column;
			}
		}
	}
}


void overwrite_matrix(char target_matrix[HEIGHT_SCREEN][WIDTH_SCREEN], char overlay_matrix[HEIGHT_SCREEN][WIDTH_SCREEN]) {
	for(int i = 0; i < HEIGHT_SCREEN; i++) {
		for(int j = 0; j < WIDTH_SCREEN; j++) {
			if (overlay_matrix[i][j] == '_') {
				target_matrix[i][j] = ' ';
			} else if (overlay_matrix[i][j] != ' ') {
				target_matrix[i][j] = overlay_matrix[i][j];
			}
		}
	}
}


void print_matrix(char matrix[HEIGHT_SCREEN][WIDTH_SCREEN], bool use_escape_codes) {
    for(int vertical = 0; vertical < HEIGHT_SCREEN; vertical++) {
        for(int horizontal = 0; horizontal < WIDTH_SCREEN; horizontal++) {
            std::string output;
            if (vertical == 0 && horizontal == 0)
                output = "╔";
            else if (vertical == HEIGHT_SCREEN - 1 && horizontal == WIDTH_SCREEN - 1)
                output = "╝";
            else if (vertical == 0 && horizontal == WIDTH_SCREEN - 1)
                output = "╗";
            else if (vertical == HEIGHT_SCREEN - 1 && horizontal == 0)
                output = "╚";
            else if (vertical == 0 || vertical == HEIGHT_SCREEN - 1)
                output = "═";
            else if (horizontal == 0 || horizontal == WIDTH_SCREEN - 1)
                output = "║";
            else if (matrix[vertical][horizontal] == '{')
                output = "╋";
            else if (matrix[vertical][horizontal] == '}')
                output = "━";
            else if (matrix[vertical][horizontal] == '/')
                output = "┃";
            else
                output = matrix[vertical][horizontal];

            if (use_escape_codes)
                std::cout << "\033[30;47m" << output << "\033[0m";
            else
                std::cout << output;
        }
        std::cout << std::endl;
    }
}


void draw_dialog(char matrix[HEIGHT_SCREEN][WIDTH_SCREEN], std::string dialog, char position) {
    int position_height, dialog_length = dialog.length();
	int padding = (WIDTH_SCREEN - dialog_length) / 2;

	switch (position) {
		case 'u':
			position_height = 2;
			break;
		case 'm':
			position_height = 24;
			break;
		case 'd':
			position_height = 42;
			break;
		default:
			position_height = 24;
			break;
	}

    for (int i = 0; i < HEIGHT_SCREEN; i++) {
        for (int j = 0; j < WIDTH_SCREEN; j++) {
            matrix[i][j] = ' ';
        }
    }

	for (int vertical = position_height; vertical < 5 + position_height; vertical++) {
		for (int horizontal = 8; horizontal < WIDTH_SCREEN - 8; horizontal++) {
			
			if ((vertical == position_height && (horizontal == 8 || horizontal == WIDTH_SCREEN - 9)) || (vertical == 4 + position_height && (horizontal == 8 || horizontal == WIDTH_SCREEN - 9))) {
				matrix[vertical][horizontal] = '{';
			} else if (vertical == position_height || vertical == 4 + position_height) {
				matrix[vertical][horizontal] = '}';
			} else if (horizontal == 8 || horizontal == WIDTH_SCREEN - 9) {
				matrix[vertical][horizontal] = '/';
			} else {
				matrix[vertical][horizontal] = '_';
			}
		}
	}

	for (int horizontal = padding; horizontal < dialog_length + padding; horizontal++) {
		if (horizontal - padding < dialog_length - 1) {
			matrix[position_height + 2][horizontal] = dialog[horizontal - padding];
		}
	}

}


void process_dialog_scene(const std::string& scene_file, int dialog_index, char dialog_position, char principal_matrix[HEIGHT_SCREEN][WIDTH_SCREEN], char dialog_matrix[HEIGHT_SCREEN][WIDTH_SCREEN], bool use_escape_codes) {
    std::string screen = get_cutscene(scene_file);
    cutscene_to_matrix(screen, principal_matrix);

    std::string dialog = get_dialog(dialog_index);
    draw_dialog(dialog_matrix, dialog, dialog_position);
    overwrite_matrix(principal_matrix, dialog_matrix);
    print_matrix(principal_matrix, use_escape_codes);
}


void process_visual_scene(const std::string& scene_file, char principal_matrix[HEIGHT_SCREEN][WIDTH_SCREEN], bool use_escape_codes) {
    std::string screen = get_cutscene(scene_file);
    cutscene_to_matrix(screen, principal_matrix);
    print_matrix(principal_matrix, use_escape_codes);
}

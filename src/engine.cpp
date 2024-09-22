#include <iostream>
#include <string>
#include "../include/utils.hpp"

const int WIDTH_SCREEN = 150;
const int HEIGHT_SCREEN = 49;

std::string get_dialog(int dialog) {
    FILE* file = fopen("dialogue.txt", "r");
	char line[256];
    int targetLine = dialog;
    int currentLine = 0;

    if (file) {
        while (fgets(line, sizeof(line), file)) {
            currentLine++;
            if (currentLine == targetLine) {
                return line;
            }
        }
        fclose(file);
    } else {
        std::cout << "Unable to open file";
    }

    return 0;
}

std::string get_screen(std::string fileLocation) {
    FILE* file = fopen(fileLocation.c_str(), "r");
    std::string content;
    char c;

    if (file) {
        while ((c = fgetc(file)) != EOF) {
            content += c;
        }
        fclose(file);
        return content;
    } else {
        std::cout << "Unable to open file";
        return "";
    }
}


void print_screen() {
	for (int vertical = 0; vertical < HEIGHT_SCREEN; vertical++) {
		for (int horizontal = 0; horizontal < WIDTH_SCREEN; horizontal++) {
			if (vertical == 0 || vertical == HEIGHT_SCREEN - 1 || horizontal == 0 || horizontal == WIDTH_SCREEN - 1) {
				std::cout << "#";
			} else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}


void string_to_matrix(const std::string& file, char matrix[HEIGHT_SCREEN][WIDTH_SCREEN]) {
    int row = 0, column = 0;

	for (char actual_character : file) {
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


void write_matrix(char matrix[HEIGHT_SCREEN][WIDTH_SCREEN], char object[HEIGHT_SCREEN][WIDTH_SCREEN]) {
	for(int i = 0; i < HEIGHT_SCREEN; i++) {
		for(int j = 0; j < WIDTH_SCREEN; j++) {
			if (object[i][j] == '?') {
				matrix[i][j] = ' ';
			} else if (object[i][j] != ' ') {
				matrix[i][j] = object[i][j];
			}
		}
	}
}


void print_matrix(char matrix[HEIGHT_SCREEN][WIDTH_SCREEN]) {
	for(int i = 0; i < HEIGHT_SCREEN; i++) {
		for(int j = 0; j < WIDTH_SCREEN; j++) {
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}
}


void dialog_matrix(char matrix[HEIGHT_SCREEN][WIDTH_SCREEN], std::string dialog, char position) {
	int position_height, dialog_length = dialog.size();
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

	for (int i = position_height; i < 5 + position_height; i++) {
		for (int j = 8; j < WIDTH_SCREEN - 8; j++) {
			if (i == position_height || i == 4 + position_height || j == 8 || j == WIDTH_SCREEN - 9) {
				matrix[i][j] = '#';
			} else {
				matrix[i][j] = '?';
			}
		}
	}

	for (int j = padding; j < dialog_length + padding; j++) {
		if (j - padding < dialog_length -1) {
			matrix[position_height + 2][j] = dialog[j - padding];
		}
	}
}


void refresh(int rate) {
	sleep(rate);
	system("clear");
}


/*
int main() {
	refresh(1000);
	char principalMatrix[HEIGHT_SCREEN][WIDTH_SCREEN];
	char dialog_matrix[HEIGHT_SCREEN][WIDTH_SCREEN];

	while (true) {
		std::string screen = getScreen("main-frame.txt");
		stringToMatrix(screen, principalMatrix);

		std::string salute = getDialog(1);
		dialogMatrix(dialog_matrix, salute, 'd');
		writeMatrix(principalMatrix, dialog_matrix);
		printMatrix(principalMatrix);

		std::cin.get();
		refresh(1000);

		salute = getDialog(2);
		dialogMatrix(dialog_matrix, salute, 'm');
		writeMatrix(principalMatrix, dialog_matrix);
		printMatrix(principalMatrix);

		std::cin.get();
		refresh(1000);

		salute = getDialog(3);
		dialogMatrix(dialog_matrix, salute, 'u');
		writeMatrix(principalMatrix, dialog_matrix);
		printMatrix(principalMatrix);

		std::cin.get();
		refresh(1000);
	}

    return 0;
}
*/

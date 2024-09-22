#pragma once
#include <iostream>
#include <string>
#include "../include/utils.hpp"

const int WIDTH_SCREEN = 150;
const int HEIGHT_SCREEN = 49;

// Function to get a dialog from a file
std::string get_dialog(int dialog);

// Function to get a cutscene from a file
std::string get_screen(std::string fileLocation);

// Function to print a default blanck screen
void print_screen();

// This function converts a string into a matrix, the string has to have the same dimensions as the matrix, actually serve to get the cutscenes
void string_to_matrix(const std::string& file, char matrix[HEIGHT_SCREEN][WIDTH_SCREEN]);

// This function writes the object matrix into the screen matrix
void write_matrix(char matrix[HEIGHT_SCREEN][WIDTH_SCREEN], char object[HEIGHT_SCREEN][WIDTH_SCREEN]);

// This function prints the screen matrix
void print_matrix(char matrix[HEIGHT_SCREEN][WIDTH_SCREEN]);

// This function prints a dialog in the screen matrix
void dialog_matrix(char matrix[HEIGHT_SCREEN][WIDTH_SCREEN], std::string dialog, char position);

// better way to clear the screen and waiting a certain time
void refresh(int rate);

#pragma once
#include <iostream>

// sleeps for the given miliseconds.
void sleep(int miliseconds);

// clears the screen.
void clear();

// reads the standard input until a newline character is found.
#define enter while (getchar() != '\n');

// refreshes the screen at the given rate.
void refresh(int rate);


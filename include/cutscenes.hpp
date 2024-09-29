#pragma once
#include <iostream>

// max size of the width of the screen, must be a positive value.
#define MAXLINE 200

// a scene, consists of an image (a directory to an ascii file), and a dialogue.
typedef struct {
	const char *image;
	const char *dialogue;
} scene;

// prints the given file in the screen, returns error codes.
int print_image(const char *dir);

// prints the given dialogue in the half of screen, returns error codes.
int print_dialogue(const char *dialogue);

// prints n scenes of the given cutscene in the screen, returns error codes.
// a cutscene consists of an array of scenes.
int print_cutscene(scene *cutscene, int n);

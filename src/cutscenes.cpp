#include <iostream>
#include "../include/cutscenes.hpp"
#include "../include/utils.hpp"

int print_image(const char *dir) {

	FILE *file = fopen(dir, "r");

	if (file == NULL) {
		fprintf(stderr, "%s%s%c", "Couldn't find the file\"", dir, '"');
		return -1;
	}

	char line[MAXLINE];
	while (fgets(line, MAXLINE, file))
		printf("%s", line);

	fclose(file);
	return 0;
}

int print_dialogue(const char *dialogue) {

	if (dialogue == NULL) {
		fprintf(stderr, "%s", "Couldn't print the dialogue. NULL pointer given.");
		return -1;
	}

	int size = 0;
	while (dialogue[size++])
		if (size > MAXLINE) {
			fprintf(stderr, "%s %d %s", "Couldn't print the dialogue. It must be lesser than", MAXLINE, "characters.");
			return -1;
		}

	int dialog_box_width = 184;
	int box_padding = (MAXLINE - dialog_box_width) / 2;
	int dialog_padding = (MAXLINE - size) / 2;


	printf("%*c%s\n", box_padding, ' ', "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("%*c%s\n", box_padding, ' ', "┃                                                                                                                                                                                      ┃");
	printf("%*c%s", box_padding, ' ',   "┃");

	int i = 0;

	for (; i < dialog_padding - box_padding; i++)
		printf(" ");

	printf("%s", dialogue);
	i += size;

	for (; i < dialog_box_width - 1; i++)
		printf(" ");

	printf("%s\n", "┃");

	printf("        %s\n", "┃                                                                                                                                                                                      ┃");
	printf("        %s",   "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");

	return 0;
}

int print_cutscene(scene *cutscene, int n) {

	for(int i = 0; i < n; i++) {
		clear();
		if (print_image(cutscene[i].image) != -1 && print_dialogue(cutscene[i].dialogue) != -1)
			enter();
		else
			return -1;
	}

	return 0;
}

#include <iostream>
#include "../include/cutscenes.h"

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

	int size = 0;

	while (dialogue[size++])
		if (size > MAXLINE) {
			fprintf(stderr, "%s %d %s", "Couldn't print the dialogue. It must be lesser than", MAXLINE, "characters.");
			return -1;
		}

	printf("\n%*c%s\n", (MAXLINE - size) / 2, ' ', dialogue);
	getchar();

	return 0;
}	

int print_cutscene(scene *cutscene, int n) {

	for(int i = 0; i < n; i++)
		if (print_image(cutscene[i].image) == -1 ||
		print_dialogue(cutscene[i].dialogue) == -1)
			return -1;
	return 0;
}

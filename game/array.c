#include <stdio.h>
#include "game.h"

int readmap(FILE *f)
{
	int c, h, v;

	h = v = 0;
	while ((c = getc(f)) != EOF) {
		if (c == '\n') {
			v++;
			h = 0;
		} else {
			map[v][h++] = c;
		}
	}

	return h * v;
}

void clearmap(void)
{
	int h, v;
	for (v = 0; v < MAPLEN; v++)
		for (h = 0; h < MAPLEN; h++)
			map[v][h] = '\0';
}

void printmap(void)
{
	int h, v;

	clear_screen();
	for (v = 0; map[v][h] != '\0'; v++, h = 0) {
		for (h = 0; map[v][h] != '\0'; h++)
			color(map[v][h]);
		putchar('\n');
	}
}

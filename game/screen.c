#include <stdio.h>
#include "game.h"

void putcharat(struct point locat, int x)
{
	screen_set(locat);
	color(x);
}

int printat(struct point locat, char *fmt)
{
	screen_set(locat);
	return printf("%s",fmt);
}

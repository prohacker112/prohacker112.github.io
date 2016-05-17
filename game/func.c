#include "game.h"
#include <stdlib.h>
#include <time.h>

struct point makepoint(int v, int h)
{
	struct point new;

	new.v = v;
	new.h = h;

	return new;
}

void xwait(int tm)
{
	int x = time(0);
	while ((x + tm) > time(0));
}

void clear(struct point locat)
{
	screen_set(locat);
	printf("\e[0K");
}

int xrand(int max)
{
	srand(time(0));
	return rand() % max;
}

#include <stdio.h>
#include "game.h"

void init(void)
{
	MESSAGE = makepoint(20,1);
	STAT_1 = makepoint(10,100);
	STAT_2 = makepoint(11,100);
	PLAYER.icon = PLAYER_DEFAULT_ICON;
	PLAYER.start = makepoint(17,2);
	PLAYER.current = PLAYER.start;
	PLAYER.level = 1;
	PLAYER.name = "Adventurer";
}

int main(void)
{
	init();
	intro();

	FILE *mapfile = fopen("maps/map.dat","r");
	readmap(mapfile);
	printmap();

	putcharat(PLAYER.start,PLAYER.icon);

	printat(MESSAGE,"You wake up in a dark cave with a light far off in the distance...");
	screen_set(makepoint(50,100));
	move();
	clear(MESSAGE);
	printf("Have a nice day!\n");
	return 0;
}

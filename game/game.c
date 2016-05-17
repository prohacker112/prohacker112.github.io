#include "game.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int intro(void)
{
	clear_screen();
	stdin_set();

	if (!access(".monster.dat",R_OK)) {
		printf("Restore saved game? [yn] ");
		if (getchar() != 'y')
			return 0;
		FILE *dat = fopen(".monster.dat","r");
		fscanf(dat,"%d,%d:%d,%d",&PLAYER.current.v,&PLAYER.current.h,&PLAYER.xp,&PLAYER.level);
		return 1;
	}
	FILE *dat = fopen(".monster.dat","r");
	clear_screen();
	printf("%s*%s Poof. %s*%s\n",TEXT_YELLOW,ATTR_RESET,TEXT_YELLOW,ATTR_RESET);
	xwait(2);
	printf("That was weird.\n");
	xwait(2);
	printf("You wake up in a dark cave with a light far off in the distance...\n");
	xwait(3);
	printf("You have no recollection of your past life, only a strong desire to rid the world of evil.\n");
	xwait(3);
	printf("Without having any other knowledge, you know that you need to defeat all of the evil mosters that\n");
	xwait(1);
	printf("riddle the countryside of Mountain Valley.\n");
	xwait(3);
	printf("\n\nWin all of the 7 battles to complete the game!\n");
	xwait(4);

	return 0;
}

void drown(void)
{
	clear(MESSAGE);
	printat(MESSAGE,"You fall under the water! ");
	getchar();
	clear(MESSAGE);
	printat(MESSAGE,"You gasp... ");
	getchar();
	clear(MESSAGE);
	printat(MESSAGE,"You choke... ");
	getchar();
	clear(MESSAGE);
	printat(MESSAGE,"You fall under... ");
	getchar();
	death("drowning");
}

void death(char *type)
{
	clear(MESSAGE);
	printat(MESSAGE,"You died!");
	clear_screen();
	xwait(3);
	printf("We are here tonight to mourn for the tragic loss of a great adventurer.\n");
	xwait(4);
	printf("%s was everything an adventurer was supposed to be... Strong, brave, fearless...\n",PLAYER.name);
	xwait(4);
	printf("%s's stats were: %d XP, level %d.\n",PLAYER.name,PLAYER.xp,PLAYER.level);
	xwait(4);
	printf("But he kicked the bucket a few hours ago - death by %s. Goodbye, everyone. Pray for %s's soul!\n\n\n",type,PLAYER.name);
	xwait(2);
	printf("Press any key to continue.\n");
	getchar();
	clear_screen();
	printat(MESSAGE,"Have a nice day!\n");
	stdin_reset();
	exit(EXIT_SUCCESS);
}

void rename_player(void)
{
	char buf[100];

	stdin_reset();
	printat(MESSAGE,"Enter new player name: ");
	fgets(buf,100,stdin);
	buf[strlen(buf)-1]=0;
	PLAYER.name = &buf;
	stdin_set();
}

void print_stats(void)
{
	screen_set(STAT_1);
	printf("Player: %s",PLAYER.name);
	screen_set(STAT_2);
	printf("XP: %d, Level %d",PLAYER.xp,PLAYER.level);
}

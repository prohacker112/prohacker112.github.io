#include <signal.h>
#include "game.h"

// movement works with WASD config and Vi keys HJKL

void _move(int x)
{
	struct point temp = PLAYER.current;

	switch(x) {
	case 'h': // left
	case 'a': PLAYER.current.h--;	break;
	case 'l': // right
	case 'd': PLAYER.current.h++;	break;
	case 'k': // up
	case 'w': PLAYER.current.v--;	break;
	case 'j': // down
	case 's': PLAYER.current.v++;	break;
	}

	if (moveto(PLAYER.current))
		reprint(temp);
	else
		PLAYER.current = temp;  // reset
}

short int moveto(struct point locat)
{
	register int x = map_coord(locat);
	// wall.
	if (x == '#') {
		printat(MESSAGE,"Ouch!");
		return 0;
	// mountain.
	} else if (x == '^') {
		if (PLAYER.level < 7)
			printat(MESSAGE,(xrand(2) == 1) ? "That terrain is too rough!":"You'll get lost out there!");
		else
			return 1;
		return 0;
	// tall grass.
	} else if (x == '"') {
		printat(MESSAGE,(xrand(5) == 3) ? "A voice whispers in the grass: Stay on the path...":"You rustle through the tall grass.");
	// grass.
	} else if (x == '-') {
		printat(MESSAGE,(xrand(4) == 3) ? "Swish swish.":"");
	// swamp.
	} else if (x == '=') {
		if (xrand(4) == 1) {
			int i, j = xrand(8);
			printat(MESSAGE,"You are stuck! ");
			for (i = 0; i < j; i++)
				getchar();
		} else {
			printat(MESSAGE,(xrand(3) == 2) ? "You move freely through the mud.":"");
		}
	// forest.
	} else if (x == ')') {
		printat(MESSAGE,(xrand(4) == 2) ? "Whack. Whack. You fight your way through the dense jungle.":"");
	// river.
	} else if (x == '~') {
		printat(MESSAGE,(xrand(2) == 1) ? "Are you sure you want to do that? ":"Confirm that, would you? ");
		if (getchar() == 'y') {
			clear(MESSAGE);
			if (xrand(3) == 2)
				drown();
			else
				printat(MESSAGE,(xrand(2) == 1) ? "Splish splosh.":"You splash through the stream.");
		} else {
			clear(MESSAGE);
			printat(MESSAGE,"You decide to stay on land, safe and dry.");
			return 0;
		}
	}
	return 1;
}

void _chloc(register int place)
{
	FILE *map;
	switch(place) {
	case ARENA_1: map = fopen("maps/arena_1.dat","r");
		      PLAYER.current = makepoint(5,1);
		      break;
	case ARENA_2: map = fopen("maps/arena_2.dat","r");
		      PLAYER.current = makepoint(7,2);
		      break;
	case ARENA_3: map = fopen("maps/arena_3.dat","r");
		      PLAYER.current = makepoint(8,1);
		      break;
	case ARENA_4: map = fopen("maps/arena_4.dat","r");
		      PLAYER.current = makepoint(2,5);
		      break;
	case ARENA_5: map = fopen("maps/arena_5.dat","r");
		      PLAYER.current = makepoint(2,2);
		      break;
	case ARENA_6: map = fopen("maps/arena_6.dat","r");
		      PLAYER.current = makepoint(12,1);
		      break;
	case ARENA_7: map = fopen("maps/arena_7.dat","r");
		      PLAYER.current = makepoint(7,2);
		      break;
	case ASCENSION: map = fopen("maps/ascension.dat","r");
		      PLAYER.current = makepoint(9,20);
		      break;
	}
	clearmap();
	readmap(map);
	printmap();
}

void chloc(register int place, struct point locat)
{
	register int coord = map_coord(locat);
	if (place == COUNTRY) {
		switch(coord) {
		case '1': _chloc(ARENA_1);	break;
		case '2': _chloc(ARENA_2);	break;
		case '3': _chloc(ARENA_3);	break;
		case '4': _chloc(ARENA_4);	break;
		case '5': _chloc(ARENA_5);	break;
		case '6': _chloc(ARENA_6);	break;
		case '7': _chloc(ARENA_7);	break;
		}
	} else if ((place >= ARENA_1) && (place <= ARENA_7)) {
		if (coord == '%')
			_chloc(ASCENSION);
		else
			_chloc(COUNTRY);
	}
}

// just ignore the signal given.
void exit_handle(int sig)
{
	signal(sig,SIG_IGN);
}

void move(void)
{
	int x;
	// ignore signals like ^C, ^Z
	struct sigaction act;
	act.sa_handler = exit_handle;
	sigaction(SIGINT,&act,NULL);

	stdin_set();
	while (1) {
		x = getchar();
		clear(MESSAGE);
		if (x == 'q') {
			printat(MESSAGE,"Really quit the game? ");
			if (getchar() == 'y')
				break;
		} else if (x == 'r') {
			rename_player();
		} else {
			_move(x);
		}
		print_stats();
		putcharat(PLAYER.current,PLAYER.icon);
		screen_set(makepoint(50,100));
	}
	stdin_reset();
}

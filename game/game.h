/* game.h
 * definitions of everything needed in monster map
 * and 'extern' declarations
 */
#include <stdio.h>
#include <string.h>
#include "terminfo.h"
#include "color.h"

#define MAPLEN 100
#define PLAYER_DEFAULT_ICON '@'

struct point {
	int v;
	int h;
};

struct point MESSAGE;
struct point STAT_1;
struct point STAT_2;
struct point STAT_3;
struct point STAT_4;

struct player {
	char *name, icon;
	struct point start, current, previous;
	int level, xp;
} PLAYER;

char map[MAPLEN][MAPLEN];

// map constants
enum {
	ARENA_1 = 1,
	ARENA_2,
	ARENA_3,
	ARENA_4,
	ARENA_5,
	ARENA_6,
	ARENA_7,
	ASCENSION,
	COUNTRY = 10
};

// screen macros
#define screen_set(x)  printf("\e[%d;%dH",(x).v,(x).h)
#define clear_screen() printf("\e[1;1H\e[2J")
#define reprint(x)     putcharat(x,map[(x).v-1][(x).h-1])
#define map_coord(x)   map[(x).v-1][(x).h-1]

// game.c functions
extern void drown(void);
extern void death(char *);
extern int intro(void);
extern void rename_player(void);
extern void print_stats(void);

// func.c functions
extern struct point makepoint(int, int);
extern int xrand(int);
extern void clear(struct point);
extern void xwait(int);

// array.c functions
extern int readmap(FILE *);
extern void clearmap(void);
extern void printmap(void);

// screen.c functions
extern void putcharat(struct point, int);
extern int printat(struct point, char *);

// color macros
#define set_color(x) printf(x);

// color.c functions
extern void color(char);
extern void printchar(char);

// stdin.c functions
extern void stdin_set(void);
extern void stdin_reset(void);

// move.c functions
extern short int moveto(struct point);
extern void exit_handle(int);
extern void _move(int);
extern void move(void);

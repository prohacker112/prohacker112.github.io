#include "game.h"
#include "color.h"

void color(char c)
{
	switch(c) {
		case '#': printf(TEXT_ORANGE "#"  ATTR_RESET);	break;
		case '@': printf(TEXT_RED    "@"  ATTR_RESET);	break;
		case '"': printf(TEXT_YELLOW "\"" ATTR_RESET);	break;
		case '-': printf(TEXT_LGREEN "-"  ATTR_RESET);	break;
		case '=': printf(TEXT_GREEN  "="  ATTR_RESET);	break;
		case '.': printf(TEXT_ORANGE "."  ATTR_RESET);	break;
		case '~': printf(TEXT_BLUE   "~"  ATTR_RESET);	break;
		case ')': printf(TEXT_GREEN  ")"  ATTR_RESET);  break;
		default:  putchar(c);
	}
}

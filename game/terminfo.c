#include <sys/ioctl.h>

int terminfo(int x)
{
	struct winsize sz;
	ioctl(1,TIOCGWINSZ,&sz);
	
	switch(x) {
	case 'r': return sz.ws_row;
	case 'c': return sz.ws_col;
	default:  return -1;
	}
}

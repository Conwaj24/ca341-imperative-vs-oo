//the following code is part of umenu (https://github.com/JCoMcL/umenu), whixh is owned by me
//see licence (https://raw.githubusercontent.com/JCoMcL/umenu/master/LICENSE)

#include <stdio.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

#define RED(s) "\e[91m" s "\e[39m"

void die(const char *s) {
	if(s) { fprintf(stderr, RED("%s\n"), s);}
	exit(1);
}

char getUserInput(void) {
	/* reopen stdin for user input */
	if (freopen("/dev/tty", "r", stdin) == NULL) {
		die("Can't reopen tty.");
	}
	
	struct termios tio_old;
	tcgetattr(0, &tio_old);
	struct termios tio_new = tio_old;
	/* disable unwanted attributes */
	tio_new.c_lflag &= ~(
		ICANON| //reads input per line rather than per character
		ECHO //echoes the typed input
	); 
	tio_new.c_cc[VMIN]=1; //require minimum of 1 char

	tcsetattr(0, TCSANOW, &tio_new);

	char c;
	read(0, &c, 1);
	tcsetattr(0, TCSANOW, &tio_old);
	return c;
}

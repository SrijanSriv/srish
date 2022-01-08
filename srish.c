#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "functions/parser.h"
#define EXIT "quit\n"

int main (int argc, char *const argv[]) {
	
	char *line = NULL;
	//char * const filler = " ";
	size_t len = 0;
	ssize_t nread;

	if (argc < 2) {
		printf("\e[48;5;033mWelcome to SRIjan's SHell!\nThis is a project that I decided to do following \"wish\"\n");
		printf("which is explained as a project at Wisconsin Uni\nin Spring '18 by prof. remzi\033[0m\n\n");
		printf("\e[38;5;033msrish> \033[0m");

		while ((nread = getline(&line, &len, stdin)) != -1) {
			if (strcmp(line, EXIT) == 0) {
				exit(0);
			}
			printf("\e[38;5;033msrish> \033[0m");
			printf("%s\n", line);
		}
	} else {
		parser(argc, argv);
		
	}

}

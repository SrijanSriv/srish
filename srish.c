#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "functions/batch.h"
#include "functions/interactive.h"
#define EXIT "exit\n"
#define MAX_PATH 50

int main (int argc, char *const argv[]) {
	
	char *line = NULL;
	//char * const filler = " ";
	size_t len = 0;
	ssize_t nread;

	if (argc < 2) {
		char cwd[MAX_PATH];
		if (getcwd(cwd, sizeof(cwd)) != NULL);
		printf("\e[48;5;033mWelcome to SRIjan's SHell!\033[0m\n");

		printf("srish\e[38;5;033m@%s> \033[0m", cwd);

		while ((nread = getline(&line, &len, stdin)) != -1) {
			if (strcmp(line, EXIT) == 0) {
				exit(0);
			}
			interactive(line, len);
			printf("srish\e[38;5;033m@%s> \033[0m", cwd);
		}
	} else {
		batch(argc, argv);
		
	}
	
	return 0;
}

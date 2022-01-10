#ifndef INTERACTIVE_H
#define INTERACTIVE_H

void interactive (char *line, size_t len) {
	
	int rc = fork();
	char *copy = strdup(line);
	char *path = strdup("/bin/");
	/*char *history[10] = NULL;
	static int historyCounter = 0;*/
	//char *multi = strdup("&&");
	size_t counter = 0;
	int itr = 0;
	if (rc == 0) {
		
		while (*copy != '\0') {
			if (*copy == ' ' || *copy == '\n') {
				++counter;
			}
			++copy;
		}
		char *myargv[counter + 1];
	
		while (itr < counter) {
			myargv[itr] = strsep(&line, " ");
			++itr;
		}
		--counter;
		myargv[0] = strcat(path, myargv[0]);
		myargv[counter] = strsep(&myargv[counter], "\n");
		myargv[++counter] = NULL;
		//history[historyCounter++] = strsep(&line, "\n");
		if (access(myargv[0], F_OK) == 0) {
			execv(myargv[0], myargv);
		} else {
			printf("\e[38;5;033merror:binary %s does not exist\033[0m\n", myargv[0]);
			exit(0);
		}
	} else {
		(int)wait(NULL);
	}

}

#endif

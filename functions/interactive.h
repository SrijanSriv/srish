#ifndef INTERACTIVE_H
#define INTERACTIVE_H

void interactive (char *line, size_t len) {
	//strsep() line, put it in an array, pass that array to execv()
	int rc = fork();
	char *copy = strdup(line);
	char *path = strdup("/bin/");
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
		execv(myargv[0], myargv);
		printf("after execv\n");
	} else {
		(int)wait(NULL);
	}

}

#endif

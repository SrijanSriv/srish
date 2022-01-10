#ifndef BATCH_H
#define BATCH_H

void batch (int argc, char *const line[]) {
	
	int rc = fork();
	char *path = strdup("/bin/");
	if (rc == 0) {
		char  *myargv[argc];
		for (int i = 0; i < argc - 1; i++) {
			if (i == 0) {
				myargv[0] = strcat(path, line[1]);
			} else {
				myargv[i] = strdup(line[i + 1]);
			}
		}
		myargv[argc - 1] = NULL;
		if (access(myargv[0], F_OK) == 0) {
			execv(myargv[0], myargv);
		} else {
			printf("\e[38;5;033merror:binary %s does not exist\033[0m\n", myargv[0]);
			exit(0);
		}
	} else {
		rc = (int)wait(NULL);
	}
}
#endif

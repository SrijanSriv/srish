#ifndef PARSER_H
#define PARSER_H

void parser (int argc, char *const line[]) {
	
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
		execv(myargv[0], myargv);
	} else {
		rc = (int)wait(NULL);
	}
}
#endif

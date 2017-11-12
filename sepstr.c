#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void test(){
	char line[100] = "wow-this-is-cool";
	char *s1 = line;
	printf("[%s]\n", strsep(&s1, "-" ));
	printf("[%s]\n", strsep(&s1, "-" ));
	printf("[%s]\n", strsep(&s1, "-" ));
	printf("[%s]\n", strsep(&s1, "-" ));
	printf("[%s]\n", s1);
}

char ** parse_args( char * line ){
	int ctr = 6;
	int i;

	char ** args = (char **)calloc(ctr, sizeof(char *));

	for(i = 0; line; i++){
	  args[i] = strsep(&line, " ");
	  //	  printf("error: %s\n", strerror(errno));
	  //printf("%s\n", args[i]);
	}
	args[i] = NULL; // null terminate array

	return args;
}

int main(){
	//test();
        char teststr[50] = "ls -a -l";

	char ** args = parse_args( teststr );
	printf("done parsing\n");
	int i = 0;
	printf("printing args...\n");
	for(;i < 4; i++){
		printf("%s	\n", args[i]);
	}
	execvp(args[0], args);

	return 0;
}

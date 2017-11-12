#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
	char * sepped = line;
	int ctr = 5;
	int i;

	char ** args = (char **)calloc(ctr, 256);

	for(i = 0; i < ctr-1; i++){
		printf("Something happened\n");
		sepped = strsep(&sepped, " ");
		printf("Something happened\n");
		args[i] = (char *)malloc(strlen(sepped));
		printf("Something happened\n");
		args[i] = word;
		printf("%s\n", args[i]);
	}
	args[i + 1] = 0;

	return args;
}

int main(){
	//test();

	char ** args = parse_args( "hi how u" );
	printf("Done\n");
	int i = 0;
	for(;i < 4; i++){
		printf("%s	\n", args[i]);
	}
	//execvp(args[0], args);

	return 0;
}

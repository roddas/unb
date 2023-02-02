#include<stdio.h>
#include<stdlib.h>


char **str_split(char *, char);

int main(int argc, char **argv)
{
	char **result = str_split("/usr/bin/mkdir foldername",' ');
	
	puts(result[0]);
	puts(result[1]);
	
	free(result);
	return EXIT_SUCCESS;
}

char **str_split(char *string, char delimiter)
{
	int i = 0,index = 0;
	char **array = (char **)calloc(2,sizeof(char *));
	array[0] = (char *)calloc(127, sizeof(char));
	array[1] = (char *)calloc(127, sizeof(char));
	
	for(; string[i] != delimiter;i++)
		array[0][index++] = string[i];
	
	index = 0;
	++i;
	for(; string[i];i++)
		array[1][index++] = string[i];

	return array;
}

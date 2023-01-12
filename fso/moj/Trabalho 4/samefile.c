#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void combinations(char **,int);
bool compare_files(char *, char *);

int main(int argc, char **argv) {
    combinations(argv,argc);
    return EXIT_SUCCESS;
}

void combinations(char **array,int size){		
	for(int a = 1; a < size -1; a++){
		for(int b = a+1; b < size;b++){
			printf("%s %s %s\n",array[a],array[b],compare_files(array[a],array[b]) ? "iguais" : "diferentes");
		}
	}
}

bool compare_files(char *file1, char *file2) {
    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        return false;
    }

    int ch1, ch2;

    do {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);
        if (ch1 != ch2) {
            fclose(fp1);
            fclose(fp2);
            return false;
        }
    } while (ch1 != EOF && ch2 != EOF);

    fclose(fp1);
    fclose(fp2);
    return true;
}

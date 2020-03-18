#define _CRT_SECURE_NO_WARNINGS
#define BLOCK_SIZE 16
#define ROUND 9
#include <stdio.h>
#include <stdlib.h>
#include "round.h"
#include "key.h"
#include "padding.h"

void readFile(const char*, char*);

int main(int argc, char *argv[]) {
	const char* key;
	char* plaintext = NULL;
	char* result = NULL;
	
	if (argc != 3) {
		printf("Usage: ./aes filename key");
		exit(-1);
	}
	
	if (sizeof(key) != 16 && sizeof(key) != 24 && sizeof(key) != 32) {
		printf("AES Key length error");
		exit(-1);
	}
	
	key = argv[2];

	readFile(argv[1], plaintext);


	free(plaintext);
	return 0;
}

void readFile(const char* filename, char* plaintext) {
	FILE *fp = fopen(filename, "rb");
	unsigned long size;

	if (fp == NULL)
		perror("Error during opening file");

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	plaintext = (char *)malloc(fp + 1);
	fgets(plaintext, size, fp);
}
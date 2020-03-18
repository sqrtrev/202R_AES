#define _CRT_SECURE_NO_WARNINGS
#define BLOCK_SIZE 16
#define ROUND 9
#include <stdio.h>
#include "round.h"
#include "key.h"
#include "padding.h"

void readFile(const char*, char*);

int main(int argc, char *argv[]) {
	const char* key;
	char* plaintext;
	char* result;
	
	if (argc != 3) 
		perror("Usage: ./aes filename key");
	
	if (sizeof(key) != 16 && sizeof(key) != 24 && sizeof(key) != 32) 
		perror("AES Key length error");
	
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
	size = fteel(fp);
	fseek(fp, 0, SEEK_SET);
	
	plaintext = (char *)malloc(fp + 1);
	fgets(plaintext, size, fp);
}
#define _CRT_SECURE_NO_WARNINGS
#define ROUND 9
#ifndef BLOCK_SIZE
#define BLOCK_SIZE 16
#endif

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

	printf("%c", InvSubBytes('\x04')); // expected output is 0
	
	/*
	if (argc != 3) {
		fprintf(stderr,"Usage: ./aes filename key");
		exit(-1);
	}
	
	if (sizeof(key) != 16 && sizeof(key) != 24 && sizeof(key) != 32) {
		fprintf(stderr, "AES Key length error");
		exit(-2);
	}
	
	 Now in testing function
	key = argv[2];

	readFile(argv[1], plaintext);


	free(plaintext);
	*/
	return 0;
}

void readFile(const char* filename, char* plaintext) {
	FILE *fp = fopen(filename, "rb");
	unsigned long size;

	if (fp == NULL) {
		fprintf(stderr, "Error during opening file");
		exit(-3);
	}

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	plaintext = (char *)malloc(fp + 1);
	fgets(plaintext, size, fp);
}
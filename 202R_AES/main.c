#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BLOCK_SIZE 16

volatile char* plaintext;
volatile char* result;
void readfile(const char*);


int main(int argc, char *argv[]) {
	const char* key;
	

	if (argc != 3) 
		perror("Usage: ./aes filename key");
	
	if (sizeof(key) != 16 && sizeof(key) != 24 && sizeof(key) != 32) 
		perror("AES Key length error");
	
	key = argv[2];

	readfile(argv[1], plaintext);


	free(plaintext);
	return 0;
}

void readfile(const char* filename) {
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
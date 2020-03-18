#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BLOCK_SIZE 16

int main(int argc, char *argv[]) {
	const char* key;
	char plaintext[129];

	if (argc != 3) {
		printf("Usage: ./aes file_dir key");
		return -1;
	}
	if (sizeof(key) != 16 && sizeof(key) != 24 && sizeof(key) != 32) {
		printf("AES Key length error");
		return -1;
	}
	key = argv[2];

	FILE *f = fopen(argv[1], "rb");
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MAGIC_LEN 12
#define PATCH_LEN 8
char MAGIC[] = {0x00,0x00,0x00,0x14,0x76,0x6D,0x68,0x64,0x00,0x00,0x00,0x01};
char PATCH[] = {0x01,0x04,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

int found_magic_bytes(char *b, int *state){
	if(*state < MAGIC_LEN && *b == MAGIC[*state])
		(*state)++;
	return *state == MAGIC_LEN;
}

int main(int argc, char *argv[]){
	if( argc < 2 ){
		printf("patches an MP4 file to use straightalpha graphics mode in quicktime\nUsage: ./qt-straightalpha movie-to-patch.mp4\n");
		return 1;
	}
	int state = 0;
	char buf[1];
	int fd = open(argv[1], O_RDWR);
	while( read(fd,buf,1) ){
		if( found_magic_bytes(buf, &state) ){
			printf("Patching...\n");
			write(fd,PATCH,PATCH_LEN);
			break;
		}
	}
	return 0;
}
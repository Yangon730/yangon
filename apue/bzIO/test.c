#include <stdio.h>
#include <unistd.h>

int main(int argc ,char *argv[])
{
	FILE *fp ,*fp2;
	int ch;

	fp = fopen(argv[1] , "r");
	if(fp == NULL){
		perror("fopen()");
		return 1;
	}
	fp2 = fopen(argv[2] , "w");
	if(fp == NULL){
		perror("fopen()");
		goto ERROR1;

	}
	while(1){
		ch = fgetc(fp);
		if(ch == EOF){
			if(feof(fp))
				break;
			else
				goto ERROR;
		}
		fputc(ch , fp2);
	}
	fclose(fp2);
	fclose(fp);
	return 0;
ERROR1:
	fclose(fp);
ERROR:
	fclose(fp);
	return 1;
}

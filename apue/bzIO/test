#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc ,char *argv[])
{
	FILE *fp ,*fp2;
	int ch;
	char buf[10];
	int cnt;

	fp = fopen(argv[1] , "r");
	if(fp == NULL){
		perror("fopen()");
		return 1;
	}
	fp2 = fopen(argv[2] , "w");
	while(1){
		cnt = fread(buf , 1 , 10 ,fp);//十个成员每个成员占一个字节
		if(cnt == 0){
			if(feof(fp))
				break;
			goto ERROR;
		}
		fwrite(buf ,1 ,cnt , fp2);
	}
/*	while(1){
	memset(buf , '\0' ,10);
	if(fgets(buf, 10 , fp) == NULL){
		if(feof(fp))
			break;
		goto ERROR;	
		} 
	fputs(buf , stdout);
	sleep(1);
	}
*/
#if 0
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
#endif
	fclose(fp);
	return 0;
ERROR1:
	fclose(fp);
ERROR:
	fclose(fp);
	return 1;
}

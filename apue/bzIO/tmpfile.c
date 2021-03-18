#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define  SIZE 2 
int main(int argc, char *argv[])
{
	FILE *tmp;
	char buf[SIZE];
	int i = 0; 
	int	cnt , len;
	FILE *fp =fopen(argv[1] ,"r+");
	tmp = tmpfile();
	//tmp =fopen(argv[3] ,"w+");
			
	if(NULL == fp){
		perror("fopen()");
		return 1;
	}
	while(1){
		cnt =fread(buf , 1 , 1 , fp);
		if(cnt == 0){
			if(feof(fp))
				break;
			goto ERROR;
		}
		if(i+1 == atoi(argv[2])){
			fwrite(argv[3] , 1 ,strlen(argv[3]), tmp);
			i++;
		}
		fwrite(buf, 1 ,cnt,tmp);
		if(buf[0] == '\n')
		{
			i++;
		}
	}
	rewind(tmp);
	rewind(fp);
	while(1){
		len = fread(buf ,1, 1, tmp);
		if(len == 0){
			if(feof(tmp))
				break;
			goto ERROR;
		}
		fwrite(buf , 1 , len , fp);
	}

		return 0;
ERROR:
		fclose(fp);


}

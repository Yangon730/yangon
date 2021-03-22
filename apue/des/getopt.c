#include <stdio.h>
#include <unistd.h>

int main(int argc ,char *argv[])
{
	int ch;
	while(1){
		ch = getopt(argc ,argv ,"lai:m::" );
		if (-1 == ch)
			break;
		switch(ch){
			case 'l':
				printf("get - l ... \n");
				break;
			case 'a':
				printf("get - a ... \n");
				break;
			case 'i':
				printf("get - i ... \n");
				if(optarg != NULL)
					printf("arg:%s",optarg);
				else
					fprintf(stderr , "required arguments\n");
				break;
			case 'm':
				printf("get - m ...\n");
				if(optarg != NULL)
					printf("arg:%s",optarg);
				break;
			case 1:
				printf("not option argument...\n");//不能识别字符串

				break;
			case '?':
				printf("i dont know\n");
				break;
			default:
				break;
		}
	}

	return 0;


}

#include <stdio.h>
#include <stat.h>
#include <unistd.h>
#include <string.h>
#include <glob.h>

int filestat_l(void)
{
	gilob_t res;
	glob("*", 0, NULL , &res);
	for(int i =0 ; i<res.gl_pathc ; i++){
		manls((res.gl_pathv[i]));
	}
	globfree(&res);
	return 0;
}

int filestat_la(void)
{
	filestat_l();
	gilob_t res;
	glob("*", 0, NULL , &res);
	for(int i =0 ; i<res.gl_pathc ; i++){
		manls((res.gl_pathv[i]));
	}
	globfree(&res);
}

int filestat_li(void)
{
	gilob_t res;
	glob("*", 0, NULL , &res);
	for(int i =0 ; i<res.gl_pathc ; i++){
		manls((res.gl_pathv[i]));
		manll((res.gl_pathv[i]));
	}
	globfree(&res);
	return 0;
}
int filestat_lai(void)
{
	gilob_t res;
	glob("*", 0, NULL , &res);
	glob(".*",GLOB_APPEND ,NULL ,&res);
	for(int i =0 ; i<res.gl_pathc ; i++){
		manls((res.gl_pathv[i]));
		manll((res.gl_pathv[i]));
	}
	globfree(&res);
	return 0;
}
int filestat_ai(void)
{
	gilob_t res;
	glob("*", 0, NULL , &res);
	glob(".*",GLOB_APPEND ,NULL ,&res);
	for(int i =0 ; i<res.gl_pathc ; i++){
		manls((res.gl_pathv[i]));
		puts((res.gl_pathv[i]));
	}
	globfree(&res);
	return 0;
}
int filestat_i(void)
{
	gilob_t res;
	glob("*", 0, NULL , &res);
	
	for(int i =0 ; i<res.gl_pathc ; i++){
		manls((res.gl_pathv[i]));
		puts((res.gl_pathv[i]));
	}
	globfree(&res);
	return 0;
}

int filestat_a(void)
{
	gilob_t res;
	glob("*", 0, NULL , &res);
	glob(".*",GLOB_APPEND ,NULL ,&res);
	for(int i =0 ; i<res.gl_pathc ; i++){
		
		puts((res.gl_pathv[i]));
	}
	globfree(&res);
	return 0;
}

int filestat_Path(char *arr)
{
	gilob_t res;
	strcat(arr,"*");
	glob("*", 0, NULL , &res);
	glob(".*",GLOB_APPEND ,NULL ,&res);
	for(int i =0 ; i<res.gl_pathc ; i++){
		
		puts((res.gl_pathv[i])+strlen(arr)-1);
	}
	globfree(&res);
	return 0;
}
int main(intargc ,char *argv[])
{




}

















































































































	for(int i =0 ; i<res.gl_pathc ; i++){
		manls((res.gl_pathv[i]));
	}
	globfree(&res);
	return 0;
}

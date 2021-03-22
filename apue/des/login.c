#define _XOPEN_SOURCE  
#include <stdio.h>
#include <shadow.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>


//读密码getpass(3)
//crypt(3)加密输入密码
// getspnam(3) 获得系统存储的密码


int main(int argc ,char *argv[])
{
	struct spwd *sp;
	char *pass;
	char *emp;
	if (argc < 2)
    	return 1;
	pass = getpass("密码:");

	sp = getspnam(argv[1]);
	if(NULL == sp){
		perror("getspnam()");
		return 1;
	}
	emp = crypt(pass , sp->sp_pwdp);
	if (NULL == emp)
          return 1;
 
    if (strcmp(sp->sp_pwdp, emp) == 0)
       printf("登录成功\n");
    else
       printf("密码错误\n");



	return 0;

}

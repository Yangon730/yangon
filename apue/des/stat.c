#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
//文件类型
static char fileType(const struct stat res)
{	
	switch (res.st_mode & S_IFMT) {
		case S_IFBLK:  return 'b';        break;
		case S_IFCHR:  return 'c';        break;
		case S_IFDIR:  return 'd';        break;
		case S_IFIFO:  return 'p';        break;
		case S_IFLNK:  return 'l';        break;
		case S_IFREG:  return '-';		  break;
		case S_IFSOCK: return 's';        break;
		default:       return -1 ;        break;
	}

}
//权限
static char *fileMode(const struct stat res)
{
	static char str[10]={'\0'};
	//主权限
	if(res.st_mode &  S_IRUSR)
		str[0] = 'r';
	else
		str[0] = '-';
	if(res.st_mode &  S_IWUSR)
		str[1] = 'w';
	else
		str[1] = '-';
	if(res.st_mode &  S_IXUSR){
		if(res.st_mode & S_ISUID)
			str[2] = 's';
		else 
			str[2] = 'x';
	}
	else
		str[2] = '-';
	//组权限
	if(res.st_mode &  S_IRGRP)
		str[3] = 'r';
	else
		str[3] = '-';
	if(res.st_mode &  S_IWGRP)
		str[4] = 'w';
	else
		str[4] = '-';
	if(res.st_mode &  S_IXGRP){
		if(res.st_mode & S_ISGID)
			str[5] = 's';
		else 
			str[5] = 'x';
	}
	else
		str[5] = '-';
	//other权限
	if(res.st_mode &  S_IROTH)
		str[6] = 'r';
	else
		str[6] = '-';
	if(res.st_mode &  S_IWOTH)
		str[7] = 'w';
	else
		str[7] = '-';
	if(res.st_mode &  S_IXOTH){
		if(res.st_mode & S_ISVTX)
			str[8] = 's';
		else 
			str[8] = 'x';
	}
	else
		str[9] = '-';
	return str;
}
//硬链接数
static long fileLink(const struct stat res)
{
	return res.st_nlink;
}
//用户名
static char *fileUIDname(const struct stat res)
{
	struct passwd *p;
	p = getpwuid(res.st_uid);
	return p->pw_name;
}
//
static char *fileGidname(const struct stat res)
{
	struct group *g;
	g = getgrgid(res.st_gid);
	return g->gr_name;
}
int main(int argc ,char *argv[])
{
	struct stat res;
	if(argc < 2)
		return 1;

	if(stat(argv[1] , &res) == -1){
		perror("stat()");
		return 1;
	}
	printf("%c",fileType(res));
	printf("%s ",fileMode(res));
	printf(" %ld ",fileLink(res));
	printf(" %s ",fileUIDname(res));
	printf(" %s \n",fileGidname(res));

	return 0;


}

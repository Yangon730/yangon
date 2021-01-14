













#include <stdio.h>
int main()
{
 int s;
 printf ("请输入成绩\n");
 scanf("%d",&s);
 
 if(90<=s && s<=100){
 printf("优秀\n");
} else if(80<=s && s<90){
 printf("良好\n");

} else if (70<=s && s<80
)
{
 printf("一般\n");
} else if(60<=s && s<70){
 printf("及格\n");
} else if(0<=s && s<60 ){
 printf("不及格\n");
} else{printf("无效\n");
}
return 0;
}



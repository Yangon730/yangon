#include <stdio.h>
int main (void)
{
	int  arr[5]={1,2,3,4,5};
	printf("arr%p\n",arr);
	printf("arr+1:%p\n",arr+1);
	printf("*(arr+1):%d\n",*(arr+1));
	printf("1[arr]%d\n",1[arr]);
    printf("sizeof(arr):%ld\n",sizeof(arr));
	return 0;
}
/*#include <stdio.h>
  void PrintArr(int arr[])
  {
  int i = 0;
  int* p = arr;
  for (i = 0; i < 10; i++)
  {
  printf("%d ", *(p + i));//指针
  }
  }
  int main()
  {
  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  PrintArr(arr);
  return 0;
  }*/

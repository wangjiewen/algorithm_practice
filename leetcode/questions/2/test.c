#include <stdio.h>
#include <stdlib.h>

// error
// a 是地址,是该函数的局部变量
void fun(int *a)
{
	a = (int*)malloc(sizeof(int));
	*a = 5;
}

// OK
int *fun1(void)
{
	int *a;
	a = (int*)malloc(sizeof(int));
	*a = 5;
	return a;
}

// OK
void fun2(int **a_d)
{
	*a_d = (int*)malloc(sizeof(int));
	**a_d = 5;
}

void fun3(int **a_d)
{
	int *a;
	*a_d = (int*)malloc(sizeof(int));
	a = *a_d;
	*a = 5;
}

int main(void)
{
	int *a;
	//fun(a);
	//a = fun1();
	//fun2(&a);
	fun3(&a);
	printf("%d\n", *a);
	free(a);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int solve(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int num0 = 0;
	int num1 = 1;
	int ret;
	for (int i = 2; i <= n; i++) {
		ret = num0 + num1;
		num0 = num1;
		num1 = ret;
	}
	return ret;
}

int main(void)
{
	int ret = solve(30);
	cout << ret << endl;
	return 0;
}


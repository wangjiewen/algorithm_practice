#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define N 35
int f[N];
int solve(int n) {
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < N; i++) {
		f[i] = f[i-1] + f[i-2];
	}
	return f[n];
}

int main(void)
{
	int ret = solve(30);
	cout << ret << endl;
	return 0;
}


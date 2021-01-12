#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(void)
{
	int loop;

	freopen("in.txt", "r", stdin);	

	scanf("%d", &loop);
	while (loop--) {
		int n, i;
		int mid;
		int out = 9;

		scanf("%d", &n);
		mid = n / 2;
		for (i = 0; i < mid; i++) {
			printf("%d", out);
			out = out - 1 < 0 ? 9 : out - 1;
		}
		for (; i < n; i++) {
			printf("%d", out);
			out = (out + 1) % 10;
		}
		printf("\n");
	}

	return 0;
}

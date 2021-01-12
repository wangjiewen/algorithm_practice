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
		int n;
		int out = 9;

		scanf("%d", &n);

		if (n == 1) {
			printf("9\n");
			continue;
		}

		printf("98");
		for (int i = 2; i < n; i++) {
			printf("%d", out);
			out = (out + 1) % 10;
		}
		printf("\n");
	}

	return 0;
}

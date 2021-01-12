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
		while (n--) {
			printf("%d", out);
			out = out - 1 < 0 ? 9 : out - 1;
		}
		printf("\n");
	}

	return 0;
}

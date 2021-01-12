#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[300005];

bool is_hill(int i)
{
	return arr[i-1] < arr[i] && arr[i+1] < arr[i];
}

bool is_valley(int i)
{
	return arr[i-1] > arr[i] && arr[i+1] > arr[i];
}

int main(void)
{
	int loop;

	freopen("in", "r", stdin);

	scanf("%d", &loop);
	while (loop--) {
		int n;
		int cont = 0, cont_max = 0, ret = 0;

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		for (int i = 1; i < n - 1; i++) {
			if (is_hill(i) || is_valley(i)) {
				ret += 1;
				cont += 1;
			} else {
				cont_max = max(cont, cont_max);
				cont = 0;
			}
		}
		cont_max = max(cont, cont_max);
		cont_max = min(3, cont_max);
		ret = max(ret-cont_max, 0);
		printf("%d\n", ret);
	}
	
	return 0;
}

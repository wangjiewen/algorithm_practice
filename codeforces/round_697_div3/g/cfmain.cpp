#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>

#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

#define N 200005

int a[N];

int main(void)
{
	freopen("in", "r", stdin);

	int loop;
	scanf("%d", &loop);
	while (loop--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		for (int i = 0; i < n; i++) {


		}
	}

	return 0;
}


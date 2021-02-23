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

class UnionFind {
public:
	vector<int> parent;
	int count;

	UnionFind(int n) {
		count = n;
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int index) {
		if (parent[index] != index) {
			parent[index] = find(parent[index]);
		}
		return parent[index];
	}

	void unionSet(int index1, int index2) {
		int root1 = find(index1);
		int root2 = find(index2);
		if (root1 != root2) {
			parent[root1] = root2;
			count -= 1;
		}
	}
};

class Solution {
public:
	inline int getIndex(int x, int y, int n) {
		return 4 * (x * n + y);
	}

	int regionsBySlashes(vector<string>& grid) {
		int n = grid[0].size();
		int size = 4 * n * n;
		class UnionFind uf(size);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int index = getIndex(i, j, n);
				if (grid[i][j] == ' ') {
					uf.unionSet(index, index + 1);
					uf.unionSet(index, index + 2);
					uf.unionSet(index, index + 3);
				} else if (grid[i][j] == '/') {
					uf.unionSet(index, index + 3);
					uf.unionSet(index + 1, index + 2);
				} else if (grid[i][j] == '\\') {
					uf.unionSet(index, index + 1);
					uf.unionSet(index + 2, index + 3);
				}
				if (j + 1 < n)
					uf.unionSet(index + 1, getIndex(i, j+1, n) + 3);
				if (i + 1 < n)
					uf.unionSet(index + 2, getIndex(i+1, j, n));
			}
		}

		return uf.count;
	}

};

int main(void)
{
	Solution s;
	vector<string> grid = {"/\\", "\\/"};
	int ret;

	ret = s.regionsBySlashes(grid);
	cout << ret << endl;

	return 0;
}


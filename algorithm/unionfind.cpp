
class UnionFind {
public:
	vector<int> parent;

	UnionFind(int n) {
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
		parent[find(index2)] = find(index1);
	}
};


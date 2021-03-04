#include <bits/stdc++.h>

using namespace std;

void pr_envlopes(vector<vector<int>> &envelopes)
{
	for (auto env : envelopes) {
		cout << env[0] << ", " << env[1] << endl;
	}
}

void pr_top_prev(vector<int> &prev, vector<int> &top)
{
	cout << "top=" << top[0] << ", " << top[1] << ", prev=" << prev[0] << ", " << prev[1] << endl;
}

bool cmp(const vector<int> &a, const vector<int> &b)
{
	if (a[0] == b[0])
		return a[1] > b[1];
	return a[0] > b[0];
}

class Solution {
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		stack<vector<int>> matryoshka;
		vector<int> top = {INT_MAX, INT_MAX}, prev = {INT_MAX, INT_MAX};

		sort(envelopes.begin(), envelopes.end(), cmp);
		pr_envlopes(envelopes);

		for (int i = 0; i < envelopes.size(); i++) {
			if (envelopes[i][0] < top[0] && envelopes[i][1] < top[1]) {
				prev = top;
				top = envelopes[i];
				matryoshka.push(top);
			} else if (matryoshka.size() > 1 && envelopes[i][0] < top[0] && envelopes[i][1] > top[1]) {
				if (envelopes[i][0] < prev[0] && envelopes[i][1] < prev[1]) {
					matryoshka.pop();
					top = envelopes[i];
					matryoshka.push(top);
				}
			}
		}

		return matryoshka.size();
	}
};

int main(void)
{
	Solution s;
	//vector<vector<int>> envelopes = {{5,4},{6,7},{6,4},{2,3}};
	vector<vector<int>> envelopes = {{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,360},{7,380}};
	//vector<vector<int>> envelopes = {{46,89},{50,53},{52,68},{72,45},{77,81}};

	int ret = s.maxEnvelopes(envelopes);
	cout << ret << endl;

	return 0;
}


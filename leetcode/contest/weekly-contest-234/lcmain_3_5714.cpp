#include <bits/stdc++.h>

using namespace std;

class Solution {
	private:
		map<string, string> km;
		void init_m(vector<vector<string>> &k) {
			for (int i = 0; i < k.size(); i++) {
				km.insert(pair<string, string>(k[i][0], k[i][1]));
			}

			/*
			   for (auto it = km.begin(); it != km.end(); it++) {
			   cout << it->first << ":" << it->second << ",";
			   }
			   cout << endl;
			   */
		}

	public:
		string evaluate(string s, vector<vector<string>>& knowledge) {
			string ret;

			init_m(knowledge);
			for (int i = 0; i < s.size(); i++) {
				while (i < s.size() && s[i] != '(') {
					ret += s[i];
					i++;
				}
				if (s[i] == '(') {
					i++;
					string key;
					while (s[i] != ')') {
						key += s[i];
						i++;
					}

					if (km.find(key) != km.end()) {
						ret += km[key];
					} else {
						ret += '?';
					}
				}
			}

			return ret;
		}
};
class Solution {
public:

};

int main(void)
{
	Solution s;

	return 0;
}


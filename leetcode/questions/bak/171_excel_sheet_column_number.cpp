class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int mult = 1;
        int len = s.length();
        for(int i = len - 1; i >= 0; i--){
            ans += mult * (s[i] - 'A' + 1);
            mult *= 26;
        }
        return ans;
    }
};

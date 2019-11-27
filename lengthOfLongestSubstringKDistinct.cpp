class Solution {
	map<int,int> h;
public:
	int lengthOfLongestSubstringKDistinct(string s, int K) {
		int ans = 0, unique = 0;
		int low = 0;
		for (int i = 0; i < s.size(); i++) {
			int idx = s[i] - 'a';
			if (h[idx]++ == 0)unique++;
			while (unique > K) {
				idx = s[low++] - 'a';
				if (--h[idx] == 0)unique--;
			}
			ans = max(ans, i - low + 1);
		}
		return ans;
	}
};
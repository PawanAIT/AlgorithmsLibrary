class Solution {
private:
	int start = 0, end = 0;
	void expand(int i, int j, string& s) {
		while (i >= 0 && j < s.size() && s[i] == s[j])i--, j++;
		if (j - i - 1 > end - start + 1) {
			end = j - 1, start = i + 1;
		}
	}
public:
	string longestPalindrome(string s) {
		int ans = 0;
		for (int i = 0; i + 1 < s.size(); i++) {
			expand(i, i, s);
			expand(i, i + 1, s);
		}
		return s.substr(start, end - start + 1);
	}
};
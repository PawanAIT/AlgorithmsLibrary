class Solution {
private:
	vector<string> mapping = vector<string>({ "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" });
	vector<string> ans;
	void addCombinations(string& s, int index, string foo) {
		if (index == s.size()) {
			ans.push_back(foo);
			return;
		}
		for (int i = 0; i < mapping[s[index] - '0'].size(); i++) {
			addCombinations(s, index + 1, foo + mapping[s[index] - '0'][i]);
		}
	}
public:
	vector<string> letterCombinations(string digits) {
        if(digits.size())
		addCombinations(digits, 0, "");
		return ans;
	}
};
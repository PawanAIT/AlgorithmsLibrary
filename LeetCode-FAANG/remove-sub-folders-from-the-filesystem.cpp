class Solution {
private:
	bool startsWith(string &a, string &b) {
		for (int i = 0; i < min(a.size(), b.size()); i++) {
			if (a[i] != b[i])
				return false;
		}
		return true;
	}
public:
	vector<string> removeSubfolders(vector<string>& folder) {
		sort(folder.begin(), folder.end());
		vector<string> ans;
		if (folder.empty())
			return ans;
		ans.push_back(folder[0]);
		for (int i = 1; i < folder.size(); i++) {
			string last = ans.back() + "/";
			if (!startsWith(folder[i], last)) {
				ans.push_back(folder[i]);
			}
		}
		return ans;
	}
};
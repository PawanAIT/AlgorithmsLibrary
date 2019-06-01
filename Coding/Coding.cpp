#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
	vector<string> ans;
	vector<string> generateParenthesis(int n) {
		int l(n), r(n);
		string s = "";
		generate(l, r, s);
		return ans;
	}
	void generate(int l, int r, string s) {
		if (l == 0 and r == 0) {
			ans.push_back(s);
		}
		if (l <= r) {
			if (l) {
				generate(l - 1, r, s + '(');
			}

			if (r) {
				generate(l, r - 1, s + ')');
			}
		}
	}
};

int main() {
	Solution solution;
	for (auto i : solution.generateParenthesis(3)) {
		cout << i << endl;
	}		
}
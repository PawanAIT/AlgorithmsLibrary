// Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.
// Example 1:
// Input: 
// s = "abcxyz123"
// dict = ["abc","123"]
// Output:
// "<b>abc</b>xyz<b>123</b>"
// Example 2:
// Input: 
// s = "aaabbcc"
// dict = ["aaa","aab","bc"]
// Output:
// "<b>aaabbc</b>c"
// Note:
// The given dict won't contain duplicates, and its length won't exceed 100.
// All the strings in input have length in range [1, 1000].

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<pair<int, int>> ranges = findpairs(s, dict);
        ranges = merge(ranges);
        for (auto it = ranges.rbegin(); it != ranges.rend(); it++) {
            s.insert(it->second, "</b>");
            s.insert(it->first, "<b>");
        }
        return s;
    }

private:
    vector<pair<int, int>> findpairs(string s, vector<string>& dict) {
        vector<pair<int, int>> res;
        for (string w : dict) {
            int n = w.size();
            for (int i = 0; (i = s.find(w, i)) != string::npos; i++) {
                res.push_back(pair<int, int>(i, i + n));
            }
        }
        return res;
    }

    vector<pair<int, int>> merge(vector<pair<int, int>>& a) {
        vector<pair<int, int>> r;
        sort(a.begin(), a.end(), compare);
        for (int i = 0, j = -1; i < a.size(); i++) {
            if (j < 0 || a[i].first > r[j].second) {
                r.push_back(a[i]);
                j++;
            }
            else {
                r[j].second = max(r[j].second, a[i].second);
            }
        }
        
        return r;
    }

    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first || a.first == b.first && a.second < b.second;
    }
};
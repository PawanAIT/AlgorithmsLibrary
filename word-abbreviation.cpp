// Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.

// Begin with the first character and then the number of characters abbreviated, which followed by the last character.
// If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
// If the abbreviation doesn't make the word shorter, then keep it as original.
// Example:
// Input: ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
// Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
// Note:
// Both n and the length of each word will not exceed 400.
// The length of each word is greater than 1.
// The words consist of lowercase English letters only.
// The return answers should be in the same order as the original array.

class Solution {
private:
    struct TrieNode {
        int count;
        vector<TrieNode*> nexts;
        TrieNode() : count(0) {nexts.resize(26, NULL);}
    };

    void insert(TrieNode* root, string& s) {
        TrieNode* cur = root;
        for (char& c : s) {
            if (!(cur->nexts)[c-'a']) cur->nexts[c-'a'] = new TrieNode();
            cur = cur->nexts[c-'a'];
            ++cur->count;
        }
    }

    int query(TrieNode* root, string& s) {
        int n = s.size();
        TrieNode* cur = root;
        for (int i = 0; i < n; ++i) {
            cur = cur->nexts[s[i]-'a'];
            if (cur->count == 1) return i;
        }
        return n;
    }
    
    void releaseTrie(TrieNode* root){
        if(!root) return;
        for(auto &p : root->nexts) releaseTrie(p);
        delete(root);
    }
    
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<string> res(n);
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            string& s = dict[i];
            int len = s.size();
            if (len <= 3) res[i] = s;
            else {
                string abbr = s[0] + to_string(len-2) + s[len-1];
                m[abbr].push_back(i);
                res[i] = abbr;
            }
        }
        
        for (auto& p : m) {
            if (p.second.size() <= 1) continue;
            TrieNode* root = new TrieNode();
            for (int i : p.second) insert(root, dict[i]);
            for (int i : p.second) {
                int len = dict[i].size();
                int j = query(root, dict[i]);
                if (j >= len-3) res[i] = dict[i];
                else res[i] = dict[i].substr(0, j+1) + to_string(len-2-j) + dict[i][len-1];
            }
            releaseTrie(root);
        }
        return res;
    }
};
#include "bits/stdc++.h"
using namespace std;

const int ALPHABET_SIZE = 26; 

// trie node 
struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 

	// isEndOfWord is true if the node represents 
	// end of a word 
	bool isEndOfWord; 
}; 

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 

	pNode->isEndOfWord = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	// mark last node as leaf 
	pCrawl->isEndOfWord = true; 
} 

// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

class Solution {
public:
    string S;
    vector<int> dp;
    bool go(int index, TrieNode *root)
    {
        TrieNode *copyRoot = root;
        if (index == S.size())
            return 1;
        if (dp[index] != -1)
            return dp[index];
        dp[index] = false;
        for (int i = index ; i < S.size(); i++) 
        {
            if (root->children[S[i] - 'a'] != NULL)
            {
                root = root->children[S[i] - 'a'];
                // if(root->isEndOfWord)
                //     cout << i << "\n";
                if (root->isEndOfWord && go(i + 1, copyRoot)){
                  
                    return dp[index] = true;
                }
                 
            }
            else{
                return false;
            }
        }
        return dp[index];
}
  bool wordBreak(string s, vector<string>& keys) 
    {
        S = s;
        dp.resize(s.size() + 1);
        fill(dp.begin(), dp.end(), -1);
        struct TrieNode *root = getNode(); 
        for (int i = 0; i < keys.size(); i++) 
            insert(root, keys[i]);
        return go(0, root);
    }
};

int main(){
    string s = "leetcode";
    vector<string> v({"leet","code"});
    Solution sol;
    cout << sol.wordBreak(s, v);
}
// "cbca"
// ["bc","ca"]


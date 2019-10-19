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


class Solution 
{
public:
    bool wordBreak(string s, vector<string>& keys) 
    {
        struct TrieNode *root = getNode(); 

        for (int i = 0; i < keys.size(); i++) 
            insert(root, keys[i]);

        vector<int> dp(s.size() + 1);
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int index = q.front();
            q.pop();
            if (index == s.size())
                return true;
            TrieNode *pRoot = root;
            for (int i = index; i < s.size(); i++)
            {
                int key = s[i] - 'a';
                if (pRoot->children[key] != NULL)
                {
                    pRoot = pRoot->children[key];
                    if (pRoot != NULL && pRoot->isEndOfWord)
                    {
                        if(dp[i + 1] == false)
                            q.push(i + 1);
                        dp[i + 1] = true;
                    }
                }
                else
                {
                    break;
                }
            }
        }
            return dp[s.size()];
    }
};

int main(){
    string s = "abcd";
    vector<string> v({"a","abc","b","cd"});
    Solution sol;
    cout << sol.wordBreak(s, v);
}

// "abcd"
// ["a","abc","b","cd"]
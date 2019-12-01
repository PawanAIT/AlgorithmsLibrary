// A string such as "word" contains the following abbreviations:

// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
// Given a target string and a set of strings in a dictionary, find an abbreviation of this target string with the smallest possible length such that it does not conflict with abbreviations of the strings in the dictionary.

// Each number or letter in the abbreviation is considered length = 1. For example, the abbreviation "a32bc" has length = 4.

// Note:
// In the case of multiple answers as shown in the second example below, you may return any one of them.
// Assume length of target string = m, and dictionary size = n. You may assume that m ≤ 21, n ≤ 1000, and log2(n) + m ≤ 20.
// Examples:
// "apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")

// "apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include "ap3", "a3e", "2p2", "3le", "3l1").

The key idea of my solution is to preprocess the dictionary to transfer all the words to bit sequences (int):
Pick the words with same length as target string from the dictionary and compare the characters with target. If the characters are different, set the corresponding bit to 1, otherwise, set to 0.
Ex: "abcde", ["abxdx", "xbcdx"] => [00101, 10001]

The problem is now converted to find a bit mask that can represent the shortest abbreviation, so that for all the bit sequences in dictionary, mask & bit sequence > 0.
Ex: for [00101, 10001], the mask should be [00001]. if we mask the target string with it, we get "****e" ("4e"), which is the abbreviation we are looking for.

To find the bit mask, we need to perform DFS with some optimizations. But which bits should be checked? We can perform "or" operation for all the bit sequences in the dictionary and do DFS for the "1" bits in the result.
Ex: 00101 | 10001 = 10101, so we only need to take care of the 1st, 3rd, and 5th bit.

Here is a C++ implementation, the running time should be about 3ms. Any suggestions would be appreciated.

class Solution {
    int n, cand, bn, minlen, minab;
    vector<int> dict;
    
    // Return the length of abbreviation given bit sequence
    int abbrLen(int mask) {
        int count = 0;
        for (int b = 1; b < bn;) {
            if ((mask & b) == 0)
                for (; b < bn and (mask & b) == 0; b <<= 1);
            else b <<= 1;
            count ++;
        }
        return count;
    }

    // DFS backtracking
    void dfs(int bit, int mask) {
        int len = abbrLen(mask);
        if (len >= minlen) return;
        bool match = true;
        for (auto d : dict) {
            if ((mask & d) == 0) {
                match = false;
                break;
            }
        }
        if (match) {
            minlen = len;
            minab = mask;
        }
        else
            for (int b = bit; b < bn; b <<= 1)
                if (cand & b) dfs(b << 1, mask + b);
    }

public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        n = target.size(), bn = 1 << n, cand = 0, minlen = INT_MAX;
        string res;
        
        // Preprocessing with bit manipulation
        for (auto w : dictionary) {
            int word = 0;
            if (w.size() != n) continue;
            for (int i = n-1, bit = 1; i >= 0; --i, bit <<= 1)
                if (target[i] != w[i]) word += bit;
            dict.push_back(word);
            cand |= word;
        }
        dfs(1, 0);

        // Reconstruct abbreviation from bit sequence
        for (int i = n-1, pre = i; i >= 0; --i, minab >>= 1) {
            if (minab & 1) {
                if (pre-i > 0) res = to_string(pre-i) + res;
                pre = i - 1;
                res = target[i] + res;
            }
            else if (i == 0) res = to_string(pre-i+1) + res;
        }
        return res;
    }
};
UPDATE: a better way to determine the length of abbreviation mentioned by @StefanPochmann

int abbrLen(int mask) {
    int count = n;
    for (int b = 3; b < bn; b <<= 1)
        if ((mask & b) == 0)
            count --;
    return count;
}
// Given a set of words (without duplicates), find all word squares you can build from them.

// A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

// For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

// b a l l
// a r e a
// l e a d
// l a d y
// Note:
// There are at least 1 and at most 1000 words.
// All words will have the exact same length.
// Word length is at least 1 and at most 5.
// Each word contains only lowercase English alphabet a-z.
// Example 1:

// Input:
// ["area","lead","wall","lady","ball"]

// Output:
// [
//   [ "wall",
//     "area",
//     "lead",
//     "lady"
//   ],
//   [ "ball",
//     "area",
//     "lead",
//     "lady"
//   ]
// ]

// Explanation:
// The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
// Example 2:

// Input:
// ["abat","baba","atan","atal"]

// Output:
// [
//   [ "baba",
//     "abat",
//     "baba",
//     "atan"
//   ],
//   [ "baba",
//     "abat",
//     "baba",
//     "atal"
//   ]
// ]

// Explanation:
// The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        n = words[0].size();
        square.resize(n);
        for (string word : words)
            for (int i=0; i<n; i++)
                fulls[word.substr(0, i)].push_back(word);
        build(0);
        return squares;
    
    }
    int n;
    unordered_map<string, vector<string>> fulls;
    vector<string> square;
    vector<vector<string>> squares;
    void build(int i) {
        if (i == n) {
            squares.push_back(square);
            return;
        }
        string prefix;
        for (int k=0; k<i; k++)
            prefix += square[k][i];
        for (string word : fulls[prefix]) {
            square[i] = word;
            build(i + 1);
        }
    }
};
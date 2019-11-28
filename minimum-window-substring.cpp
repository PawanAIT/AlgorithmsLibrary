// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// Example:

// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:

// If there is no such window in S that covers all characters in T, return the empty string "".
// If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

class Solution {
const int MaxHashSize = 257;

bool IsCornerCase(string& text, string& pattern) {
	if (text.size() < pattern.size()) // pattern is bigger than text itself
		return true;
	
	if (pattern == "" || text == "")
		return true;

	return false;
}
public:
string minWindow(string text, string pattern) {
	if (IsCornerCase(text,pattern))
		return "";

	int patternHash[MaxHashSize] = {0};
	int rollingHash[MaxHashSize] = {0};

	for (auto& i : pattern) // count rakh lo poore pattern ka.
		patternHash[i]++;

	int leftptr = 0;
	int kitteCharacterPatternMeinAaye = 0;
	int MinStartIndex = 0, MinEndIndex = INT_MAX;

	for (int i = 0; i < text.size(); i++) {
		char ch = text[i];
		 
		rollingHash[ch]++;

		if (patternHash[ch] != 0 and rollingHash[ch] <= patternHash[ch]) { // koi character , jo pattern mein aaya ho , magar uske recurrence se jyada ho to count mat karo.
			kitteCharacterPatternMeinAaye++;
		}

		if (kitteCharacterPatternMeinAaye == pattern.size()) { // window mili , magar minimum nahi hai.
			char ch = text[leftptr];
			while (rollingHash[ch] > patternHash[ch] || patternHash[ch] == 0) { // window choti karo , jabtak pattern ke characters se jyada hai.
				rollingHash[ch]--;
				leftptr++;
				ch = text[leftptr];
			}
			if (MinEndIndex - MinStartIndex > i - leftptr) { // sabse min window utha lo.
				MinStartIndex = leftptr;
				MinEndIndex = i;
			}
		}
	}
	
	if (kitteCharacterPatternMeinAaye != pattern.size())
		return "";
	int len = MinEndIndex - MinStartIndex + 1;
	return text.substr(MinStartIndex, len);
}
};
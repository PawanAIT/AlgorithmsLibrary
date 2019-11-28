// Given a rows x cols screen and a sentence represented by a list of non-empty words, find how many times the given sentence can be fitted on the screen.

// Note:

// A word cannot be split into two lines.
// The order of words in the sentence must remain unchanged.
// Two consecutive words in a line must be separated by a single space.
// Total words in the sentence won't exceed 100.
// Length of each word is greater than 0 and won't exceed 10.
// 1 ≤ rows, cols ≤ 20,000.

// Input:
// rows = 3, cols = 6, sentence = ["a", "bcd", "e"]

// Output: 
// 2

// Explanation:
// a-bcd- 
// e-a---
// bcd-e-

// The character '-' signifies an empty space on the screen.

public int wordsTyping(String[] sentence, int rows, int cols) {
    String s = String.join(" ", sentence) + " ";
    int len = s.length(), count = 0;
    int[] map = new int[len];
    for (int i = 1; i < len; ++i) {
        map[i] = s.charAt(i) == ' ' ? 1 : map[i-1] - 1;
    }
    for (int i = 0; i < rows; ++i) {
        count += cols;
        count += map[count % len];
    }
    return count / len;
}
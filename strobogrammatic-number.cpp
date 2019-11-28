// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

// Write a function to determine if a number is strobogrammatic. The number is represented as a string.

// Example 1:

// Input:  "69"
// Output: true
// Example 2:

// Input:  "88"
// Output: true
// Example 3:

// Input:  "962"
// Output: false

public boolean isStrobogrammatic(String num) {
    for (int i=0, j=num.length()-1; i <= j; i++, j--)
        if (!"00 11 88 696".contains(num.charAt(i) + "" + num.charAt(j)))
            return false;
    return true;
}
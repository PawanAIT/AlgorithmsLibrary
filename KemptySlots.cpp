// You have N bulbs in a row numbered from 1 to N. Initially, all the bulbs are turned off. We turn on exactly one bulb everyday until all bulbs are on after N days.
// You are given an array bulbs of length N where bulbs[i] = x means that on the (i+1)th day, we will turn on the bulb at position x where i is 0-indexed and x is 1-indexed.
// Given an integer K, find out the minimum day number such that there exists two turned on bulbs that have exactly K bulbs between them that are all turned off.
// If there isn't such day, return -1.

// Input: 
// bulbs: [1,3,2]
// K: 1
// Output: 2
// Explanation:
// On the first day: bulbs[0] = 1, first bulb is turned on: [1,0,0]
// On the second day: bulbs[1] = 3, third bulb is turned on: [1,0,1]
// On the third day: bulbs[2] = 2, second bulb is turned on: [1,1,1]
// We return 2 because on the second day, there were two on bulbs with one off bulb between them.

public int kEmptySlots(int[] flowers, int k) {
    int[] days = new int[flowers.length];
    for (int i = 0; i < days.length; i++) {
        days[flowers[i] - 1] = i + 1;
    }
    int left = 0;
    int right = k + 1;
    int res = Integer.MAX_VALUE;
    for (int i = 1; right < days.length; i++) {
        // current days[i] is valid, continue scanning
        if (days[i] > days[left] && days[i] > days[right]) {
            continue;
        }
       // reach boundary of sliding window, since previous number are all valid, record result  
        if (i == right) {
            res = Math.min(res, Math.max(days[left],days[right]));
        }
        // not valid, move the sliding window
        left = i;
        right = left + k + 1;
    }
    return res == Integer.MAX_VALUE ? -1 : res;
}
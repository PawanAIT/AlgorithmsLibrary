// Given two 1d vectors, implement an iterator to return their elements alternately.

// Example:

// Input:
// v1 = [1,2]
// v2 = [3,4,5,6] 

// Output: [1,3,2,4,5,6]

// Explanation: By calling next repeatedly until hasNext returns false, 
//              the order of elements returned by next should be: [1,3,2,4,5,6].
// Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

// Clarification for the follow up question:
// The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example:

// Input:
// [1,2,3]
// [4,5,6,7]
// [8,9]

// Output: [1,4,8,2,5,9,3,6,7].

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size() != 0)
            Q.push(make_pair(v1.begin(), v1.end()));
        if (v2.size() != 0)
            Q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        vector<int>::iterator it = Q.front().first;
        vector<int>::iterator endIt = Q.front().second;
        Q.pop();
        if (it + 1 != endIt)
            Q.push(make_pair(it+1, endIt));
        return *it;
    }

    bool hasNext() {
        return !Q.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> Q;
};
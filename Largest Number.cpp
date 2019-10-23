class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(auto x : nums){
            ans.push_back(to_string(x));
        }
        sort(ans.begin(), ans.end(), 
             [&](string &a, string &b){
                 return a + b > b + a;
             });
        string s;
        for(auto x : ans){
            s += x;
        }
        string zero(s.size(), '0');
        return s == zero ? "0" : s;
    }
};
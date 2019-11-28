// Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#'). For each character they type except '#', you need to return the top 3 historical hot sentences that have prefix the same as the part of sentence already typed. Here are the specific rules:

// The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
// The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same degree of hot, you need to use ASCII-code order (smaller one appears first).
// If less than 3 hot sentences exist, then just return as many as you can.
// When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
// Your job is to implement the following functions:

// The constructor function:

// AutocompleteSystem(String[] sentences, int[] times): This is the constructor. The input is historical data. Sentences is a string array consists of previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record these historical data.

// Now, the user wants to input a new sentence. The following function will provide the next character the user types:

// List<String> input(char c): The input c is the next character typed by the user. The character will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in your system. The output will be the top 3 historical hot sentences that have prefix the same as the part of sentence already typed.

 
// Example:
// Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2])
// The system have already tracked down the following sentences and their corresponding times:
// "i love you" : 5 times
// "island" : 3 times
// "ironman" : 2 times
// "i love leetcode" : 2 times
// Now, the user begins another search:

// Operation: input('i')
// Output: ["i love you", "island","i love leetcode"]
// Explanation:
// There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored.

// Operation: input(' ')
// Output: ["i love you","i love leetcode"]
// Explanation:
// There are only two sentences that have prefix "i ".

// Operation: input('a')
// Output: []
// Explanation:
// There are no sentences that have prefix "i a".

// Operation: input('#')
// Output: []
// Explanation:
// The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search.

 
// Note:

// The input sentence will always start with a letter and end with '#', and only one blank space will exist between two words.
// The number of complete sentences that to be searched won't exceed 100. The length of each sentence including those in the historical data won't exceed 100.
// Please use double-quote instead of single-quote when you write test cases even for a character input.
// Please remember to RESET your class variables declared in class AutocompleteSystem, as static/class variables are persisted across multiple test cases. Please see here for more details.

class AutocompleteSystem {
    unordered_map<string, int> dict;
    string data;

public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < times.size(); i++)
            dict[sentences[i]] += times[i];
        data.clear();
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            dict[data]++;
            data.clear();
            return {};
        }

        data.push_back(c);
        auto cmp = [](const pair<string, int> &a, const pair<string, int> &b) {
            return a.second > b.second || a.second == b.second && a.first < b.first;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);

        for (auto &p : dict) {
            bool match = true;
            for (int i = 0; i < data.size(); i++) {
                if (data[i] != p.first[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                pq.push(p);
                if (pq.size() > 3)
                    pq.pop();
            }
        }

        vector<string> res(pq.size());
        for (int i = pq.size() - 1; i >= 0; i--) {
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};

class AutocompleteSystem {
    
    class TrieNode{
        public:
            unordered_map<char, TrieNode*> child;
            string str;
            int count;
            TrieNode(): str(""), count(0) {}
    };
    
    void insert(string& s, TrieNode* root, int times){
        TrieNode* curr = root;
        for (int i=0;i<s.size();i++){
            if (!curr->child.count(s[i]))
                curr->child[s[i]] = new TrieNode();
            curr = curr->child[s[i]];
        }
        curr->count += times;
        curr->str = s;
    }
    
public:
    void dfs(TrieNode* temp){
        if (temp->str != "") q.push({temp->str, temp->count});
        
        for (auto& ele: temp->child){
            dfs(ele.second);
        }
    }
    
    struct comp{
        bool operator() (pair<string, int>& a, pair<string, int>& b){
            return a.second<b.second || a.second==b.second && a.first>b.first;
        }
    };
    
    priority_queue<pair<string, int>, vector<pair<string, int> >, comp> q;
        
    TrieNode* root, *curr;
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        for (int i=0;i<sentences.size();i++){
            insert(sentences[i], root, times[i]);
        }
        curr = root;
    }
    
    
    string s="";
    vector<string> input(char c) {
        q = priority_queue<pair<string, int>, vector<pair<string, int> >, comp>();
        if (c=='#'){
            insert(s, root, 1);
            s="";
            curr = root; //start searching from the beginning node for the next sentence
            return {};
        }
        s += c;
        if (curr && curr->child.count(c)){
            curr = curr->child[c];
        }else{
            curr = NULL; //curr node is null so empty result for any further characters in current input 
            return {};
        }
        
        if (curr->str != "") q.push({curr->str, curr->count});
        for (auto& ele: curr->child){
            dfs(ele.second);
        }
        
        vector<string> res;
        while (!q.empty() && res.size()<3){
            res.push_back(q.top().first);
            q.pop();
        }
        
        return res;
    }
};

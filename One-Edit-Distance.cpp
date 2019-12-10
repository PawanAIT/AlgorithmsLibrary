bool isOneEditDistance(string s, string t) {
    const int m = s.length(), n = t.length();
    if(m < n) return isOneEditDistance(t, s);
    if(s.compare(t) == 0 || m - n > 1) 
        return false;
    int i = 0, j = 0, cnt = 0;
    while(i < m && j < n){
        if(s[i] != t[j]){
            if(++cnt > 1)       //more than one difference 
                return false;
            if(m != n){         //move to the next position
                i++;
                continue;
            }
        }
        i++, j++;
    }
    return true;
}
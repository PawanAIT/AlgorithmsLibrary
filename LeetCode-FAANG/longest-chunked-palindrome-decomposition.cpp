 int longestDecomposition(string S) {
        int res = 0, n = S.length();
        string l = "", r = "";
        for (int i = 0; i < n; ++i) {
            l = l + S[i], r = S[n - i - 1] + r;
            if (l == r)
                ++res, l = "", r = "";
        }
        return res;
    }
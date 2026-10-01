1class Solution {
2public:
3
4    int dp[21][21];
5
6    bool solve(string &s, string &p, int i, int j) {
7
8        // Already calculated
9        if (dp[i][j] != -1)
10            return dp[i][j];
11
12        // Pattern finished
13        if (j == p.length()) {
14            return dp[i][j] = (i == s.length());
15        }
16
17        // Current character matches
18        bool match = (i < s.length() &&
19                     (s[i] == p[j] || p[j] == '.'));
20
21        // Next character is *
22        if (j + 1 < p.length() && p[j + 1] == '*') {
23
24            // 1. * matches zero characters
25            // 2. * matches current character
26            return dp[i][j] =
27                solve(s, p, i, j + 2) ||
28                (match && solve(s, p, i + 1, j));
29        }
30
31        // Normal character or .
32        return dp[i][j] =
33            match && solve(s, p, i + 1, j + 1);
34    }
35
36    bool isMatch(string s, string p) {
37
38        memset(dp, -1, sizeof(dp));
39
40        return solve(s, p, 0, 0);
41    }
42};
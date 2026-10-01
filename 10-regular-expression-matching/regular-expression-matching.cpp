class Solution {
public:

    int dp[21][21];

    bool solve(string &s, string &p, int i, int j) {

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Pattern finished
        if (j == p.length()) {
            return dp[i][j] = (i == s.length());
        }

        // Current character matches
        bool match = (i < s.length() &&
                     (s[i] == p[j] || p[j] == '.'));

        // Next character is *
        if (j + 1 < p.length() && p[j + 1] == '*') {

            // 1. * matches zero characters
            // 2. * matches current character
            return dp[i][j] =
                solve(s, p, i, j + 2) ||
                (match && solve(s, p, i + 1, j));
        }

        // Normal character or .
        return dp[i][j] =
            match && solve(s, p, i + 1, j + 1);
    }

    bool isMatch(string s, string p) {

        memset(dp, -1, sizeof(dp));

        return solve(s, p, 0, 0);
    }
};
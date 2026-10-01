1class Solution {
2public:
3
4    string expand(string s, int left, int right) {
5
6        while (left >= 0 && right < s.length() &&
7               s[left] == s[right]) {
8
9            left--;
10            right++;
11        }
12
13        return s.substr(left + 1, right - left - 1);
14    }
15
16    string longestPalindrome(string s) {
17
18        string ans = "";
19
20        for (int i = 0; i < s.length(); i++) {
21
22            // Odd length palindrome
23            string odd = expand(s, i, i);
24
25            // Even length palindrome
26            string even = expand(s, i, i + 1);
27
28            if (odd.length() > ans.length()) {
29                ans = odd;
30            }
31
32            if (even.length() > ans.length()) {
33                ans = even;
34            }
35        }
36
37        return ans;
38    }
39};
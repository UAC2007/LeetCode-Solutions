1class Solution {
2public:
3    int myAtoi(string s) {
4        int i = 0;
5        int sign = 1;
6        int ans = 0;
7
8        while (i < s.length() && s[i] == ' ')
9            i++;
10
11        if (i < s.length() && s[i] == '-') {
12            sign = -1;
13            i++;
14        }
15        else if (i < s.length() && s[i] == '+') {
16            i++;
17        }
18
19        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
20            int digit = s[i] - '0';
21
22            if (ans > 214748364 || 
23               (ans == 214748364 && digit > 7)) {
24                return sign == 1 ? 2147483647 : -2147483648;
25            }
26
27            ans = ans * 10 + digit;
28            i++;
29        }
30
31        return ans * sign;
32    }
33};
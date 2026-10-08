1class Solution {
2public:
3    int reverse(int x) {
4        int ans = 0;
5
6        while (x != 0) {
7            int digit = x % 10;
8            x = x / 10;
9
10            if (ans > 214748364 || ans < -214748364)
11                return 0;
12
13            if (ans == 214748364 && digit > 7)
14                return 0;
15
16            if (ans == -214748364 && digit < -8)
17                return 0;
18
19            ans = ans * 10 + digit;
20        }
21
22        return ans;
23    }
24};
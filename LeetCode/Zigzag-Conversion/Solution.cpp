1class Solution {
2public:
3    string convert(string s, int numRows) {
4
5        if (numRows == 1 || numRows >= s.length()) {
6            return s;
7        }
8
9        vector<string> rows(numRows);
10
11        int row = 0;
12        int direction = 1;
13
14        for (char c : s) {
15
16            rows[row] += c;
17
18            if (row == 0) {
19                direction = 1;
20            }
21            else if (row == numRows - 1) {
22                direction = -1;
23            }
24
25            row += direction;
26        }
27
28        string result = "";
29
30        for (string r : rows) {
31            result += r;
32        }
33
34        return result;
35    }
36};
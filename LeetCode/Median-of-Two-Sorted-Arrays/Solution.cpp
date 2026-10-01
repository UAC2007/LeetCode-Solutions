1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4
5        // Always binary search on the smaller array
6        if (nums1.size() > nums2.size()) {
7            return findMedianSortedArrays(nums2, nums1);
8        }
9
10        int m = nums1.size();
11        int n = nums2.size();
12
13        int left = 0;
14        int right = m;
15
16        while (left <= right) {
17
18            int cut1 = (left + right) / 2;
19            int cut2 = (m + n + 1) / 2 - cut1;
20
21            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
22            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];
23
24            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
25            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];
26
27            // Correct partition
28            if (left1 <= right2 && left2 <= right1) {
29
30                // Odd total length
31                if ((m + n) % 2 == 1) {
32                    return max(left1, left2);
33                }
34
35                // Even total length
36                return (max(left1, left2) + 
37                        min(right1, right2)) / 2.0;
38            }
39
40            // Move partition left
41            else if (left1 > right2) {
42                right = cut1 - 1;
43            }
44
45            // Move partition right
46            else {
47                left = cut1 + 1;
48            }
49        }
50
51        return 0.0;
52    }
53};
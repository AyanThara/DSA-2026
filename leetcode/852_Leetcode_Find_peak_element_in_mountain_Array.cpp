#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 852 - Peak Index in a Mountain Array

Approach: Binary Search on Mountain Array

Logic:
- The array first increases, then decreases (mountain shape)
- Compare arr[mid] with arr[mid + 1]
    - If arr[mid] < arr[mid + 1], we are on the increasing slope
      → peak lies on the right → move start = mid + 1
    - Else, we are on the decreasing slope or at the peak
      → peak lies at mid or on the left → move end = mid
- Continue until start == end
- At the end, start (or end) points to the peak index

Important Notes:
- Use while(start < end), NOT start <= end (avoids infinite loop / TLE)
- Do NOT use end = mid - 1, because mid itself can be the peak
- Returning start or end both work since start == end at the end

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] < arr[mid + 1]) {
                start = mid + 1;   // move right
            } else {
                end = mid;         // move left or stay at mid
            }
        }

        return start; // same as end
    }
};

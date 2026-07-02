# LeetCode 852 - Peak Index in a Mountain Array
## Intuition
A mountain array first increases and then decreases. The peak element is the highest element where the increasing part changes to decreasing.
Using Binary Search:
* If `arr[mid] < arr[mid + 1]`, we are on the increasing slope, so the peak lies to the right.
* Otherwise, we are on the decreasing slope or at the peak, so the peak lies at `mid` or to the left.
---
## Approach
1. Initialize `start = 0` and `end = n - 1`.
2. Find the middle element.
3. Compare `arr[mid]` with `arr[mid + 1]`.
4. If `arr[mid] < arr[mid + 1]`, move right:
   ```cpp
   start = mid + 1;
   ```
5. Otherwise, move left:

   ```cpp
   end = mid;
   ```
6. Continue until `start == end`.
7. Return `start` (or `end`).
---
## Dry Run
### Input
```text
arr = [0, 2, 5, 3, 1]
`''
### Iteration 1

```text
start = 0
end = 4

mid = 2

arr[mid] = 5
arr[mid + 1] = 3
```

Since:

```text
5 > 3
```

Peak lies on the left side (including mid).

```text
end = mid = 2
```

### Iteration 2

```text
start = 0
end = 2

mid = 1

arr[mid] = 2
arr[mid + 1] = 5
```

Since:

```text
2 < 5
```

Peak lies on the right side.

```text
start = mid + 1 = 2
```
### Final State

```text
start = 2
end = 2
```
Loop terminates because:

```text
start == end
```
Peak Index:
```text
2
```
Peak Element:

```text
arr[2] = 5
```

------
## Complexity Analysis
### Time Complexity :O(Log N) Binary Search halves the search space in every iteration.
### Space Complexity :O(1) No extra space is used.
---
## C++ Solution
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        while(start < end) {
            int mid = start + (end - start) / 2;

            if(arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return start;
    }
};
```
##Key Takeaway
At every step, determine whether `mid` lies on the increasing slope or decreasing slope of the mountain. Keep shrinking the search space until only one index remains. That index is the peak.

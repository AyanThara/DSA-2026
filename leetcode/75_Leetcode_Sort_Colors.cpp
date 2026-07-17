# Sort Colors - Dutch National Flag Algorithm | LeetCode 75

## Intuition
The array contains only 0, 1, and 2. We can use three pointers to place 0s at the beginning, 1s in the middle, and 2s at the end.

## Approach
Use the Dutch National Flag Algorithm with three pointers:
- `low` represents the position where the next 0 should go.
- `mid` checks the current element.
- `high` represents the position where the next 2 should go.

If `nums[mid] == 0`, swap it with `nums[low]` and increment both `low` and `mid`.

If `nums[mid] == 1`, it is already in the correct position, so increment `mid`.

If `nums[mid] == 2`, swap it with `nums[high]` and decrement `high`. We do not increment `mid` because the new element that comes from `high` needs to be checked.

## Dry Run

Input:
`nums = [2, 0, 2, 1, 1, 0]`

Initial:
`low = 0, mid = 0, high = 5`

| Step | nums[mid] | Operation | Array | low | mid | high |
|------|-----------|-----------|-------|-----|-----|------|
| 1 | 2 | Swap mid with high | `[0,0,2,1,1,2]` | 0 | 0 | 4 |
| 2 | 0 | Swap mid with low | `[0,0,2,1,1,2]` | 1 | 1 | 4 |
| 3 | 0 | Swap mid with low | `[0,0,2,1,1,2]` | 2 | 2 | 4 |
| 4 | 2 | Swap mid with high | `[0,0,1,1,2,2]` | 2 | 2 | 3 |
| 5 | 1 | Increment mid | `[0,0,1,1,2,2]` | 2 | 3 | 3 |
| 6 | 1 | Increment mid | `[0,0,1,1,2,2]` | 2 | 4 | 3 |

Now `mid > high`, so the loop stops.

Output:
`[0, 0, 1, 1, 2, 2]`

## Complexity
- Time Complexity: `O(n)`
- Space Complexity: `O(1)`

## Code

```cpp
/* Brute Force Approach
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // O(n log n)
    }
};
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

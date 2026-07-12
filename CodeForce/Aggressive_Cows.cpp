# 🐄 Aggressive Cows (GFG)

## Problem Statement

You are given an array `arr[]` representing the positions of stalls and an integer `k` representing the number of cows.

Place the cows in the stalls such that:

* Each stall can contain only one cow.
* The minimum distance between any two cows is as **large as possible**.

Return the **maximum possible minimum distance**.

---

# Intuition

Instead of directly finding the best arrangement, we **guess** the minimum distance between cows.

Suppose we assume:

```text
Minimum distance between any two cows = mid
```

Now ask the question:

> **Can we place all `k` cows such that the distance between every pair of consecutive cows is at least `mid`?**

There are only two possibilities:

* ✅ **Yes** → We can try a **larger** minimum distance.
* ❌ **No** → We must reduce the minimum distance.

This monotonic property makes **Binary Search on Answer** applicable.

---

# Binary Search Range

## Minimum Possible Answer

The smallest possible distance between two cows is **1**.

```cpp
low = 1;
```

---

## Maximum Possible Answer

The largest possible distance is between the first and the last stall.

```cpp
high = last_stall - first_stall;
```

Example:

```text
Stalls = [1,2,4,8,9]

high = 9 - 1 = 8
```

Search Space

```text
1 -------------------- 8
```

---

# Feasibility Check (`isPossible()`)

We place cows greedily.

### Step 1

Always place the first cow in the first stall.

```text
Cow 1 → Stall 1
```

### Step 2

Traverse the remaining stalls.

If the distance between the current stall and the last occupied stall is at least `mid`, place another cow.

```cpp
if(arr[i] - lastPos >= mid)
```

Update

```cpp
cows++;
lastPos = arr[i];
```

If all `k` cows are placed successfully,

```cpp
return true;
```

Otherwise,

```cpp
return false;
```

---

# Algorithm

1. Sort the stall positions.
2. Set

   * `low = 1`
   * `high = last stall - first stall`
3. Perform Binary Search.
4. For every `mid`, check whether all cows can be placed.
5. If possible:

   * Store `mid` as the current answer.
   * Search the right half (try a larger distance).
6. Otherwise:

   * Search the left half.
7. Return the largest valid minimum distance.

---

# Dry Run

### Input

```text
arr = [1,2,4,8,9]
k = 3
```

After sorting

```text
1 2 4 8 9
```

Initial values

```text
low = 1
high = 8
```

---

## Iteration 1

```text
mid = (1 + 8) / 2 = 4
```

Place first cow

```text
Cow 1 → 1
```

Need next cow at least **4 units away**

```text
2 → distance = 1 ❌
4 → distance = 3 ❌
8 → distance = 7 ✅
```

Place second cow

```text
Cow 2 → 8
```

Need third cow at least **4 units away**

```text
9 → distance = 1 ❌
```

Only **2 cows** placed.

Not Possible ❌

Update

```text
high = 3
```

---

## Iteration 2

```text
low = 1
high = 3

mid = 2
```

Place cows

```text
Cow 1 → 1

Cow 2 → 4

Cow 3 → 8
```

Successfully placed **3 cows**.

Possible ✅

Update

```text
ans = 2
low = 3
```

---

## Iteration 3

```text
low = 3
high = 3

mid = 3
```

Place cows

```text
Cow 1 → 1

Cow 2 → 4

Cow 3 → 8
```

Minimum distance is maintained.

Possible ✅

Update

```text
ans = 3
low = 4
```

Now

```text
low = 4
high = 3
```

Loop ends.

---

# Final Answer

```text
3
```

---

# C++ Solution

```cpp
class Solution {
public:

    bool isPossible(vector<int>& arr, int k, int dist) {

        int cows = 1;
        int lastPos = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            if (arr[i] - lastPos >= dist) {

                cows++;
                lastPos = arr[i];

                if (cows == k)
                    return true;
            }
        }

        return false;
    }

    int aggressiveCows(vector<int> &arr, int k) {

        sort(arr.begin(), arr.end());

        int low = 1;
        int high = arr.back() - arr.front();

        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {

                ans = mid;
                low = mid + 1;      // Try larger minimum distance

            } else {

                high = mid - 1;     // Distance too large
            }
        }

        return ans;
    }
};
```

---

# Complexity Analysis

| Complexity            | Value                   |
| --------------------- | ----------------------- |
| **Sorting**           | **O(n log n)**          |
| **Binary Search**     | **O(log(maxDistance))** |
| **Feasibility Check** | **O(n)**                |

Overall Time Complexity:

```text
O(n log n + n log(maxDistance))
```

Space Complexity:

```text
O(1)
```

---

# Key Observations

* We are **not searching the stall positions**.
* We are **searching the answer (minimum distance)**.
* `isPossible(mid)` checks whether all cows can be placed while maintaining at least `mid` distance.
* If `mid` is possible, we try to increase the distance.
* If `mid` is not possible, we reduce the distance.

---

# Pattern to Remember

Whenever a problem asks you to:

* **Maximize the minimum** value, and
* You can efficiently verify whether a candidate answer is feasible,

think of **Binary Search on Answer**.

## Similar Problems

* Aggressive Cows (GFG)
* Allocate Minimum Pages (GFG)
* Painter's Partition Problem
* Split Array Largest Sum (LeetCode 410)
* Capacity to Ship Packages Within D Days (LeetCode 1011)

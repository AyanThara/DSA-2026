# 🎨 Painter's Partition Problem – II (GFG)
## Problem Statemen
Given an array `arr[]` where each element represents the length of a board and an integer `k` representing the number of painters, determine the minimum time required to paint all the boards.
### Constraints

* Each painter can paint **only contiguous boards**.
* A board **cannot be split** between painters.
* Every painter paints **1 unit length in 1 unit time**.
* The goal is to **minimize the maximum time** taken by any painter.

---

# Intuition

Instead of trying every possible way to partition the boards, we **binary search the answer**.

Suppose we assume that **no painter is allowed to paint more than `mid` units of board**.

Now the question becomes:

> Can all boards be painted using at most `k` painters if each painter can paint at most `mid` units?

* If **Yes**, we can try to reduce the maximum time.
* If **No**, we need to increase the allowed maximum time.

This monotonic property makes **Binary Search on Answer** applicable.

---

# Binary Search Range

### Minimum Possible Answer

A painter must paint the largest board.

```cpp
low = max(arr)
```

Example:

```text
Boards = [5,10,30,20,15]

Largest board = 30
```

So the answer can never be less than **30**.

---

### Maximum Possible Answer

If only one painter paints every board,

```cpp
high = sum(arr)
```

Example:

```text
5 + 10 + 30 + 20 + 15 = 80
```

So the search space becomes

```text
30 ------------------ 80
```

---

# Feasibility Check

Traverse the boards one by one.

Keep assigning boards to the current painter.

If adding the next board exceeds `mid`:

* Assign that board to the next painter.
* Increase the painter count.

If painters required become greater than `k`, return **false**.

Otherwise return **true**.

---

# Algorithm

1. Set

   * `low = maximum board length`
   * `high = sum of all board lengths`
2. Perform Binary Search.
3. For every `mid`, check whether painting is possible.
4. If possible:

   * Store the answer.
   * Search the left half.
5. Otherwise:

   * Search the right half.
6. Return the minimum possible answer.

---

# Dry Run

### Input

```text
arr = [5,10,30,20,15]
k = 3
```

Initial values

```text
low = 30
high = 80
```

---

## Iteration 1

```text
mid = (30 + 80) / 2 = 55
```

Allocation

```text
Painter 1

5 + 10 + 30 = 45

45 + 20 = 65 > 55
```

Move to Painter 2

```text
Painter 2

20 + 15 = 35
```

Painters used

```text
2
```

Possible ✅

```text
Answer = 55
high = 54
```

---

## Iteration 2

```text
low = 30
high = 54

mid = 42
```

Allocation

```text
Painter 1

5 + 10 = 15

15 + 30 = 45 > 42
```

Painter 2

```text
30
```

Next board

```text
30 + 20 = 50 > 42
```

Painter 3

```text
20 + 15 = 35
```

Painters used

```text
3
```

Possible ✅

```text
Answer = 42
high = 41
```

---

## Iteration 3

```text
low = 30
high = 41

mid = 35
```

Allocation

```text
Painter 1

5 + 10 = 15

15 + 30 = 45 > 35
```

Painter 2

```text
30
```

Next board

```text
30 + 20 = 50 > 35
```

Painter 3

```text
20 + 15 = 35
```

Painters used

```text
3
```

Possible ✅

```text
Answer = 35
high = 34
```

---

## Iteration 4

```text
low = 30
high = 34

mid = 32
```

Allocation

```text
Painter 1

5 + 10 = 15

15 + 30 = 45 > 32
```

Painter 2

```text
30
```

Next board

```text
30 + 20 = 50 > 32
```

Painter 3

```text
20
```

Next board

```text
20 + 15 = 35 > 32
```

Painter 4

```text
15
```

Painters used

```text
4
```

Not Possible ❌

```text
low = 33
```

---

## Iteration 5

```text
low = 33
high = 34

mid = 33
```

Again, 4 painters are required.

Not Possible ❌

```text
low = 34
```

---

## Iteration 6

```text
low = 34
high = 34

mid = 34
```

Again, 4 painters are required.

Not Possible ❌

```text
low = 35
```

Now

```text
low = 35
high = 34
```

Binary Search stops.

---

# Final Answer

```text
35
```

---

# C++ Solution

```cpp
class Solution {
public:

    bool isPossible(vector<int> &arr, int k, long long mid) {

        int painters = 1;
        long long time = 0;

        for (int board : arr) {

            if (time + board <= mid) {
                time += board;
            }
            else {
                painters++;
                time = board;

                if (painters > k)
                    return false;
            }
        }

        return true;
    }

    int minTime(vector<int> &arr, int k) {

        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;

        for (int board : arr)
            high += board;

        long long ans = high;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};
```

---

# Complexity Analysis

| Complexity           | Value                    |
| -------------------- | ------------------------ |
| **Time Complexity**  | **O(n × log(sum(arr)))** |
| **Space Complexity** | **O(1)**                 |

---

# Key Takeaways
* This is a classic **Binary Search on Answer** problem.
* We binary search the **maximum painting time**, not the array.
* The feasibility function greedily assigns contiguous boards while ensuring no painter exceeds the current limit.
* Whenever a problem asks you to **minimize the maximum** value and provides an efficient feasibility check, Binary Search on Answer is often the optimal solution.

## Similar Problems
* Split Array Largest Sum (LeetCode 410)
* Capacity to Ship Packages Within D Days (LeetCode 1011)

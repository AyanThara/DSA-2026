# 📚 Allocate Minimum Pages (GFG)

## Problem Statement

You are given:

* An array `arr[]`, where `arr[i]` represents the number of pages in the `i-th` book.
* An integer `k` representing the number of students.

Allocate the books such that:

* Every student gets **at least one book**.
* Every book is assigned to exactly one student.
* Books assigned to a student must be **contiguous**.
* The objective is to **minimize the maximum number of pages assigned to any student**.

If the number of students is greater than the number of books, return **-1**.

---

# Intuition

Instead of trying every possible allocation of books, we **guess the answer**.

Suppose we assume:

```text
Maximum pages allowed for one student = mid
```

Now ask:

> **Can all books be allocated to at most `k` students such that no student gets more than `mid` pages?**

There are only two possibilities:

* ✅ **Yes** → `mid` is a valid answer. Try to minimize it further.
* ❌ **No** → `mid` is too small. Increase it.

This monotonic behavior makes **Binary Search on Answer** applicable.

---

# Why is the Search Space Correct?

## Minimum Possible Answer

The student who receives the book with the maximum pages must read that entire book.

Since a book **cannot be split**,

```cpp
low = max(arr);
```

Example

```text
Books = [12,34,67,90]

Largest Book = 90
```

No answer smaller than **90** can ever work.

Therefore,

```text
low = 90
```

---

## Maximum Possible Answer

One student reads every book.

```cpp
high = sum(arr);
```

Example

```text
12 + 34 + 67 + 90 = 203
```

Therefore,

```text
high = 203
```

Search Space

```text
90 --------------------- 203
```

---

# Feasibility Check (`isPossible()`)

For every guessed value `mid`:

* Start assigning books to the first student.
* Keep adding books while the total pages do not exceed `mid`.
* If adding another book exceeds `mid`, assign it to the next student.
* Count the number of students used.

If the number of students becomes greater than `k`,

```cpp
return false;
```

Otherwise,

```cpp
return true;
```

---

# Algorithm

1. If `k > number of books`, return `-1`.
2. Set

   * `low = maximum book`
   * `high = sum of all books`
3. Perform Binary Search.
4. Compute `mid`.
5. Check whether allocation is possible.
6. If possible:

   * Store the answer.
   * Search the left half.
7. Otherwise:

   * Search the right half.
8. Return the minimum valid answer.

---

# Dry Run

### Input

```text
arr = [12,34,67,90]
k = 2
```

Initial values

```text
low = 90
high = 203
```

---

## Iteration 1

```text
mid = (90 + 203) / 2 = 146
```

Allocation

```text
Student 1

12 + 34 + 67 = 113

113 + 90 = 203 > 146
```

Student 2

```text
90
```

Students used = **2**

Possible ✅

Update

```text
ans = 146
high = 145
```

---

## Iteration 2

```text
low = 90
high = 145

mid = 117
```

Allocation

```text
Student 1

12 + 34 + 67 = 113
```

Next book

```text
113 + 90 = 203 > 117
```

Student 2

```text
90
```

Students used = **2**

Possible ✅

Update

```text
ans = 117
high = 116
```

---

## Iteration 3

```text
low = 90
high = 116

mid = 103
```

Allocation

```text
Student 1

12 + 34 = 46
```

Next book

```text
46 + 67 = 113 > 103
```

Student 2

```text
67
```

Next book

```text
67 + 90 = 157 > 103
```

Student 3

```text
90
```

Students used = **3**

Need more than `k = 2`

Not Possible ❌

Update

```text
low = 104
```

---

## Iteration 4

```text
low = 104
high = 116

mid = 110
```

Again,

Need **3 students**

Not Possible ❌

Update

```text
low = 111
```

---

## Iteration 5

```text
low = 111
high = 116

mid = 113
```

Allocation

```text
Student 1

12 + 34 + 67 = 113
```

Student 2

```text
90
```

Students used = **2**

Possible ✅

Update

```text
ans = 113
high = 112
```

Now

```text
low = 113
high = 112
```

Binary Search ends.

---

# Final Answer

```text
113
```

---

# C++ Solution

```cpp
class Solution {
public:

    bool isPossible(vector<int>& arr, int k, long long mid) {

        int students = 1;
        long long pages = 0;

        for (int book : arr) {

            if (pages + book <= mid) {
                pages += book;
            }
            else {

                students++;
                pages = book;

                if (students > k)
                    return false;
            }
        }

        return true;
    }

    int findPages(vector<int>& arr, int k) {

        int n = arr.size();

        if (k > n)
            return -1;

        long long low = *max_element(arr.begin(), arr.end());

        long long high = 0;

        for (int book : arr)
            high += book;

        long long ans = high;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {

                ans = mid;
                high = mid - 1;

            } else {

                low = mid + 1;
            }
        }

        return (int)ans;
    }
};
```

---

# Complexity Analysis

| Complexity            | Value                |
| --------------------- | -------------------- |
| **Feasibility Check** | **O(n)**             |
| **Binary Search**     | **O(log(sum(arr)))** |

### Overall Time Complexity

```text
O(n × log(sum(arr)))
```

### Space Complexity

```text
O(1)
```

---

# Key Takeaways

* We are **not searching the array**.
* We are **searching the answer** (maximum pages assigned to a student).
* `low = max(arr)` because the largest book cannot be split.
* `high = sum(arr)` because one student can read all books.
* `isPossible(mid)` checks whether all books can be allocated using at most `k` students while ensuring no student gets more than `mid` pages.
* If `mid` is possible, search the **left half** because we want to minimize the answer.
* If `mid` is not possible, search the **right half**.

---

# Similar Problems

* Allocate Minimum Pages (GFG)
* Painter's Partition Problem (GFG)
* Split Array Largest Sum (LeetCode 410)
* Capacity to Ship Packages Within D Days (LeetCode 1011)

### Binary Search Pattern

| Problem Type             | Binary Search Move                                                         |
| ------------------------ | -------------------------------------------------------------------------- |
| **Minimize the Maximum** | Possible → Left (`high = mid - 1`), Not Possible → Right (`low = mid + 1`) |
| **Maximize the Minimum** | Possible → Right (`low = mid + 1`), Not Possible → Left (`high = mid - 1`) |

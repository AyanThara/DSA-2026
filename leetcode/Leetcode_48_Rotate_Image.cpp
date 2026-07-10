# 🔄 LeetCode 48 - Rotate Image (C++)

## Problem Statement

Given an `n × n` 2D matrix representing an image, rotate the image by **90 degrees clockwise**.

**Constraints:**

* Rotate the matrix **in-place**.
* Do **not** use another matrix.

---

# 💡 Intuition

A 90° clockwise rotation can be achieved in two simple steps:

1. **Transpose** the matrix.
2. **Reverse every row**.

This allows us to rotate the matrix without using any extra space.

---

# 🚀 Approach

### Step 1: Transpose the Matrix

Swap every element above the main diagonal with its corresponding element below the diagonal.

```cpp
swap(matrix[i][j], matrix[j][i]);
```

Example:

Original

```text
1 2 3
4 5 6
7 8 9
```

After Transpose

```text
1 4 7
2 5 8
3 6 9
```

---

### Step 2: Reverse Every Row

Reverse each row of the transposed matrix.

After reversing:

```text
7 4 1
8 5 2
9 6 3
```

This is the required **90° clockwise rotated matrix**.

---

# 📝 Dry Run

### Input Matrix

```text
1 2 3
4 5 6
7 8 9
```

---

## Transpose

### i = 0

### j = 0

Swap (0,0) with (0,0)

```text
1 2 3
4 5 6
7 8 9
```

---

### j = 1

Swap (0,1) with (1,0)

```text
1 4 3
2 5 6
7 8 9
```

---

### j = 2

Swap (0,2) with (2,0)

```text
1 4 7
2 5 6
3 8 9
```

---

## i = 1

### j = 1

No change

```text
1 4 7
2 5 6
3 8 9
```

---

### j = 2

Swap (1,2) with (2,1)

```text
1 4 7
2 5 8
3 6 9
```

---

## i = 2

### j = 2

No change

Transpose Completed

```text
1 4 7
2 5 8
3 6 9
```

---

## Reverse Every Row

Row 1

```text
1 4 7
```

↓

```text
7 4 1
```

Matrix

```text
7 4 1
2 5 8
3 6 9
```

---

Row 2

```text
2 5 8
```

↓

```text
8 5 2
```

Matrix

```text
7 4 1
8 5 2
3 6 9
```

---

Row 3

```text
3 6 9
```

↓

```text
9 6 3
```

Final Output

```text
7 4 1
8 5 2
9 6 3
```

---

# ✅ C++ Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse every row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

---

# ⏱️ Complexity Analysis

* **Time Complexity:** `O(N²)`
* **Space Complexity:** `O(1)`

---

# ⭐ Key Takeaway

For **90° Clockwise Rotation**, always remember:

```text
Transpose
        +
Reverse Every Row
```

This is the most efficient in-place solution and is the standard approach expected in coding interviews and on LeetCode.

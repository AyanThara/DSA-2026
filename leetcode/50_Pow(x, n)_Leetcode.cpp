# LeetCode 50 - Pow(x, n)|**Binary Exponentiation | O(log n) | C++**
## Intuition
The brute force approach multiplies `x` by itself `n` times, which takes `O(n)` time.
We can do better using **Binary Exponentiation**.
Think of it like taking giant jumps instead of small steps. Instead of multiplying by `x` again and again, we keep squaring `x` and reduce the power by half each time.
This makes the solution much faster.
---
##Approach
1. Store `n` in a `long long` variable to avoid overflow.
2. If `n` is negative:
   * Convert `x` to `1/x`.
   * Make `n` positive.
3. Initialize `ans = 1`.
4. While power is greater than 0:
   * If power is odd, multiply `ans` by `x`.
   * Square `x`.
   * Divide power by 2.
5. Return `ans`.
---
## Dry Run
### Example
```text
x = 2
n = 10
```
Binary form of 10:
```text
1010
```
Initial values:
```text
ans = 1
x = 2
power = 10
```
### Iteration 1

```text
power = 10
```

10 is even.

```text
ans = 1
x = 2 × 2 = 4
power = 10 / 2 = 5
```

---

### Iteration 2

```text
power = 5
```

5 is odd.

```text
ans = 1 × 4 = 4
x = 4 × 4 = 16
power = 5 / 2 = 2
```

---

### Iteration 3

```text
power = 2
```

2 is even.

```text
ans = 4
x = 16 × 16 = 256
power = 2 / 2 = 1
```

---

### Iteration 4

```text
power = 1
```

1 is odd.

```text
ans = 4 × 256 = 1024
x = 256 × 256
power = 0
```

Loop stops.

```text
Answer = 1024
```

---

## Explain Like a Kid 🧒

Suppose your teacher asks:

```text
2 × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2
```

That is a lot of multiplication.
Instead of multiplying 2 ten times, we do this:
```text
2² = 4
4² = 16
16² = 256
```
Now we are making bigger numbers quickly.
Whenever the power is odd, we save the current value in our answer.
Whenever the power is even, we simply square the number and cut the power in half.
So instead of doing 10 multiplications, we do only a few operations.
That is why Binary Exponentiation is much faster than the brute-force method.
---
## Complexity
* Time Complexity: **O(log n)**
* Space Complexity: **O(1)**
## Code
class Solution {
public:
    double myPow(double x, int n) {
        long long binaryform = n;//start binary form with n 
        double ans = 1; //ans with 1
        if(binaryform < 0) { //check is binary form less than 0 basically is power less than 0
            x = 1 / x; //if yes than convert x to 1/x 
            binaryform = -binaryform;//make binar to -binary so it convert into positive
        }
        while(binaryform > 0) {//if binary form greater than 0 i.e power 
            if(binaryform % 2 == 1) {//than check divisble by 2 
                ans *= x;//yes than ans=ans*x
            }
            x *= x;//update the x value 
            binaryform /= 2;//remove the last digit
        }
        return ans;//return ans
    }
};

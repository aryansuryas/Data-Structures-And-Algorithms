# LC 9 — Palindrome Number

## Problem Info

| Field | Details |
|-------|---------|
| **LeetCode #** | 9 |
| **Problem Name** | Palindrome Number |
| **Difficulty** | Easy |
| **Topic** | Math |
| **Pattern** | Half Reversal — Reverse only half the digits |

---

## Problem Description

Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.

```
Input:  x = 121    →  Output: true   (reads same forward and backward)
Input:  x = -121   →  Output: false  (negative numbers are never palindromes)
Input:  x = 10     →  Output: false  (trailing zero can't match leading zero)
```

---

## Visual — What Is a Palindrome Number?

```
121   →   forward: 1 2 1   |   backward: 1 2 1   ✅ Palindrome
1221  →   forward: 1 2 2 1 |   backward: 1 2 2 1 ✅ Palindrome
123   →   forward: 1 2 3   |   backward: 3 2 1   ❌ Not a Palindrome
-121  →   Negative → always false                ❌
10    →   Trailing zero → always false            ❌
```

---

## Core Concept — Half Reversal

Instead of reversing the entire number (which can overflow), we only reverse **half** of it.

We pop digits from the right of `num` and push them onto `rev`:

```
121
Step 1: num=12,  rev=1    (popped 1)
Step 2: num=1,   rev=12   (popped 2)

Now: num == rev/10  →  1 == 1  ✅  (odd-length middle digit ignored)

1221
Step 1: num=122, rev=1
Step 2: num=12,  rev=12

Now: num == rev  →  12 == 12  ✅  (even-length, exact match)
```

We **stop** when `rev >= num`. At that point, half is done.

---

## The Code

```cpp
class Solution {
public:
    bool isPalindrome(int num) {
        if (num < 0 || (num % 10 == 0 && num != 0)) return false;

        long rev = 0;
        while (num > rev) {
            int digit = num % 10;
            rev = rev * 10 + digit;
            num = num / 10;
        }
        return rev == num || rev / 10 == num;
    }
};
```

---

## Line by Line Explanation

### `isPalindrome(int num)` — Main Function

| Line | Code | What it does |
|------|------|-------------|
| 1 | `if (num < 0)` | Negative numbers can never be palindromes — return false |
| 2 | `(num % 10 == 0 && num != 0)` | Numbers ending in 0 can't be palindromes (no leading zeros) except 0 itself |
| 3 | `long rev = 0` | Stores the reversed half. `long` prevents overflow during build-up |
| 4 | `while (num > rev)` | Keep reversing until the right half (rev) catches up to the left half (num) |
| 5 | `int digit = num % 10` | Extract the last digit of num |
| 6 | `rev = rev * 10 + digit` | Append that digit to rev (builds reverse) |
| 7 | `num = num / 10` | Remove the last digit from num |
| 8 | `rev == num` | Even-length palindrome: both halves are exactly equal |
| 9 | `rev / 10 == num` | Odd-length palindrome: middle digit is in rev, so drop it and compare |

---

## Why Two Return Conditions?

```
Even-length: 1221
  After loop: num = 12,  rev = 12
  Check: rev == num  →  12 == 12  ✅

Odd-length: 12321
  After loop: num = 12,  rev = 123
  Check: rev / 10 == num  →  12 == 12  ✅
  (middle digit 3 is stripped away by /10)
```

---

## Full Dry Run

### Case 1: `num = 121`
```
Initial:  num=121, rev=0
while (121 > 0):
  digit = 121 % 10 = 1
  rev   = 0*10 + 1 = 1
  num   = 121 / 10 = 12

while (12 > 1):
  digit = 12 % 10 = 2
  rev   = 1*10 + 2 = 12
  num   = 12 / 10 = 1

while (1 > 12):  ← FALSE, loop ends

Check: rev == num?  →  12 == 1  ❌
Check: rev/10 == num?  →  1 == 1  ✅
Return: true
```

### Case 2: `num = 1221`
```
Initial:  num=1221, rev=0
while (1221 > 0):
  digit=1, rev=1, num=122

while (122 > 1):
  digit=2, rev=12, num=12

while (12 > 12):  ← FALSE, loop ends

Check: rev == num?  →  12 == 12  ✅
Return: true
```

### Case 3: `num = -121`
```
num < 0  →  return false immediately
```

### Case 4: `num = 10`
```
num % 10 == 0 && num != 0  →  return false immediately
```

---

## Output

```
Input:  x = 121    →  true
Input:  x = -121   →  false
Input:  x = 10     →  false
Input:  x = 0      →  true
Input:  x = 1221   →  true
```

---

## Complexity Analysis — All 10 Steps

### Time Complexity

| Step | What Happens | Cost |
|------|-------------|------|
| 1 | Check negative / trailing zero | O(1) |
| 2 | Enter while loop | runs until rev ≥ num |
| 3 | Each iteration: one mod, one divide, one multiply | O(1) per step |
| 4 | Number has d digits total | d = log₁₀(num) |
| 5 | Loop runs for only half the digits | d/2 iterations |
| 6 | Early exit for negatives and trailing zeros | O(1) |
| 7 | Final comparison is O(1) | O(1) |
| 8 | Dominant cost: half-reversal loop | O(d/2) |
| 9 | d = log₁₀(num) | log factor |
| 10 | **Final Time Complexity = O(log n)** | ✅ (n = input number) |

```
Number of digits d = log₁₀(n)
Loop runs d/2 times → O(log n)
```

### Space Complexity

| Step | What is Stored | Cost |
|------|---------------|------|
| 1 | `rev` — one long variable | O(1) |
| 2 | `digit` — one int variable | O(1) |
| 3 | `num` — modified in place | O(1) |
| 4 | No arrays, no recursion stack | O(1) |
| 5 | Fixed number of variables regardless of input size | O(1) |
| 6 | No extra memory allocated | O(1) |
| 7 | No string conversion used | O(1) |
| 8 | No output structure needed | O(1) |
| 9 | All work done in a few primitive variables | O(1) |
| 10 | **Final Space Complexity = O(1)** | ✅ constant space |

---

## Summary Table

| | Complexity | Reason |
|-|-----------|--------|
| **Time** | O(log n) | Loop runs for half the digits = log₁₀(n)/2 |
| **Space** | O(1) | Only a few integer variables used |

---

## Key Takeaway

```
Two edge cases to eliminate first:
  1. Negative numbers    → always false
  2. Trailing zero       → always false (except 0 itself)

Then reverse only HALF the digits:
  while (num > rev):
    pop digit from num → push onto rev

Two checks at the end:
  rev == num        →  even-length palindrome
  rev / 10 == num   →  odd-length palindrome (drop middle digit)

This avoids full reversal and prevents integer overflow.
```

---

FizzBuzz

A simple C++ solution for the FizzBuzz problem.

---

1. Problem

Given an integer "n", return a vector containing numbers from "1" to "n".

Follow these rules:

- If the number is divisible by 3 and 5 → ""FizzBuzz""
- If the number is divisible by 3 → ""Fizz""
- If the number is divisible by 5 → ""Buzz""
- Otherwise → return the number as a string

---

2. Example

Input

n = 15

Output

["1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz",
 "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"]

---

3. Step-by-Step Approach

Step 1: Create the answer vector

vector<string> ans;

This vector stores all the results.

---

Step 2: Loop from 1 to n

for (int i = 1; i <= n; i++)

We check every number from "1" to "n".

---

Step 3: Check divisibility by both 3 and 5

if (i % 3 == 0 && i % 5 == 0)

If the number is divisible by both "3" and "5", add:

FizzBuzz

Example:

15 → FizzBuzz

---

Step 4: Check divisibility by 3

else if (i % 3 == 0)

If the number is divisible by "3", add:

Fizz

Example:

9 → Fizz

---

Step 5: Check divisibility by 5

else if (i % 5 == 0)

If the number is divisible by "5", add:

Buzz

Example:

10 → Buzz

---

Step 6: Otherwise, add the number

else {
    ans.push_back(to_string(i));
}

If the number is not divisible by "3" or "5", convert it into a string.

Example:

7 → "7"

---

Step 7: Return the answer

return ans;

The completed vector is returned.

---

4. C++ Code

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for (int i = 1; i <= n; i++) {

            if (i % 3 == 0 && i % 5 == 0) {
                ans.push_back("FizzBuzz");
            }
            else if (i % 3 == 0) {
                ans.push_back("Fizz");
            }
            else if (i % 5 == 0) {
                ans.push_back("Buzz");
            }
            else {
                ans.push_back(to_string(i));
            }
        }

        return ans;
    }
};

---

5. Important Concept

Modulo Operator "%"

The modulo operator gives the remainder after division.

15 % 3 == 0

Since "15" is completely divisible by "3", the remainder is "0".

Similarly:

15 % 5 == 0

Therefore:

15 % 3 == 0 && 15 % 5 == 0

is "true", so the output is:

FizzBuzz

---

6. Why Check FizzBuzz First?

The order of conditions is important.

We check:

if (i % 3 == 0 && i % 5 == 0)

before checking "3" or "5" individually.

For example, "15" is divisible by both.

If we checked "3" first:

if (i % 3 == 0)

then "15" would become:

Fizz

instead of:

FizzBuzz

---

7. Complexity

Time Complexity

O(n)

We iterate from "1" to "n" once.

Space Complexity

O(n)

The result vector stores "n" elements.

---

8. Concepts Used

- C++ "vector"
- "string"
- "for" loop
- "if / else if / else"
- Modulo operator "%"
- "push_back()"
- "to_string()"

---

9. Key Takeaway

FizzBuzz is a simple problem that helps build the fundamentals of:

Loops
   ↓
Conditions
   ↓
Modulo Operator
   ↓
Vectors
   ↓
String Conversion

These concepts are useful for solving many beginner-level DSA problems.
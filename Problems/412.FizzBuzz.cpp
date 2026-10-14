# LeetCode 412: FizzBuzz

## 🎯 Goal
The function generates a 1-indexed list of strings from \(1\) to \(n\) by replacing multiples of 3 with "Fizz", multiples of 5 with "Buzz", and common multiples of both with "FizzBuzz". It uses a simple **linear iteration** combined with conditional modulo checks.

## 🛠️ Code Implementation
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans; // Stores the final list of strings
        
        for (int i = 1; i <= n; i++) { // 1-indexed loop up to n
            // Check rarest condition first: divisibility by both 3 and 5 (LCM = 15)
            if (i % 3 == 0 && i % 5 == 0)
                ans.push_back("FizzBuzz");
            // Check divisibility by 3 only
            else if (i % 3 == 0)
                ans.push_back("Fizz");
            // Check divisibility by 5 only
            else if (i % 5 == 0)
                ans.push_back("Buzz");
            // Fallback: convert the current integer to a string
            else {
                ans.push_back(to_string(i));
            }
        }
        return ans; // Return the populated string array
    }
};
```

## 🔄 Trace Example (n = 5)

| Step | i | i % 3 == 0 | i % 5 == 0 | Matching Condition | Action / Appended Value | Cumulative `ans` |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 1 | False | False | `else` | Appended `"1"` | `["1"]` |
| 2 | 2 | False | False | `else` | Appended `"2"` | `["1", "2"]` |
| 3 | 3 | True | False | `i % 3 == 0` | Appended `"Fizz"` | `["1", "2", "Fizz"]` |
| 4 | 4 | False | False | `else` | Appended `"4"` | `["1", "2", "Fizz", "4"]` |
| 5 | 5 | False | True | `i % 5 == 0` | Appended `"Buzz"` | `["1", "2", "Fizz", "4", "Buzz"]` |

**Result:** `["1", "2", "Fizz", "4", "Buzz"]`

## ⚠️ Edge Cases Handled
* **Minimum Constraint (\(n = 1\)):** Loop executes exactly once, evaluates to the `else` branch, and safely outputs `["1"]`.
* **Rarest Branch Order:** Divisibility by 15 (`i % 3 == 0 && i % 5 == 0`) is placed at the top so that combined multiples are not prematurely intercepted by individual "Fizz" or "Buzz" conditions.

## 💡 Key Takeaways
* **Conditional Ordering:** Always check the most restrictive joint condition first in an `if-else` chain to prevent broader individual conditions from masking it.
* **String Conversion Costs:** Utilizing `to_string(i)` creates a new string object dynamically, which takes minimal but measurable overhead compared to pushing static string literals like `"Fizz"`.

## ⚡ Complexity Analysis
* **Time Complexity:** \(O(n)\)
  * The algorithm runs a single loop that iterates exactly \(n\) times, performing constant-time modulo checks per iteration.
* **Space Complexity:** \(O(n)\) 
  * The memory scales linearly with the input since it requires storing \(n\) elements inside the output string vector.

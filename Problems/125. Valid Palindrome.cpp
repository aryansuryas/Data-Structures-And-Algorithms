125. Valid Palindrome : A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
  it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

//===========================================================================================================================================================================
  #include <string>
#include <cctype>

using namespace std;

/* ==========================================                           | ==========================================
 *              YOUR ORIGINAL CODE                                      |             FULLY OPTIMIZED CODE        
 * ==========================================                           | ========================================== */

class SolutionOriginal {                                                 | class SolutionOptimized {
public:                                                                 | public:
    bool isPalindrome(string s) {                                       |     bool isPalindrome(string s) {
        int l = 0;                                                      |         // Unties C++ standard streams for speed
        int r = s.size() - 1;                                           |         ios_base::sync_with_stdio(false);
                                                                        |         cin.tie(NULL);
                                                                        | 
                                                                        |         int l = 0;
                                                                        |         int r = s.size() - 1;
                                                                        | 
        while(l < r) {                                                  |         while (l < r) {
            while(l < r && !(isalnum(s[l]))) {                          |             // Inlined ASCII checks skip function overhead
                l++;                                                    |             while (l < r && !((s[l] >= 'a' && s[l] <= 'z') || 
            }                                                           |                               (s[l] >= 'A' && s[l] <= 'Z') || 
                                                                        |                               (s[l] >= '0' && s[l] <= '9'))) {
                                                                        |                 l++;
                                                                        |             }
            while(l < r && !(isalnum(s[r]))) {                          |             while (l < r && !((s[r] >= 'a' && s[r] <= 'z') || 
                r--;                                                    |                               (s[r] >= 'A' && s[r] <= 'Z') || 
            }                                                           |                               (s[r] >= '0' && s[r] <= '9'))) {
                                                                        |                 r--;
                                                                        |             }
                                                                        | 
            if(tolower(s[l]) != tolower(s[r]))                          |             // Fast inline ASCII arithmetic case folding
                return false;                                           |             char cl = (s[l] >= 'A' && s[l] <= 'Z') ? (s[l] + 32) : s[l];
            }                                                           |             char cr = (s[r] >= 'A' && s[r] <= 'Z') ? (s[r] + 32) : s[r];
                                                                        | 
                                                                        |             if (cl != cr) {
                                                                        |                 return false;
                                                                        |             }
                                                                        | 
            r--;                                                        |             l++;
            l++;                                                        |             r--;
        }                                                               |         }
        return true;                                                    |         return true;
    }                                                                   |     }
};                                                                      | };

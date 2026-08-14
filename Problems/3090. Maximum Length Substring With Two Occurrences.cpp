3090. Maximum Length Substring With Two Occurrences  : Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
Example 1:
Input: s = "bcbbbcba"
Output: 4
Explanation:The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".

Example 2:
Input: s = "aaaa"
Output: 2
Explanation:The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 
Constraints:

2 <= s.length <= 100
s consists only of lowercase English letters.

//=============================================================================================================================================================================
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int max_len = 0;
        int left = 0;
        vector<int> count(26, 0);

        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'a']++;

            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};

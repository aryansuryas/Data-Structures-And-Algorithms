//===========================================
class Solution {
public:
    bool isPalindrome(int x) {
        // FIXED: Changed bitwise & to logical &&
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int ans = 0;
        while (x > ans) {
            int mod = x % 10;
            ans = mod + ans * 10;
            x = x / 10;
        }
        return ans == x || x == ans / 10;
    }
};





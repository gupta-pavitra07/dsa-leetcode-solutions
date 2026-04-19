/*
Problem no 9
Platform : Leetcode
Problem name : Palindrome Number
Link : https://leetcode.com/problems/palindrome-number/description/
Approach : Half Reversal
Time Complexity : O(log N)
Space Complexity : O(1)
*/
class Solution {
public:
    bool isPalindrome(int x) 
    {
        // Negative numbers are not palindrome
        // Numbers ending with 0 (but not 0 itself) also not palindrome
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;

        int revHalf = 0;

        // Reverse only half of the number
        while(x > revHalf)
        {
            int digit = x % 10;
            revHalf = revHalf * 10 + digit;
            x = x / 10;
        }

        // For even digits: x == revHalf
        // For odd digits: x == revHalf/10 (middle digit ignored).
        return (x == revHalf || x == revHalf / 10);
    }
};
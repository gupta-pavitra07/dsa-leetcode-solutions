/*
Problem no 125
Platform : Leetcode
Problem name : Valid Palindrome
Link : https://leetcode.com/problems/valid-palindrome/description/
Approach : String Handling
Time Complexity : O(n2)
Space Complexity : O(1)
*/
class Solution {
public:
    bool isPalindrome(string s) 
    {
    for (int i = 0 ; i < s.size() ; i++)
    {
        if(!isalnum(s[i]))
        {   
            s.erase(s.begin()+i);
            i--;  
        }
    }

    for(int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
    }

    if(s.size() == 0) return true;

    for(int i = 0 ; i < s.size()/2 ; i++)
    {
        if(s[i] != s[s.size()-i-1]) return false;
    }
    return true;
    }
};
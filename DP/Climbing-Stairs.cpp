// PROBLEM NO : 70
// Platform : Leetcode
// Link : https://leetcode.com/problems/climbing-stairs/
// Approach : Dynamic Programming 
// Time Complexity : O(N)
// Space Complexity : O(N) + O(N)
class Solution {
public:
    int f(int n , vector<int>&dp )
    {
        if(n == 0) return 1;
        if(n == 1)  return 1;

        int left , right;

        if(dp[n-1] != -1) 
        {
            left = dp[n-1];
        }
        else 
        {
            left = f(n-1,dp);
        }
        if(dp[n-2] != -1) 
        {
            right = dp[n-2];
        }
        else
        {
            right = f(n-2,dp);
        }

        return dp[n] = left + right ;
    }
    int climbStairs(int n) 
    {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};

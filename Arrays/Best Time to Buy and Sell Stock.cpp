//Problem 121
class Solution {
public:
    int maxProfit(vector<int>& nums) 
    {
       int n = nums.size();
       int profit =0 , maxprofit = 0 , mini = nums[0];
       for(int i = 0 ; i< n ; i++)
       {
            profit = nums[i] - mini ;
            maxprofit = max(profit , maxprofit);
            mini = min(mini , nums[i]);
       } 
       return maxprofit;
    }
};


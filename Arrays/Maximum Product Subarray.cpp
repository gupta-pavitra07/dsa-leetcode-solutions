//Problem 152
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        int maxpro = INT_MIN;
        for(int i = 0 ; i<n ; i++ )
        {
            int pro = 1 ;
            for(int j = i ; j< n ; j++ )
            {
                pro *= nums[j];
                maxpro = max(pro , maxpro);
            }
        }
        return maxpro;
    }
};
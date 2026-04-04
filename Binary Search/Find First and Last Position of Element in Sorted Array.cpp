//Problem 34
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n = nums.size();
        auto it1 = std::lower_bound(nums.begin(),nums.end(),target);
        int lb = it1-nums.begin();
        auto it2 = std::upper_bound(nums.begin(),nums.end(),target);
        int ub = it2-nums.begin();
        if(lb == n || nums[lb] != target)
        {
            return {-1,-1};
        }
        return{lb,ub-1};   
    }
};
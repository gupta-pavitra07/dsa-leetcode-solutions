//Problem 153
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = INT_MAX;
        int low = 0 , high = n-1;

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(nums[low] <= nums[mid])
            {
                if(nums[low] < ans)
                {
                    ans = nums[low];
                }
                low = mid+1;
            }
            else
            {
                if(nums[mid]<ans)
                {
                    ans = nums[mid];
                }
                high = mid-1;
            }
        }
        return ans;
    }
};
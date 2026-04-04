//Problem 1283
class Solution {
public:
    int check(vector<int>&nums,int mid)
    {
        int sum = 0 ;
        for(int i = 0 ; i<nums.size();i++)
        {
            sum += (nums[i] + mid-1)/mid;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int n = nums.size();

        int maxi = nums[0];
        for(int x : nums)
        {
            maxi = max(maxi,x);
        }

        int low =1 , high = maxi,ans;
        while(low<=high)
        {
            int mid = (low+high)/2;

            if(check(nums,mid)<=threshold)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};
//Problem 1011
class Solution {
public:
    int check(vector<int>&nums , int mid )
    {
        int days = 1,weight=0;
        for(int i = 0 ; i<nums.size();i++)
        {
            if(weight + nums[i] > mid)
            {
                days++;
                weight = nums[i] ;
            }
            else
            {
                weight += nums[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n = weights.size();

        int sum = 0 ;
        for(int x : weights)
        {
            sum += x;
        }

        int low = *max_element(weights.begin(), weights.end()); 
        int high = sum,ans ;
        while(low <= high)
        {
            int mid = (low+high)/2;

            if(check(weights,mid) <= days)
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
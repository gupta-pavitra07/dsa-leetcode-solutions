//Problem 485
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int n = nums.size();
        int maxone = 0 ;
        for(int i = 0 ; i< n ;)
        {
            if(nums[i] == 1)
            {
                int j = i ;
                int cnt = 0 ;
                while(j<n && nums[j] == 1)
                {
                    cnt++;
                    j++;
                }
                if(cnt > maxone)
                {
                    maxone = cnt;
                }
                i=j;
            }
            else
            {
                i++;
            }
        }
        return maxone;
    }
};;
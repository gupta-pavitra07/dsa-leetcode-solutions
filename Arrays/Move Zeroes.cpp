//Problem 283
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int j =-1 ;
        //finding the occurrence of first zero
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(nums[i] == 0 )
            {
                j = i ;
                break;
            }
        }
        if(j == -1) return;
        for(int i = j+1 ; i<nums.size() ; i++)
        {
            if(nums[i] != 0)
            {
                swap(nums[i] , nums[j]);
                j++;
            }
        }

    }
};

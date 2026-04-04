//Problem 128
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n = nums.size();
        if(nums.empty()) return 0 ;
        sort(nums.begin(),nums.end());
        int longestseq = 1 , seq = 1 ;
        for(int  i = 1 ; i< n ; i++)
        {
            if(nums[i] == nums[i-1])
            {
                continue;
            }

            if(nums[i] == nums[i-1]+1)
            {
                seq++;
                longestseq = max(seq,longestseq);
            }
            else
            {
                seq = 1 ;
            }
        }
        return longestseq;
    }
};
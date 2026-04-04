//Problem 977
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();
        int left = 0 , right = n-1;
        int pos = n-1;
        vector<int>result(n);
        while(left<=right)
        {
            if(nums[left]*nums[left] > nums[right]*nums[right])
            {
                result[pos] = nums[left]*nums[left];
                left++;
                pos--;
            }
            else
            {
                result[pos] = nums[right]*nums[right];
                right--;
                pos--;
            } 
        }
        return result;
    }
};
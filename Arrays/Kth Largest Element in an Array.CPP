//Problem 215
class Solution {
public:
    void heapify(vector<int>&nums , int n , int i)
    {
        int largest = i ;
        int left = 2*i +1 ;
        int right = 2*i + 2;

        if(left < n && nums[largest] < nums[left])
        {
            largest = left ;
        }
        if(right < n && nums[largest] < nums[right])
        {
            largest = right ;
        }
        if(largest != i)
        {
            swap(nums[largest] , nums[i]);
            heapify(nums,n,largest);
        }
    }

    int extractmax(vector<int>&nums , int *n)
    {
        if(*n==0) return -1;

        int max = nums[0];
        swap(nums[0],nums[*n-1]);
        (*n)--;
        heapify(nums,*n,0);
        return max;
    }

    int findKthLargest(vector<int>& nums, int k) 
    {
        int n = nums.size();
        for(int i = n/2 - 1 ; i>=0 ; i--)
        {
            heapify(nums,n,i);
        }
        int max;
        for(int i = 0 ; i<k ; i++)
        {
            max = extractmax(nums,&n);
        }
        return max;
        
    }
};
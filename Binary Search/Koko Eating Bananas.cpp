//Problem 875
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int n = piles.size();
        int low = 1 ,high = 0;
        for(int i = 0 ; i< n ; i++)
        {
            high = max(piles[i],high);
        }
        int ans;

        while(low<=high)
        {
            int mid = (low+high)/2;
            long long reqtime = 0 ;

            for(int i=0 ; i<n ; i++)
            {
                reqtime += (piles[i] + mid - 1) / mid;
            }

            if(reqtime <= h)
            {
                ans = mid ;
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
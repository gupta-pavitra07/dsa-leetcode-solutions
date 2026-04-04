//Problem 1482
class Solution {
public:
    int check(vector<int>&bloomday , int k , int mid)
    {
        int bouquecnt = 0 , flowers = 0 ;
        for(int i = 0 ;i < bloomday.size() ; i++)
        {
            if(bloomday[i]<=mid)
            {
                flowers++;
                if(flowers == k)
                {
                    bouquecnt++;
                    flowers =0;
                }
            }
            else
            {
                flowers = 0 ;
            }
        }
        return bouquecnt;
    }
    int minDays(vector<int>& bloomday, int m, int k) 
    {
        int n = bloomday.size();
        //f(m*k > n) return -1;

        int maxi = bloomday[0];
        for(int i = 0 ; i< n ; i++)
        {
            maxi = max(maxi,bloomday[i]); 
        }
        int low = 1 , high = maxi ,minday=-1;
        while(low<=high)
        {
            int mid = (low+high)/2;

            if(check(bloomday,k,mid) >= m)
            {
                minday = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return minday;
    }
};
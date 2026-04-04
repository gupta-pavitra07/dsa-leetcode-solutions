//Problem 169
class Solution {
public:
    int majorityElement(vector<int>& v) 
    {
     //moore's vooting algorithm
        int n = v.size();
        int cnt = 0 ;
        int ele;
        for(int i =0 ; i<n ; i++)
        {
            if(cnt == 0 )
            {
                cnt =1;
                ele = v[i];
            }
            else if(v[i] == ele)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return ele;

    }
};
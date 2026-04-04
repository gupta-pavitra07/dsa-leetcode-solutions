//Problem 11
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int maxarea = 0 , area = 0;
        int i = 0;
        for(int j=n-1 ; j>i ;)
        {
            int width = j - i ;
            area = width * min(height[i] , height[j]);
            if(area > maxarea)
            {
                maxarea = area;
            }
            if(height[i] > height[j])
            {
                j--;
            }
            else if(height[i] <= height[j])
            {
                i++;
            }
        }
        return maxarea;
    }
};
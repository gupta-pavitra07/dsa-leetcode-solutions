//Problem 509
class Solution {
public:
    int fib(int n) 
    {
        int first = 0 , second = 1,sum;
        if (n==0) return 0;
        if (n==1) return 1;
        for (int i=1;i<n;i++)
        {
            sum = first+second;
            first = second;
            second = sum;
        }
        return sum;
    }
};
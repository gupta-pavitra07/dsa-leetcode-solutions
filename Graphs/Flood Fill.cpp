//Problem 733
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>>q;
        int startcolor = image[sr][sc];
        if(startcolor == color) return image;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        q.push({sr,sc});
        image[sr][sc] = color ;
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow < n && ncol>=0 && ncol < m && image[nrow][ncol] == startcolor)
                {
                    q.push({nrow,ncol});
                    image[nrow][ncol] = color ;
                }
            }
        }
        return image;
    }
};
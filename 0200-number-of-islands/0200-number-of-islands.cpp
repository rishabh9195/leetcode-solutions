class Solution {
public:

    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};

    bool valid(int i, int j, int m, int n)
    {
        if(i<0 || i>=m || j<0 || j>=n)
        {
            return false;
        } 
        return true;
    }

    void dfs(vector<vector<char>>& grid,int m, int n,  int i, int j, vector<vector<bool>>& visited)
    {
        visited[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int row= i+ x[k];
            int col= j+ y[k];
        
            if(valid(row,col,m,n) && grid[row][col]=='1' && visited[row][col]==0)
            {
                dfs(grid,m,n,row,col,visited);
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;

        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        for(int i=0;i<m;i++)
        {
            for(int j=0; j<n;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    dfs(grid,m,n,i,j,visited);
                    res++;
                }
            }
        }
        return res;

    }
};
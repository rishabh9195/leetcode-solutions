class Solution {
public:

    void dfs(vector<vector<int>>& isConnected,int node,vector<bool>&visited)
    {
        visited[node]=1;

        for(int j=0;j<isConnected.size();j++)
        {
            if(isConnected[node][j]==1 && visited[j]==0)
            {
                dfs(isConnected,j,visited);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        int ans=0;
        vector<bool>visited(n,0);

        for(int i=0 ;i<n;i++)
        {
            if(visited[i]==0)
            {
                ans++;
                dfs(isConnected,i,visited);
            }
        }
        return ans;

    }
};
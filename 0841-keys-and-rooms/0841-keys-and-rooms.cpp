class Solution {
public:

    void dfs(vector<vector<int>>& rooms,int node,vector<bool>&vis)
    {
        vis[node]=1;

        for(int j=0;j<rooms[node].size();j++)
        {
            int neigh=rooms[node][j];

            if(vis[neigh]==0)
            {
                dfs(rooms,neigh,vis);
            }
        }
        return;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();

        vector<bool>vis(n,0);

        dfs(rooms,0,vis);

        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> a(n);

        for(int i=0;i<edges.size();i++)
        {
            int s=edges[i][0];
            int d=edges[i][1];

            a[s].push_back(d);
            a[d].push_back(s);
        }
        
        queue<int>q;
        vector<bool>vis(n,0);

        q.push(source);
        vis[source]=1;

        while(!q.empty())
        {
            int node= q.front();
            q.pop();

            if(node == destination) {
                return true;
            }

            for(int j=0;j<a[node].size();j++)
            {
                int neigh=a[node][j];
                if(neigh==destination)
                {
                    return true;
                }
                if(vis[neigh]==0)
                {
                    q.push(neigh);
                    vis[neigh]=1;
                }
            }
        }
        return false;
    }
};
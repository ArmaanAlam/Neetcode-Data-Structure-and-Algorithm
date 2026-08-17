class Solution {

    bool DFS(int node, int parent, vector<int> adj[], vector<int> &visit){
        visit[node] = 1;

        for(auto adjnode : adj[node]){
            if(!visit[adjnode]){
                if(!DFS(adjnode, node, adj, visit)){
                   return false;
                }
            }
            else{
                if(parent != adjnode){
                    return false;
                }
            }
        }

        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<int> adj[n+1];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visit(n, 0);

        if(!DFS(0, -1, adj, visit)){
            return false;
        }

        for(int i = 0; i < n; i++){
            if(!visit[i]){
                return false;
            }
        }

        return true;
    }
};

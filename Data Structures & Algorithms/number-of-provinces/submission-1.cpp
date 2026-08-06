class Solution {

    void DFS(vector<int> adj[], vector<int>& visit, int node){
        visit[node] = 1;
        for(auto adjnode : adj[node]){
            if(!visit[adjnode]){
                DFS(adj, visit, adjnode);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> adj[n+1];
        vector<int> visit(n, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i != j && isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                cnt++;
                DFS(adj, visit, i);
            }
        }
        
        return cnt;
    }
};
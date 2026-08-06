class Solution {

    void BFS(vector<int> adj[], vector<int>& visit, int start){

        queue<int> q;
        q.push(start);
        visit[start] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto adjnode : adj[node]){
                if(!visit[adjnode]){
                    visit[adjnode] = 1;
                    q.push(adjnode);
                }
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
                BFS(adj, visit, i);
            }
        }
        
        return cnt;
    }
};
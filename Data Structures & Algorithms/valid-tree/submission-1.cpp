class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {


        vector<int> adj[n+1];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> visit(n, 0);
        queue<pair<int, int>>q;
        visit[0] = 1;
        q.push({0, -1});

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto adjnode : adj[node]){
                if(!visit[adjnode]){
                    visit[adjnode] = 1;
                    q.push({adjnode, node});
                }
                else{
                    if(parent != adjnode){
                        return false;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!visit[i])
                return false;
        }

        return true;

    }
};

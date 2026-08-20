class Solution {

    bool DFS(vector<int> adj[], vector<int> &visit, vector<int> &pathvisit, int node){
        visit[node] = 1;
        pathvisit[node] = 1;

        for(auto adjnode : adj[node]){
            if(!visit[adjnode]){
                if(DFS(adj, visit, pathvisit, adjnode)){
                    return true;
                }
            }
            else{
                if(pathvisit[adjnode]){
                    return true;
                }
            }
        }

        pathvisit[node] = 0;

        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();
        vector<int> adj[numCourses + 1];

        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        vector<int> visit(numCourses, 0);
        vector<int> pathvisit(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            if(!visit[i]){
                if(DFS(adj, visit, pathvisit, i)){
                    return false;
                }
            }
        }

        return true;
    }
};

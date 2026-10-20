
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> ans;

        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto adjnode : adj[node]){
                indegree[adjnode]--;

                if(indegree[adjnode] == 0){
                    q.push(adjnode);
                }
            }
        }

        if(ans.size() != numCourses){
            return {};
        }

        return ans;
    }
};

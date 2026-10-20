class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        int v = words.size();
        vector<int> adj[26];

        vector<bool> present(26, false);
        int distinctCharacters = 0;

        for (string word : words) {
            for (char c : word) {
                if (!present[c - 'a']) {
                    present[c - 'a'] = true;
                    distinctCharacters++;
                }
            }
        }


        for(int i = 0; i < v-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];

            int len = min(s1.size(), s2.size());
            bool found = false;

            for(int j = 0; j < len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    found = true;
                    break;
                }
            }

            if(!found && s1.size() > s2.size()){
                return "";
            }
        }

        queue<int>q;
        vector<int> ind(26, 0);
        string ans = "";

        for(int u = 0; u < 26; u++){
            for(int v : adj[u]){
                ind[v]++;
            }
        }
        

        for(int i = 0; i < 26; i++){
            if(present[i] && ind[i] == 0){
                q.push(i);
            }
        }


        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans += char(node + 'a');
            for(int adjnode : adj[node]){
                ind[adjnode]--;
                if(ind[adjnode] == 0){
                    q.push(adjnode);
                }
            }
        }

        if(ans.size() != distinctCharacters){
            return "";
        }

        return ans;
    }
};

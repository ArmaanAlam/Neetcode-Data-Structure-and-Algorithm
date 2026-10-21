
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        mp[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* nextnode : curr->neighbors) {
                if (mp.find(nextnode) == mp.end()) {
                    mp[nextnode] = new Node(nextnode->val);
                    q.push(nextnode);
                }

                mp[curr]->neighbors.push_back(mp[nextnode]);
            }
        }

        return mp[node];
    }
};

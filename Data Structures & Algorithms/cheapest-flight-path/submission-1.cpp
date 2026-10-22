
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v, wt});
        }

        // {price, {node, flights_taken}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        // dist[node][flights] = minimum cost using exactly flights flights
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        dist[src][0] = 0;
        pq.push({0, {src, 0}});

        while (!pq.empty()) {
            int pr = pq.top().first;
            int node = pq.top().second.first;
            int stop = pq.top().second.second;
            pq.pop();

            // Ignore outdated states
            if (pr > dist[node][stop]) continue;

            // Min-heap ensures the cheapest valid destination is popped first
            if (node == dst) {
                return pr;
            }

            // No more flights allowed
            if (stop == k + 1) continue;

            for (auto it : adj[node]) {
                int adjnode = it.first;
                int price = it.second;

                int newPrice = pr + price;
                int newFlights = stop + 1;

                if (newPrice < dist[adjnode][newFlights]) {
                    dist[adjnode][newFlights] = newPrice;
                    pq.push({newPrice, {adjnode, newFlights}});
                }
            }
        }

        return -1;
    }
};

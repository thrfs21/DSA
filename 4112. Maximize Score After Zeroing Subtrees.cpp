class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<long long> dp(n);
        vector<int> order = {0};

        for (int i = 0; i < order.size(); i++) {
            int u = order[i];

            for (int v : adj[u]) {
                order.push_back(v);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            if (adj[u].empty()) {
                dp[u] = score[u];
                continue;
            }

            long long sum = 0;
            long long mn = LLONG_MAX;

            for (int v : adj[u]) {
                sum += dp[v];
                mn = min(mn, dp[v]);
            }

            if (op[u] == 1) {
                sum -= mn;
            } 
            else {
                if (mn < 0) {
                    sum -= mn;
                }
            }

            dp[u] = score[u] + sum;
        }

        return (int)dp[0];
    }
};

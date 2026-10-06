class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> grid(n + 1);

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            grid[u].push_back({v, wt});
        }

        vector<int> time(n + 1, INT_MAX);
        time[k] = 0;

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        pq.push({k, 0});

        while (pq.size() > 0) {
            int n1 = pq.top().first;
            int wt = pq.top().second;
            pq.pop();

            if (time[n1] < wt)
                continue;

            for (auto i : grid[n1]) {
                int u = i.first;
                int t2 = i.second;

                if (time[u] > wt + t2) {
                    time[u] = wt + t2;
                    pq.push({u, wt + t2});
                }
            }
        }

        int ans = -1;

        for (int i = 1; i <= n; i++) {
            if (time[i] == INT_MAX)
                return -1;

            ans = max(time[i], ans);
        }

        return ans;
    }
};

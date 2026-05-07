#include<bits/stdc++.h>
using namespace std;

int maximizeProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
    const int MOD = 1e9 + 7;

    // Build graph and indegree
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    for (const auto& e : edges) {
        int u = e[0], v = e[1];
        graph[u].push_back(v);
        indegree[v]++;
    }

    // Min-heap: {score, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            pq.push({score[i], i});
        }
    }

    int position = 1;
    long long profit = 0;

    while (!pq.empty()) {
        int s = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        profit = (profit + 1LL * position * s) % MOD;
        position++;

        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                pq.push({score[v], v});
            }
        }
    }

    return (int)profit;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2)); // Fix: each edge has exactly two elements
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> score(n);
    for (int i = 0; i < n; ++i) {
        cin >> score[i];
    }

    // Call the function and print the result
    int result = maximizeProfit(n, edges, score);
    cout << "Maximum profit: " << result << endl;

    return 0;
}

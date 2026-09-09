class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, pair<int, pair<int, pair<int, int>>>>,
                       vector<pair<int, pair<int, pair<int, pair<int, int>>>>>,
                       greater<pair<int, pair<int, pair<int, pair<int, int>>>>>>
            pq;

        vector<vector<vector<vector<int>>>> dist(
            m, vector<vector<vector<int>>>(
                   n, vector<vector<int>>(k + 1, vector<int>(5, 1e9))));

        vector<int> drow = {0, 1, 0, -1};
        vector<int> dcol = {1, 0, -1, 0};
        dist[0][0][0][4] = grid[0][0];
        pq.push({grid[0][0], {0, {0, {0, 4}}}});
        while (!pq.empty()) {
            auto [cost, temp1] = pq.top();
            pq.pop();

            auto [turns, temp2] = temp1;
            auto [i, temp3] = temp2;
            auto [j, prevDir] = temp3;

            if (cost > dist[i][j][turns][prevDir])
                continue;

            if (i == m - 1 && j == n - 1)
                return cost;

            for (int dir = 0; dir < 4; dir++) {

                int ni = i + drow[dir];
                int nj = j + dcol[dir];

                if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                    continue;

                int newTurns = turns;
                if (prevDir != 4 && prevDir != dir)
                    newTurns++;

                if (newTurns > k)
                    continue;

                int newCost = cost + grid[ni][nj];

                if (newCost < dist[ni][nj][newTurns][dir]) {

                    dist[ni][nj][newTurns][dir] = newCost;

                    pq.push({newCost, {newTurns, {ni, {nj, dir}}}});
                }
            }
        }

        return -1;
    }
};
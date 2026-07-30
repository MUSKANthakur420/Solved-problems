class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int prefix[201][205][205];
        memset(prefix, 0, sizeof(prefix));
        for (int val = 0; val <= 200; val++) {
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (val < matrix[i - 1][j - 1]) {
                        prefix[val][i][j] = prefix[val][i - 1][j] +
                                            prefix[val][i][j - 1] -
                                            prefix[val][i - 1][j - 1] + 1;
                    } else {
                        prefix[val][i][j] = prefix[val][i - 1][j] +
                                            prefix[val][i][j - 1] -
                                            prefix[val][i - 1][j - 1];
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0)
                    continue;
                int val = matrix[i][j];
                int lr = max(0, i - val), mr = min(m - 1, i + val);
                int lc = max(0, j - val), mc = min(n - 1, j + val);
                int sum = prefix[val][mr + 1][mc + 1] -
                          prefix[val][lr][mc + 1] - prefix[val][mr + 1][lc] +
                          prefix[val][lr][lc];
                if (i - val >= 0 && j - val >= 0 &&
                    matrix[i - val][j - val] > val)
                    sum--;
                if (i - val >= 0 && j + val < n &&
                    matrix[i - val][j + val] > val)
                    sum--;
                if (i + val < m && j - val >= 0 &&
                    matrix[i + val][j - val] > val)
                    sum--;
                if (i + val < m && j + val < n &&
                    matrix[i + val][j + val] > val)
                    sum--;
                if (sum == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};
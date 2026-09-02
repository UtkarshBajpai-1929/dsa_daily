class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        vector<vector<int>> id(m, vector<int>(n, -1));

        int L = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = L++;
                }
            }
        }

        int fullMask = (1 << L) - 1;
        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(n, vector<int>(1 << L, -1))
        );

        struct State {
            int r, c, mask, e;
        };

        queue<State> q;

        best[sr][sc][0] = energy;
        q.push({sr, sc, 0, energy});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == fullMask)
                    return dist;
                if (e == 0 && classroom[r][c] != 'R')
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }
                    if (ne <= best[nr][nc][nmask])
                        continue;

                    best[nr][nc][nmask] = ne;
                    q.push({nr, nc, nmask, ne});
                }
            }

            dist++;
        }

        return -1;
    }
};
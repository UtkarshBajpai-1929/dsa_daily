class Solution {
public:
    class SegTree {
        int n;
        vector<int> tree;

    public:
        SegTree(vector<int>& a) {
            n = a.size();
            tree.resize(4 * n);
            build(1, 0, n - 1, a);
        }
        void build(int node, int l, int r, vector<int>& a) {
            if (l == r) {
                tree[node] = a[l];
                return;
            }

            int mid = l + (r - l) / 2;

            build(2 * node, l, mid, a);
            build(2 * node + 1, mid + 1, r, a);

            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }

        int query(int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql)
                return 0;

            if (ql <= l && r <= qr)
                return tree[node];

            int mid = l + (r - l) / 2;

            return max(
                query(2 * node, l, mid, ql, qr),
                query(2 * node + 1, mid + 1, r, ql, qr)
            );
        }

        int query(int l, int r) {
            if (l > r)
                return 0;

            return query(1, 0, n - 1, l, r);
        }
    };

    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>>& queries
    ) {
        int n = s.size();
        int initialOne = 0;

        for (char c : s) {
            if (c == '1')
                initialOne++;
        }
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (s[i] == '1');
        }
        vector<char> type;
        vector<int> start;
        vector<int> end;
        vector<int> len;

        for (int i = 0; i < n;) {

            int j = i;

            while (j < n && s[j] == s[i])
                j++;

            type.push_back(s[i]);
            start.push_back(i);
            end.push_back(j - 1);
            len.push_back(j - i);

            i = j;
        }

        int m = len.size();
        vector<int> groupId(n);

        for (int g = 0; g < m; g++) {
            for (int i = start[g]; i <= end[g]; i++) {
                groupId[i] = g;
            }
        }
        vector<int> gain(m, 0);

        for (int i = 1; i + 1 < m; i++) {

            if (type[i] == '1' &&
                type[i - 1] == '0' &&
                type[i + 1] == '0') {

                gain[i] = len[i - 1] + len[i + 1];
            }
        }

        SegTree st(gain);

        vector<int> answer;
        for (auto& q : queries) {

            int l = q[0];
            int r = q[1];

            int leftGroup = groupId[l];
            int rightGroup = groupId[r];

            int bestGain = 0;
            int L = leftGroup + 2;
            int R = rightGroup - 2;

            if (L <= R)
                bestGain = st.query(L, R);
            for (int g = max(1, leftGroup);
                 g <= min(m - 2, leftGroup + 2);
                 g++) {

                if (type[g] != '1')
                    continue;

                if (type[g - 1] != '0' ||
                    type[g + 1] != '0')
                    continue;
                int leftZeros =
                    max(0,
                        min(end[g - 1], r)
                        - max(start[g - 1], l)
                        + 1);

                int rightZeros =
                    max(0,
                        min(end[g + 1], r)
                        - max(start[g + 1], l)
                        + 1);
                if (start[g] >= l && end[g] <= r &&
                    leftZeros > 0 && rightZeros > 0) {

                    bestGain =
                        max(bestGain,
                            leftZeros + rightZeros);
                }
            }
            for (int g = max(1, rightGroup - 2);
                 g <= min(m - 2, rightGroup);
                 g++) {

                if (type[g] != '1')
                    continue;

                if (type[g - 1] != '0' ||
                    type[g + 1] != '0')
                    continue;

                int leftZeros =
                    max(0,
                        min(end[g - 1], r)
                        - max(start[g - 1], l)
                        + 1);

                int rightZeros =
                    max(0,
                        min(end[g + 1], r)
                        - max(start[g + 1], l)
                        + 1);

                if (start[g] >= l && end[g] <= r &&
                    leftZeros > 0 && rightZeros > 0) {

                    bestGain =
                        max(bestGain,
                            leftZeros + rightZeros);
                }
            }

            answer.push_back(initialOne + bestGain);
        }
        return answer;
    }
};
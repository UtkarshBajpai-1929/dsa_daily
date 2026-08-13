class SegmentTree {
    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;

        Node() {
            leftChar = rightChar = '#';
            prefix = suffix = best = len = 0;
        }

        Node(char c) {
            leftChar = rightChar = c;
            prefix = suffix = best = len = 1;
        }
    };

    vector<Node> tree;
    string &s;

    Node merge(Node &L, Node &R) {
        if (L.len == 0) return R;
        if (R.len == 0) return L;

        Node res;

        res.len = L.len + R.len;
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        // Prefix
        res.prefix = L.prefix;

        if (L.prefix == L.len && L.rightChar == R.leftChar) {
            res.prefix = L.len + R.prefix;
        }

        // Suffix
        res.suffix = R.suffix;

        if (R.suffix == R.len && L.rightChar == R.leftChar) {
            res.suffix = R.len + L.suffix;
        }

        // Best answer inside this segment
        res.best = max(L.best, R.best);

        // Join suffix of L + prefix of R
        if (L.rightChar == R.leftChar) {
            res.best = max(res.best, L.suffix + R.prefix);
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

public:
    SegmentTree(string &str) : s(str) {
        tree.resize(4 * s.size());
        build(1, 0, s.size() - 1);
    }

    void update(int idx, char c) {
        update(1, 0, s.size() - 1, idx, c);
    }

    int getBest() {
        return tree[1].best;
    }
};

class Solution {
public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        SegmentTree st(s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            st.update(idx, c);

            ans.push_back(st.getBest());
        }

        return ans;
    }
};
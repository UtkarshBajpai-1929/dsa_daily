class Solution {
public:
    long long lim = 1000000;

    long long ncr(int n, int r) {
        if (r < 0 || r > n) return 0;

        r = min(r, n - r);
        long long x = 1;

        for (int i = 1; i <= r; i++) {
            if (x > lim * i / (n - r + i))
                return lim + 1;

            x = x * (n - r + i) / i;

            if (x > lim)
                return lim + 1;
        }

        return x;
    }

    long long cnt(vector<int>& f, int n) {
        long long x = 1;
        int r = n;

        for (int v : f) {
            if (!v) continue;

            long long c = ncr(r, v);

            if (x > lim / c)
                return lim + 1;

            x *= c;

            if (x > lim)
                return lim + 1;

            r -= v;
        }

        return x;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> f(26, 0);

        for (char c : s)
            f[c - 'a']++;

        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (f[i] % 2)
                mid = 'a' + i;

            f[i] /= 2;
        }

        int n = s.size() / 2;

        if (cnt(f, n) < k)
            return "";

        string a;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (!f[j]) continue;

                f[j]--;

                long long x = cnt(f, n - i - 1);

                if (k > x) {
                    k -= x;
                    f[j]++;
                }
                else {
                    a += 'a' + j;
                    break;
                }
            }
        }

        string b = a;
        reverse(b.begin(), b.end());

        if (mid)
            return a + mid + b;

        return a + b;
    }
};
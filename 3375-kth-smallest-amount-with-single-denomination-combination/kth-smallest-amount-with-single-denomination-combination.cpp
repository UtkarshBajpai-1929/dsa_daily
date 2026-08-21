class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b) {
        return std::gcd(a, b);
    }

    ll lcmLimited(ll a, ll b, ll limit) {
        ll g = gcd(a, b);
        a /= g;

        if (a > limit / b)
            return limit + 1;

        return a * b;
    }

    ll countAmounts(const vector<int>& coins, ll x) {
        int n = coins.size();
        ll ans = 0;

        // Inclusion-exclusion over all subsets
        for (int mask = 1; mask < (1 << n); mask++) {
            ll curLCM = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    curLCM = lcmLimited(curLCM, coins[i], x);

                    if (curLCM > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            ll cnt = x / curLCM;

            if (bits & 1)
                ans += cnt;
            else
                ans -= cnt;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        // Remove redundant coins
        sort(coins.begin(), coins.end());

        vector<int> useful;

        for (int coin : coins) {
            bool redundant = false;

            for (int x : useful) {
                if (coin % x == 0) {
                    redundant = true;
                    break;
                }
            }

            if (!redundant)
                useful.push_back(coin);
        }

        ll lo = 1;
        ll hi = 1LL * useful[0] * k;

        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;

            if (countAmounts(useful, mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};
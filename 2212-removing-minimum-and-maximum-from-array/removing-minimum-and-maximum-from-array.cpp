class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = 0, mx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mn]) mn = i;
            if (nums[i] > nums[mx]) mx = i;
        }

        int i = min(mn, mx);
        int j = max(mn, mx);

        return min({
            j + 1,
            n - i,
            i + 1 + n - j
        });
    }
};
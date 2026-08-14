class Solution {
public:
   int helper(vector<int> &nums, int i, int j){
    vector<int> dp(j-i);
    if(j-i<2){
        return nums[i];
    }
    dp[0] = nums[i];
    dp[1] = max(nums[i], nums[i+1]);

    for(int x=2; x<j-i; x++){
        dp[x] = max(dp[x-1], dp[x-2] + nums[i+x]);
    }
    return dp[j-i-1];
   }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(helper(nums, 0, n-1), helper(nums, 1, n));
    }
};
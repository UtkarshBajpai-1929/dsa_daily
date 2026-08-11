class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums){
            sum+=num;
        }
        if(sum%2 != 0) return false;

        int tg = sum/2;
        vector<bool> dp(tg+1, false);
        dp[0] = true;
        for(auto num: nums){
            for(int s = tg; s>=num; s--){
                dp[s] = dp[s] || dp[s-num];
            }
        }
        return dp[tg];
    }
};
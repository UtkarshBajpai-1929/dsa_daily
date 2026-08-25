class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int a = 0;
        int curr = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i=n-1; i>=0; i--){
            if(nums[i]%k == 0){
                curr = nums[i]/k;
                a = max(curr, a);
            }
        }
        int ans = k*a + k;
        for(int i=1; i<=a; i++){
            int num = k*i;
            if(s.find(num) == s.end()) {
                ans = num;
                break;
            }
        }

        return ans;
    }
};
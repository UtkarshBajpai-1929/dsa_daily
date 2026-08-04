class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int l = INT_MIN, s = INT_MAX;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            l = max(nums[i] ,l);
            s = min(nums[i], s);
            m[nums[i]] = 1;
        }
        vector<int> ans;
        for(int i=s; i<=l; i++){
            if(m.find(i) == m.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
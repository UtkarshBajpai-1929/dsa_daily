class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(m.find(nums[i]) != m.end()){
                m[nums[i]]++;
            }else{
                m[nums[i]] = 1;
            }
        }
        priority_queue<pair<int,int>> pq;
        for(auto &p : m){
            pq.push({p.second, p.first});
        }
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
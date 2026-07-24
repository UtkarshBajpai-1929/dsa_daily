class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
       int n =  nums.size();
        unordered_set<int> s;
        s.insert(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                for(int k=j; k<n; k++){
                    if(i == k|| j == k){
                        continue;
                    }else{int x = nums[i]^nums[j]^nums[k];
                    if(s.size() == 2048) {
                        return 2048;
                    }
                    s.insert(x);
                    }
                    
                }
            }
        }
        return s.size();
    }
};
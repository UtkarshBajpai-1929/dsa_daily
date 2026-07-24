class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                for(int j=0; j<=i; j++){
                    if(nums[j]> nums[i]){
                        ans[i] = nums[j];
                        break;
                    }else{
                        ans[i] = -1;
                    }
                }
            }else{
                ans[i] = st.top();
            }
              st.push(nums[i]);
        }
        return ans;
    }
};
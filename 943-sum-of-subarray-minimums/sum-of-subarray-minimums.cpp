class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       //make all the subarrays and then take minimum from them and sum up 
       int n = arr.size();
       long long sum = 0;
       stack<int> st;
       vector<int> left(n), right(n);
       for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
       }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
       }
      
       for(int i=0; i<n; i++){
        long long lefti = i-left[i];
        long long righti = right[i] - i;
        sum += (lefti* righti *arr[i]);
       }
       long long mod = 1e9 + 7;
       return sum%mod;
    }
};
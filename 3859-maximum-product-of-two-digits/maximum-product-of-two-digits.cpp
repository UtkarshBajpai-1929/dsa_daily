class Solution {
public:
    int maxProduct(int n) {
        int first = 0;
        vector<int>v(10, 0);
        while(n>0){
            v[n%10]++;
            first = max(first, n%10);
            n/=10;
        }
        v[first]--;
        int ans = INT_MIN;
        for(int i=9; i>=0; i--){
            if(v[i]>0){
                ans = max(ans, first*i);
            }
        }
        return ans;
    }
};
class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(), compare);
        for(auto &box: boxTypes){
            int n = box[0];
            int units = box[1];

            if(n<=truckSize){
                ans+=(n*units);
                truckSize-=n;
            }else if(truckSize < n){
                ans+=(truckSize*units);
                break;
            }
        }
        return ans;
    }
};
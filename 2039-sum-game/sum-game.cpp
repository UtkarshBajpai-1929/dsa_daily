class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int lq = 0, rq = 0;
        int lSum = 0, rSum = 0;
        for(int i=0; i<n/2; i++){
            if(num[i] == '?'){
                lq++;
            }else{
                lSum += num[i]-'0';
            }
        }
        for(int i=n/2; i<n; i++){
            if(num[i] == '?'){
                rq++;
            }else{
                rSum += num[i]-'0';
            }
        }
        int diff = lSum - rSum;
        int qDiff = lq-rq;

        if(qDiff%2 != 0){
            return true;
        }

        return diff != -9*qDiff/2;
    }
};
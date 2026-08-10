class Solution {
public:
    bool isValid(char a){
        if(a>='0' && a<='9'){
            return true;
        }
        return false;
    }
    int secondHighest(string s) {
        int ans = -1;
        int m1 = -1;
        for(int i=0; i<s.length(); i++){
            if(isValid(s[i]) && int(s[i]-'0') > m1){
                ans = m1;
                m1 = int(s[i]-'0');
            }else if(isValid(s[i]) && int(s[i]-'0')>ans && int(s[i] - '0') != m1){
                ans = int(s[i]-'0');
            }
        }
        return ans;
    }
};
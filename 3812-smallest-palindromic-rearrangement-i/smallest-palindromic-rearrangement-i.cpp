class Solution {
public:
    string smallestPalindrome(string s) {
        int l = s.length();
        int mid = l/2;
        vector<int>freq(26, 0);
        for(int i=0; i<l/2; i++){
            freq[s[i]-'a']++;
        }
        string ans = "";
        for(int i=0; i<26; i++){
            ans.append(freq[i], 'a'+i);
        }
        string rev = "";
        for(int i=ans.length()-1; i>=0; i--){
            rev.append(1, ans[i]);
        }
        if(l%2!=0){
            ans.append(1, s[l/2]);
            ans = ans+rev;
        }else{
            ans = ans + rev;
        } 
        return ans;
    }
};
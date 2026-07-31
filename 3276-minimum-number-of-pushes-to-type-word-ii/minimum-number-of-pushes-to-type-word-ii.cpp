class Solution {
public:
    int minimumPushes(string word) {
         int ans = 0;

        if (word.length() <= 8)
            return word.length();
    vector<pair<int, char>> freq(26);
        for(int i=0; i<word.length(); i++){
            freq[word[i]-'a'].first++;
            freq[word[i]-'a'].second = word[i];
        }
        sort(freq.begin(), freq.end(), greater<pair<int, char>>());
        int i = 0;
        while(i<8){
            if(freq[i].first > 0){
                ans+=freq[i].first;
            }
            i++;
        }
        while(i>=8 && i<16){
            if(freq[i].first > 0){
ans+=(2*freq[i].first);
            }
            i++;
        }
        while(i>=16 && i<24){
             if(freq[i].first > 0){
                ans+=(3 * freq[i].first);
            }
            i++;
        }
        while(i>=24 && i<freq.size()){
             if(freq[i].first > 0){
                ans+=(4 * freq[i].first);
            }
            i++;
        }
        return ans;
    }
};
class Solution {
public:
    bool isDigit(char a) {
        if (a >= '0' && a <= '9') {
            return true;
        }
        return false;
    }

    int myAtoi(string s) {
        long long ans = 0;
        stack<char> st;

        char sign = '+';       

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == ' ' && (i == 0 || s[i - 1] == ' ')) {
                continue;
            }
            else if (isDigit(s[i])) {
                st.push(s[i]);
            }
            else if ((s[i] == '-' || s[i] == '+') &&
                     (i == 0 || s[i - 1] == ' ')) {
                sign = s[i];
            }
            else {
                break;
            }
        }

        int i = 0;

        while (!st.empty()) {

            int a = st.top() - '0';
            st.pop();

        
            if (i >= 10) {
                if (a != 0)
                    ans = (long long)INT_MAX + 1;
            }
            else {
                long long value = a * (long long)pow(10, i);

                if (ans > (long long)INT_MAX + 1 - value) {
                    ans = (long long)INT_MAX + 1;
                }
                else {
                    ans += value;
                }
            }

            i++;
        }

        if (sign == '-')
            ans = -ans;

        if (ans > INT_MAX)
            return INT_MAX;

        if (ans < INT_MIN)
            return INT_MIN;

        return (int)ans;
    }
};
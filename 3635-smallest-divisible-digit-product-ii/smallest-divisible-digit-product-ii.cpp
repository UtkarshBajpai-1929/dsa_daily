class Solution {
public:
    int digit_2[10], digit_3[10], digit_5[10], digit_7[10];
    int count_of_2, count_of_3, count_of_5, count_of_7;
    vector<vector<int>> min_digits_for_23;

    void initDigitFactors() {
        int f2[10] = {0,0,1,0,2,0,1,0,3,0};
        int f3[10] = {0,0,0,1,0,0,1,0,0,2};
        int f5[10] = {0,0,0,0,0,1,0,0,0,0};
        int f7[10] = {0,0,0,0,0,0,0,1,0,0};
        for (int i = 0; i < 10; i++) {
            digit_2[i] = f2[i];
            digit_3[i] = f3[i];
            digit_5[i] = f5[i];
            digit_7[i] = f7[i];
        }
    }

    int minDigitsNeeded(int need_2, int need_3) {
        need_2 = max(0, min(need_2, count_of_2));
        need_3 = max(0, min(need_3, count_of_3));
        return min_digits_for_23[need_2][need_3];
    }

    bool isFeasible(long long remainingLength, long long need_2, long long need_3,
                     long long need_5, long long need_7) {
        need_2 = max(0LL, need_2);
        need_3 = max(0LL, need_3);
        need_5 = max(0LL, need_5);
        need_7 = max(0LL, need_7);
        if (need_5 + need_7 > remainingLength) return false;
        long long leftoverLength = remainingLength - need_5 - need_7;
        return (long long)minDigitsNeeded((int)need_2, (int)need_3) <= leftoverLength;
    }

    string buildSuffix(long long remainingLength, long long need_2, long long need_3,
                        long long need_5, long long need_7) {
        string result;
        result.reserve(remainingLength);
        need_2 = max(0LL, need_2);
        need_3 = max(0LL, need_3);
        need_5 = max(0LL, need_5);
        need_7 = max(0LL, need_7);
        for (long long pos = 0; pos < remainingLength; pos++) {
            long long slotsAfter = remainingLength - pos - 1;
            for (int candidate = 1; candidate <= 9; candidate++) {
                long long new2 = max(0LL, need_2 - digit_2[candidate]);
                long long new3 = max(0LL, need_3 - digit_3[candidate]);
                long long new5 = max(0LL, need_5 - digit_5[candidate]);
                long long new7 = max(0LL, need_7 - digit_7[candidate]);
                if (isFeasible(slotsAfter, new2, new3, new5, new7)) {
                    result.push_back('0' + candidate);
                    need_2 = new2; need_3 = new3; need_5 = new5; need_7 = new7;
                    break;
                }
            }
        }
        return result;
    }

    string smallestNumber(string num, long long t) {
        initDigitFactors();

        count_of_2 = count_of_3 = count_of_5 = count_of_7 = 0;
        long long remaining_t = t;
        while (remaining_t % 2 == 0) { remaining_t /= 2; count_of_2++; }
        while (remaining_t % 3 == 0) { remaining_t /= 3; count_of_3++; }
        while (remaining_t % 5 == 0) { remaining_t /= 5; count_of_5++; }
        while (remaining_t % 7 == 0) { remaining_t /= 7; count_of_7++; }
        if (remaining_t != 1) return "-1";

        int length = num.size();
        vector<int> digits(length);
        for (int i = 0; i < length; i++) digits[i] = num[i] - '0';

        
        min_digits_for_23.assign(count_of_2 + 1, vector<int>(count_of_3 + 1, 0));
        for (int need_2 = 0; need_2 <= count_of_2; need_2++) {
            for (int need_3 = 0; need_3 <= count_of_3; need_3++) {
                if (need_2 == 0 && need_3 == 0) continue;
                int best = INT_MAX;
                int maxNeed = max(need_2, need_3);
                for (int m = 0; m <= maxNeed; m++) {
                    int cost = m;
                    if (need_2 > m) cost += (need_2 - m + 2) / 3; // ceil div by 3 (8's)
                    if (need_3 > m) cost += (need_3 - m + 1) / 2; // ceil div by 2 (9's)
                    best = min(best, cost);
                }
                min_digits_for_23[need_2][need_3] = best;
            }
        }

    
        vector<long long> prefix_2(length + 1, 0), prefix_3(length + 1, 0);
        vector<long long> prefix_5(length + 1, 0), prefix_7(length + 1, 0);
        int firstZeroIndex = length;
        for (int i = 0; i < length; i++) {
            int d = digits[i];
            if (d == 0 && firstZeroIndex == length) firstZeroIndex = i;
            int f2 = (d == 0) ? 0 : digit_2[d];
            int f3 = (d == 0) ? 0 : digit_3[d];
            int f5 = (d == 0) ? 0 : digit_5[d];
            int f7 = (d == 0) ? 0 : digit_7[d];
            prefix_2[i+1] = prefix_2[i] + f2;
            prefix_3[i+1] = prefix_3[i] + f3;
            prefix_5[i+1] = prefix_5[i] + f5;
            prefix_7[i+1] = prefix_7[i] + f7;
        }

    
        if (firstZeroIndex == length) {
            long long need_2 = count_of_2 - prefix_2[length];
            long long need_3 = count_of_3 - prefix_3[length];
            long long need_5 = count_of_5 - prefix_5[length];
            long long need_7 = count_of_7 - prefix_7[length];
            if (need_2 <= 0 && need_3 <= 0 && need_5 <= 0 && need_7 <= 0) {
                return num;
            }
        }

        string answer = "";
        bool found = false;
        int lastPositionToTry = min(length - 1, firstZeroIndex);
        for (int i = lastPositionToTry; i >= 0 && !found; i--) {
            long long need_2 = count_of_2 - prefix_2[i];
            long long need_3 = count_of_3 - prefix_3[i];
            long long need_5 = count_of_5 - prefix_5[i];
            long long need_7 = count_of_7 - prefix_7[i];
            long long slotsAfter = length - 1 - i;
            for (int candidate = digits[i] + 1; candidate <= 9; candidate++) {
                long long new2 = need_2 - digit_2[candidate];
                long long new3 = need_3 - digit_3[candidate];
                long long new5 = need_5 - digit_5[candidate];
                long long new7 = need_7 - digit_7[candidate];
                if (isFeasible(slotsAfter, new2, new3, new5, new7)) {
                    answer = num.substr(0, i) + char('0' + candidate) +
                             buildSuffix(slotsAfter, new2, new3, new5, new7);
                    found = true;
                    break;
                }
            }
        }

        if (found) return answer;

        long long minRequiredLength = (long long)minDigitsNeeded(count_of_2, count_of_3) + count_of_5 + count_of_7;
        long long finalLength = max((long long)(length + 1), minRequiredLength);
        return buildSuffix(finalLength, count_of_2, count_of_3, count_of_5, count_of_7);
    }
};
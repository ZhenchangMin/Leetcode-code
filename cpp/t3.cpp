#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool allowed(const map<char, int>& cnt) {
        for (auto i : cnt) {
            if (i.second > 1) return false;
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        map<char, int> cnt;
        int answer = 0, cur_length = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            cnt[s[i]] = 1;
            cur_length = 1;
            for (int j = i + 1; j < len; j++) {
                cnt[s[j]]++;
                if (!allowed(cnt)) {
                    cur_length = j - i;
                    break;
                } else {
                    cur_length = j - i + 1;
                }
            }
            answer = max(answer, cur_length);
            cnt.clear();
        }
        return answer;
    }
};

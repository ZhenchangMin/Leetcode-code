#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(128, 0);
        int left = 0, ans = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            cnt[s[right]]++;
            while (cnt[s[right]] > 1) {
                cnt[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

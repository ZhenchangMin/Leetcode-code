#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        map<char, int> cnt;
        int ans = 0;
        for (int right = 0; right < s.size(); right++){
            cnt[s[right]]++;
            while(cnt[s[right]] > 2){
                cnt[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
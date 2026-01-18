#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int m = 0, now = 0;
        for (int i = 0; i < k; i++) if (isVowel(s[i])) now++;
        m = max(m, now);
        for (int i = k; i < n; i++){
            now = now - isVowel(s[i - k]) + isVowel(s[i]); // use this formula to replace double pointers
            m = max(m, now);
        }
        return m;
    }
};
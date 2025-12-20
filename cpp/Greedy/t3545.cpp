#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> alphabet(26);
        int totalAlphas = 0;
        for (char c : s){
            if (alphabet[c - 'a'] == 0) totalAlphas++;
            alphabet[c - 'a']++;
        }
        int gap = totalAlphas - k;
        if (gap <= 0) return 0;
        sort(alphabet.begin(), alphabet.end());
        int ans = 0;
        int posIndex = 0;
        for (int i = 0; i < alphabet.size(); i++){
            if (alphabet[i] > 0){
                posIndex = i;
                break;
            }
        }
        for (int i = posIndex; i < posIndex + gap; i++){
            ans += alphabet[i];
        }
        return ans;
    }
};
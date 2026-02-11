#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        ll total = 0;
        for (int a : apple) total += a;
        sort(capacity.begin(), capacity.end(), greater<int>());
        ll ans = 0;
        ll current_total = 0;
        for (int i = 0; i < capacity.size(); i++){
            ans++;
            current_total += capacity[i];
            if (current_total >= total) break;
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> needed(n);
        for (int i = 0; i < n; ++i) {
            needed[i] = capacity[i] - rocks[i];
        }
        sort(needed.begin(), needed.end());
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (needed[i] <= additionalRocks) {
                additionalRocks -= needed[i];
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};
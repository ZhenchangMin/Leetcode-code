#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int, int> cnt;
        int n = static_cast<int>(arrivals.size());
        vector<int> kept(n, 0);
        int discarded = 0;

        for (int i = 0; i < n; ++i) {
            int x = arrivals[i];

            if (i >= w) {
                int out = arrivals[i - w];
                cnt[out] -= kept[i - w];
            }

            if (cnt[x] >= m) {
                ++discarded;
            } else {
                kept[i] = 1;
                ++cnt[x];
            }
        }

        return discarded;
    }
};

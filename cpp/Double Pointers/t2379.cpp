#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = 0;
        int cur_min = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                cur_min++;
            }
        }
        ans = cur_min;
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W') {
                cur_min++;
            }
            if (blocks[i - k] == 'W') {
                cur_min--;
            }
            ans = min(ans, cur_min);
        }
        return ans;
    }
};
#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int> cnt;

        long long cur_sum = 0;
        long long ans = 0;
        int distinct = 0;

        for (int i = 0; i < k; i++) {
            cur_sum += nums[i];
            if (++cnt[nums[i]] == 1) distinct++;
        }

        if (distinct >= m) ans = cur_sum;

        for (int i = k; i < nums.size(); i++) {
            if (--cnt[nums[i - k]] == 0) distinct--;
            cur_sum -= nums[i - k];

            cur_sum += nums[i];
            if (++cnt[nums[i]] == 1) distinct++;

            if (distinct >= m)
                ans = max(ans, cur_sum);
        }

        return ans;
    }
};

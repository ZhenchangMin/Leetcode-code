#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> res(nums.size(), -1);
        long long windowSum = 0;
        int curr = k;
        if (2 * k + 1 > nums.size()) return res;
        for (int i = 0; i < 2 * k + 1; i++){
            windowSum += nums[i];
        }
        res[curr] = windowSum / (2 * k + 1);
        while (curr + k + 1< nums.size()){
            windowSum -= nums[curr - k];
            windowSum += nums[curr + k + 1];
            curr++;
            res[curr] = windowSum / (2 * k + 1);
        }
        return res;
    }
};
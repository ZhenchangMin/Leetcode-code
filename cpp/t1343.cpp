#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = k * threshold, n = arr.size();
        int curr = accumulate(arr.begin(), arr.begin() + k, 0), ans = 0;
        if (curr >= sum) ans++;
        for (int i = k; i < n; i++) {
            curr += arr[i] - arr[i - k];
            if (curr >= sum) ans++;
        }
        return ans;
    }
};
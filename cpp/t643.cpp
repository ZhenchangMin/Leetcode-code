#include <bits/stdc++.h>
#define INF 1e10;
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        double m = -INF;
        for (int i = 0; i < k; i++) sum += nums[i];
        m = max(m, sum);
        for (int i = k; i < n; i++){
            sum += nums[i] - nums[i - k];
            m = max(m, sum);
        }
        return m / k;
    }
};

// Answer
//class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
//         int ans=0;//用来统计答案
//         int max_count=INT_MIN;
//         int len=nums.size();
//         for(int i=0;i<len;i++)
//         {
//         ans+=nums[i];
//         if(i<k-1)continue;
//         max_count=max(max_count,ans);
//         ans-=nums[i-k+1];
//         }
//         return (double)max_count/k;
//     }
// };
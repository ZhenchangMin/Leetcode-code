#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int left = 0, right = nums.size() - 1;
        int r = -1, l = -1;
        int mid = (right + left) / 2;
        while(left <= right){
            mid = (right + left) / 2;
            if (nums[mid] == target) break;
            if (nums[mid] < target){
                left = mid + 1;
                mid = (right + left) / 2;
            }
            else {
                right = mid - 1;
                mid = (right + left) / 2;
            }
        }
        if (left > right) return {-1, -1};
        if (nums[mid] != target) return {-1, -1};
        l = r = mid;
        int big = mid + 1;
        int small = mid - 1;
        while(big < nums.size() && nums[big] == target){
            r++;
            big++;
        }
        while(small >= 0 && nums[small] == target){
            l--;
            small--;
        }
        return {l, r};
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> longer(cardPoints.size()+k, 0);
        for (int i = 0; i < cardPoints.size(); i++){
            longer[i] = cardPoints[i];
        }
        for (int i = 0; i < k; i++){
            longer[i+cardPoints.size()] = cardPoints[i];
        }
        int cur_sum = 0;
        int cur_max = 0;
        for (int i = cardPoints.size() - k; i < cardPoints.size(); i++){
            cur_sum += longer[i];
        }
        cur_max = cur_sum;
        for (int i = 0; i < k; i++){
            cur_sum += longer[i+cardPoints.size()] - longer[i+cardPoints.size()-k];
            cur_max = max(cur_max, cur_sum);
        }
        return cur_max;
    }
};
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
        int mymax = 0;
        for (int i = cardPoints.size() - k; i < cardPoints.size(); i++){
            cur_sum += longer[i];
        }
        mymax = cur_sum;
        for (int i = 0; i < k; i++){
            cur_sum += longer[i+cardPoints.size()] - longer[i+cardPoints.size()-k];
            mymax = max(mymax, cur_sum);
        }
        return mymax;
    }
};
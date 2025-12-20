#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int a) {
        return parent[a] == a ? a : parent[a] = find(parent[a]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                swap(a, b);
            }
            parent[b] = a;
            rank[a] += rank[b];
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j]) {
                    dsu.unite(i, j);
                }
            }
        }
        unordered_set<int> provinces;
        for (int i = 0; i < n; ++i) {
            provinces.insert(dsu.find(i));
        }
        return provinces.size();
    }
};
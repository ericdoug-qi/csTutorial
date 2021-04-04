#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s);
};


int Solution::findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int child = 0, cookie = 0;
    while(child < g.size() && cookie < s.size()) {
        if (g[child] <= s[cookie]){
            ++child;
        }
        cookie++;
    }

    return child;
}

int main() {
    Solution solution;
    vector<int> g;
    g.push_back(1);
    g.push_back(2);
    g.push_back(3);
    vector<int> s;
    s.push_back(1);
    s.push_back(1);
    cout << solution.findContentChildren(g, s);
    // std::cout << solution.findContentChildren(g, s) << std::endl;

    return 0;
}
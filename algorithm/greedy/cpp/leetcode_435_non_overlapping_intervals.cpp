#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals);
};

int Solution::eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.empty()) {
        return 0;
    }

    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
    });

    int total = 0, prev = intervals[0][1];
    for (int i = 1; i < n; ++i) {
        if (intervals[i][0] < prev){
            ++total;
        }else {
            prev = intervals[i][1];
        }
    }
    return total;


}

int main()
{
    Solution solution;

    vector<int> arr = {1, 2, 3};
    cout << arr << endl;


}


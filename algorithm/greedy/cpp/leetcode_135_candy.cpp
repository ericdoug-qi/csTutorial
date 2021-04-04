#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings);
};

int Solution::candy(vector<int>& ratings) 
{
    int n = ratings.size();

    if (n < 2)
    {
        return n;
    }

    vector<int> nums(n, 1);

    for (int i = 1; i < n; ++i)
    {
        if (ratings[i] > ratings[i - 1])
        {
            nums[i] = nums[i - 1] + 1;
        }
    }

    for (int i = n - 1; i > 0; --i)
    {
        if (ratings[i] < ratings[i - 1])
        {
            nums[i - 1] = std::max(nums[i - 1], nums[i] + 1);
        }
    }

    return std::accumulate(nums.begin(), nums.end(), 0);
}


int main() {
    Solution solution;
    vector<int> candy_info;
    candy_info.push_back(1);
    candy_info.push_back(0);
    candy_info.push_back(2);

    cout << solution.candy(candy_info);
    
    return 0;
}
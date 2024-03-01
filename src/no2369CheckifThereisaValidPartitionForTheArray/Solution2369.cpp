#include <vector>

using namespace std;

class Solution2369 {
   public:
    bool validPartition(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return false;
        }
        vector<bool> dp(n + 1, false);
        //init
        dp[0] = true;
        dp[2] = nums[0] == nums[1];
        for (int i = 3; i <= n; i++)
        {
            dp[i] = (judge(nums, i - 1, 2) && dp.at(i - 2)) ||
                    (judge(nums, i - 1, 3) && dp.at(i - 3));
        }
        return dp[n];
    }

   private:
    bool judge(vector<int>& nums, int idx, int len)
    {
        if (len == 2)
        {
            return nums.at(idx) == nums.at(idx - 1);
        }
        if (nums.at(idx) == nums.at(idx - 1))
        {
            return nums.at(idx - 1) == nums[idx - 2];
        }
        if (nums.at(idx) - nums.at(idx - 1) == 1)
        {
            return nums.at(idx - 1) - nums[idx - 2] == 1;
        }
        return false;
    }
};
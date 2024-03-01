#include <vector>

using namespace std;

class Solution2917 {
   public:
    int findKOr(vector<int>& nums, int k)
    {
        int kor = 0;
        if (k > nums.size())
        {
            return kor;
        }
        if (k == 1)
        {
            for (int num : nums)
            {
                kor |= num;
            }
            return kor;
        }
        int bitVal = 1;
        for (int i = 0; i < 31; i++)
        {
            int cnt = 0;
            for (int num : nums)
            {
                if ((num & bitVal) == bitVal)
                {
                    cnt++;
                }
                if (cnt >= k)
                {
                    kor |= bitVal;
                    break;
                }
            }
            bitVal <<= 1;
        }
        return kor;
    }
};
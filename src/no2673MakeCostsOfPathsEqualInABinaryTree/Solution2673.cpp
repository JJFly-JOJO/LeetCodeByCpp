#include <vector>
#include <valarray>

using namespace std;

class Solution2673
{
public:
    int addCnt = 0;

    int minIncrements(int n, vector<int> &cost)
    {
        addPathVal(1, n, cost);
        return addCnt;
    }

    int addPathVal(int idx, int n, vector<int> &cost)
    {
        if (idx > n)
        {
            return 0;
        }
        int leftVal = addPathVal(2 * idx, n, cost);
        int rightVal = addPathVal(2 * idx + 1, n, cost);
        int maxVal = leftVal > rightVal ? leftVal : rightVal;
        addCnt += abs(leftVal - rightVal);
        return maxVal + cost.at(idx - 1);
    }
};

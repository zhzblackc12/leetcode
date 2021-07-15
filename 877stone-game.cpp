#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 定义 f[l][r]f[l][r] 为考虑区间 [l,r][l,r]，在双方都做最好选择的情况下，先手与后手的最大得分差值为多少。

// 那么 f[1][n]f[1][n] 为考虑所有石子，先手与后手的得分差值：

// f[1][n] > 0f[1][n]>0，则先手必胜，返回 True
// f[1][n] < 0f[1][n]<0，则先手必败，返回 False
// 不失一般性的考虑 f[l][r]f[l][r] 如何转移。根据题意，只能从两端取石子（令 pilespiles 下标从 11 开始），共两种情况：

// 从左端取石子，价值为 piles[l - 1]piles[l−1]；取完石子后，原来的后手变为先手，从 [l + 1, r][l+1,r] 区间做最优决策，所得价值为 f[l + 1][r]f[l+1][r]。因此本次先手从左端点取石子的话，双方差值为：
// piles[l - 1] - f[l + 1][r]
// piles[l−1]−f[l+1][r]

// 从右端取石子，价值为 piles[r - 1]piles[r−1]；取完石子后，原来的后手变为先手，从 [l, r - 1][l,r−1] 区间做最优决策，所得价值为 f[l][r - 1]f[l][r−1]。因此本次先手从右端点取石子的话，双方差值为：
// piles[r - 1] - f[l][r - 1]
// piles[r−1]−f[l][r−1]

// 双方都想赢，都会做最优决策（即使自己与对方分差最大）。因此 f[l][r]f[l][r] 为上述两种情况中的最大值。

// 根据状态转移方程，我们发现大区间的状态值依赖于小区间的状态值，典型的区间 DP 问题。

// 按照从小到大「枚举区间长度」和「区间左端点」的常规做法进行求解即可。

// 作者：AC_OIer
// 链接：https://leetcode-cn.com/problems/stone-game/solution/gong-shui-san-xie-jing-dian-qu-jian-dp-j-wn31/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
     //思路：动态规划
    bool stoneGame(vector<int>& piles) {
        int len=piles.size();
        //给出一个len*len的bp矩阵
        vector<vector<int>> dp=vector<vector<int>>(len,vector<int>(len));
        //初始化矩阵元素
        for(int i=0;i<len;i++)
        {
            dp[i][i]=piles[i];
            for(int j=0;j<len;j++)
                if(i!=j)
                    dp[i][j]=0;
        }
        for(int i=1;i<len;i++)
        {
            for(int j=i-1;j>=0;j--)
            dp[i][j]=max(piles[i]-dp[i-1][j],piles[j]-dp[i][j+1]);
        }
        return dp[len-1][0]>0;
    }

    void test()
    {
        vector<int> case1Vec{5,3,4,5};
        cout << stoneGame(case1Vec) << " " << true << endl;
        
        // vector<int> case3Vec{0,10,5,2};
        // cout << peakIndexInMountainArray(case3Vec) << " " << 1 << endl;

        // vector<int> case4Vec{3,4,5,1};
        // cout << peakIndexInMountainArray(case4Vec) << " " << 2 << endl;

        // vector<int> case5Vec{24,69,100,99,79,78,67,36,26,19};
        // cout << peakIndexInMountainArray(case5Vec) << " " << 2 << endl;
    }
};

int main(int argc, char* argv[])
{
    Solution solution;
    solution.test();
    return 0;
}
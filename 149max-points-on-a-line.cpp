#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;
class Solution {
public:

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)
        {
            return n;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int maxPoints = 0;
            unordered_map<int, int> slopMap;
            for (int j = i + 1; j < n; j++)
            {
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];

                int x = x2 - x1;
                int y = y2 - y1;
                if (x == 0)
                {
                    y = 1;
                }
                else if (y == 0)
                {
                    x = 1;
                }
                else if (y < 0)
                {
                    x = -x;
                    y = -y;
                }

                int k  = gcd(x, y);
                x /= k;
                y /= k;
                int keyPoint = y + x * 20001;
                slopMap[keyPoint]++;
                maxPoints = max(maxPoints, slopMap[keyPoint]);
            }
            ans = max(ans, maxPoints + 1);
        }
        return ans
    }

private:
   int gcd(int a, int b)
   {
       return  b == 0 ? a : gcd(b, a%b);
   }
};


int main(int argc, char* argv[])
{
    return 0;
}


#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <functional>

class Solution {
public:
    int seen[10010];//记录搜到过的轮盘锁数字
    int ans = -1;
    bool dead[10010];//记录死亡数字
    string q[10010];//模拟队列
    int openLock(vector<string>& deadends, string target) { 
        for(auto d : deadends){
            
            //将死亡数字转int作为下标存储在dead数组中
            int tmp = stoi(d);
            dead[tmp] = 1;
        }

        //如果"0000"是死亡数字直接返回0,如果target为0000直接返回-1
        if(dead[0])return -1;
        if(target == "0000") return 0;
        bfs(target);
        return ans;
    }

    //判断旋转后的数字
    int numsadd(int num)
    {
        if(num == 10)
        return 0;
        if(num == -1)
        return 9;
        else return num;
    }
  
    void bfs(string target)
    {    
        //hh队头，tt队尾
        int hh=0,tt=0;

        //先将队头初始化为“0000”,代表从"0000"开始旋转
        q[0] = "0000";
        while(hh <= tt){
            auto t = q[hh++];
            int prev = stoi(t);
            for(int i = 0 ;i < 4; i++){
                int num = t[i]-'0';//提取当前位的数字
                string temp = t;

                //正向旋转当前位的数字
                temp[i] = ('0' + numsadd(num+1));
                int tmp = stoi(temp);
                if(!seen[tmp] && !dead[tmp]){

                    //满足条件就将temp插入队尾
                    q[++tt] = temp;
                    //更新新转盘锁数字的操作次数
                    seen[tmp] = seen[prev]+1;

                }

                //反向旋转当前位的数字
                temp[i]=('0' + numsadd(num-1));
                tmp = stoi(temp);
                if(!seen[tmp] && !dead[tmp]){
                    q[++tt] = temp;
                    seen[tmp] = seen[prev]+1;
                }           
            }
            int tar = stoi(target);
            if(seen[tar] != 0){
                ans = seen[tar];
                break;
            }
        }
    }
};


int main(int argc, char* argv[])
{
    return 0;
}
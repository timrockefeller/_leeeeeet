/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 *
 * https://leetcode-cn.com/problems/brick-wall/description/
 *
 * algorithms
 * Medium (43.62%)
 * Likes:    30
 * Dislikes: 0
 * Total Accepted:    1K
 * Total Submissions: 2.3K
 * Testcase Example:  '[[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]'
 *
 * 你的面前有一堵方形的、由多行砖块组成的砖墙。 这些砖块高度相同但是宽度不同。你现在要画一条自顶向下的、穿过最少砖块的垂线。
 *
 * 砖墙由行的列表表示。 每一行都是一个代表从左至右每块砖的宽度的整数列表。
 *
 * 如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。你需要找出怎样画才能使这条线穿过的砖块数量最少，并且返回穿过的砖块数量。
 *
 * 你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。
 *
 *
 *
 * 示例：
 *
 * 输入: [[1,2,2,1],
 * ⁠     [3,1,2],
 * ⁠     [1,3,2],
 * ⁠     [2,4],
 * ⁠     [3,1,2],
 * ⁠     [1,3,1,1]]
 *
 * 输出: 2
 *
 * 解释:
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 每一行砖块的宽度之和应该相等，并且不能超过 INT_MAX。
 * 每一行砖块的数量在 [1,10,000] 范围内， 墙的高度在 [1,10,000]
 * 范围内， 总的砖块数量不超过 20,000。
 *
 */
#include <map>
#include <vector>
using namespace std;
class Solution {
  public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> _map;
        int blocklength = 0,finallength=0;
        for (int i = 0; i < wall[0].size(); i++) {
            blocklength += wall[0][i];
        }
        for (int level = 0; level < wall.size(); level++) {
            int sum = 0;
            for (int block = 0; block < wall[level].size() - 1; block++) {
                sum += wall[level][block];
                _map[sum]++;
            }
            if(blocklength - wall[level][wall[level].size() - 1]>finallength)
                finallength = blocklength - wall[level][wall[level].size() - 1];
        }
        // summer
        int max = 0;
        for (int i = 0; i < finallength+1; i++) {
            if (_map[i] > max)
                max = _map[i];
        }
        if (max == wall.size() && wall[0].size() == 1) {
            return wall.size();
        }
        return wall.size() - max;
    }
};
// [[7, 1, 2], [3, 5, 1, 1], [10]]
//'[[100000000],[100000000],[100000000]]'

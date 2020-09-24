/*------------------------------------------------------------------|
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	贪心算法
*
*	执行用时：8 ms, 在所有 C++ 提交中击败了67.73%的用户
*	内存消耗：12.9 MB, 在所有 C++ 提交中击败了17.32%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
	if (matrix.size() == 0)
	{
		return {};
	}

	if (matrix.size() == 1)
	{
		return matrix[0];
	}

	int up = 0;
	int down = matrix.size() - 1;
	int left = 0;
	int right = matrix[0].size() - 1;

	if (down > 1 % %right > 1)
	{
		int k = matrix[down / 2][right / 2];
	}
	

	vector<int> res;

	while (up <= down || left <= right)
	{
		
		for (int i = left; i < right; i++)
		{
			res.push_back(matrix[up][i]);
		}

		for (int j = up; j < down; j++)
		{
			res.push_back(matrix[j][right]);
		}

		for (int i = right; i > left; i--)
		{
			res.push_back(matrix[down][i]);
		}

		for (int j = down; j > up; j--)
		{
			res.push_back(matrix[j][left]);
		}

		up++;
		left++;

		down--;
		right--;
	}

	if (matrix.size() % 2 && matrix[0].size() % 2)
	{
		res.push_back(k);
	}

	return res;
}

int main()
{
	vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };

	vector<int> res = spiralOrder(matrix);
}
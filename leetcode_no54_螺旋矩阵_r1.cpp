/* ------------------------------------------------------------------|
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

 

示例 1：


输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：


输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6.6 MB, 在所有 C++ 提交中击败了87.84%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size();
    int n = matrix[0].size();
    if (m == 0 || n == 0) {
        return res;
    }
    int upper = 0;    
    int lower = m - 1;
    int left = 0;
    int right = n - 1;
    while (upper < lower && left < right) {
        for (int i = left; i < right; ++i) {
            res.emplace_back(matrix[upper][i]);
        }
        for (int i = upper; i < lower; ++i) {
            res.emplace_back(matrix[i][right]);
        }
        for (int i = right; i > left; --i) {
            res.emplace_back(matrix[lower][i]);
        }
        for (int i = lower; i > upper; --i) {
            res.emplace_back(matrix[i][left]);
        }
        upper++;
        lower--;
        left++;
        right--;
    }
    //对于奇数行/列的处理
    if (upper == lower && left == right) {
        res.emplace_back(matrix[upper][left]);
    }
    else if (upper == lower || left == right) {
        for (int i = upper; i <= lower; ++i) {
            for (int j = left; j <= right; ++j) {
                res.emplace_back(matrix[i][j]);
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>> s = { {6,9,7} };
    spiralOrder(s);
}
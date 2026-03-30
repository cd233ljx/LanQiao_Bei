#include <bits/stdc++.h>
using namespace std;

int n;
char a[105][105];
bool keep[105][105]; // 标记该位置是否需要保留（属于某个单词）
string target = "yizhong";

// 8个方向: 右, 右下, 下, 左下, 左, 左上, 上, 右上
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

// 检查从 (x, y) 开始，沿着方向 (dir) 是否能组成 "yizhong"
void check_and_mark(int x, int y, int dir)
{
    int cx = x;
    int cy = y;

    // 临时存储这7个点的坐标，如果匹配成功再标记
    vector<pair<int, int>> path;

    for (int i = 0; i < 7; i++)
    {
        // 检查边界
        if (cx < 1 || cx > n || cy < 1 || cy > n)
            return;

        // 检查字符是否匹配
        if (a[cx][cy] != target[i])
            return;

        path.push_back({cx, cy});

        // 沿固定方向移动
        cx += dx[dir];
        cy += dy[dir];
    }

    // 如果循环走完没返回，说明找到了完整的单词
    // 将路径上的所有点标记为需要保留
    for (auto p : path)
    {
        keep[p.first][p.second] = true;
    }
}

int main()
{
    // 优化输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (!(cin >> n))
        return 0;

    // 读入矩阵
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            keep[i][j] = false; // 初始化标记数组
        }
    }

    // 遍历每个点
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 只有当字符是 'y' 时才可能是单词起点
            if (a[i][j] == 'y')
            {
                // 尝试 8 个方向
                for (int k = 0; k < 8; k++)
                {
                    check_and_mark(i, j, k);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (keep[i][j])
            {
                cout << a[i][j];
            }
            else
            {
                cout << "*";
            }
        }
        cout << "\n";
    }

    return 0;
}
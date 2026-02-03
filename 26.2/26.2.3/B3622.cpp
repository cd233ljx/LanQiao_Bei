#include <iostream>

using namespace std;

int n;
string path;
void dfs(int i)
{
    if (i > n)
    {
        cout << path << endl;
        return;
    }

    //不选
    path += 'N';
    dfs(i + 1);
    path.pop_back();
    //选
    path += 'Y';
    dfs(i + 1);
    path.pop_back();
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}
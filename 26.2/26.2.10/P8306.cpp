#include<bits/stdc++.h>
using namespace std;

int T;
int n, q;
string s,t;

const int N = 3e6 + 10;
int tree[N][26 + 26 + 10];
int p[N];
int idx;

int get_num(char& ch)
{
    int num = -1;
    if(ch >= 48 && ch <= 57)
    {
        return ch - 48;//0~9
    }
    else if(ch >= 65 && ch <= 90)
    {
        return ch - 65 + 10;//10~
    }
    else
    {
        return ch - 97 + 10 + 26;
    }

}
void insert(string& s)
{
    int cur = 0;
    for(char ch:s)
    {
        int path = get_num(ch);

        if(tree[cur][path] == 0)
            tree[cur][path] = ++idx;

        cur = tree[cur][path];
        p[cur]++;
    }
}

int find_pre(string& s)
{
    int cur = 0;
    for(char ch : s)
    {
        int path = get_num(ch);

        if (tree[cur][path] == 0)
            return 0;

        cur = tree[cur][path];
    }
    return p[cur];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while(T--){
        cin >> n >> q;

        // 重置trie树
        fill(tree[0], tree[idx], 0);
        fill(p, p + idx, 0);

        //或者用
        // memset(tree, 0, (idx+1) * 62 * sizeof(int));
        // memset(p, 0, (idx+1) * sizeof(int));

        idx = 0;

        for (int i = 1; i <= n;i++)
        {
            cin >> s;
            insert(s);
        }

        for (int i = 1; i <= q;i++)
        {
            cin >> t;
            cout << find_pre(t) << endl;
        }
    }
    return 0;
}
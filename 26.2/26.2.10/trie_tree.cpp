#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int tree[N][26], p[N], e[N];
int idx;

//插入字符串-创建
void insert(string& s){
    int cur = 0;
    p[cur]++;

    for(auto ch : s)
    {
        int path = ch - 'a';

        //如果没有路就分配一个结点
        if(tree[cur][path] == 0){
            tree[cur][path] = ++idx;
        }
        
        cur = tree[cur][path];
        p[cur]++;
    }
    e[cur]++;
}

//查找
int find(string& s)
{
    int cur = 0;
    for(char ch : s)
    {
        int path = ch - 'a';
        if(tree[cur][path] == 0){
            return 0;
        }
        cur = tree[cur][path];
    }
    return e[cur];
}

//查询多少个字符以"s"为前缀
int find_pre(string& s)
{
    int cur = 0;
    for(char ch: s)
    {
        int path = ch - 'a';
        if(tree[cur][path] == 0)
            return 0;
        cur = tree[cur][path];
    }
    return p[cur];
}

int main()
{
    


    return 0;
}
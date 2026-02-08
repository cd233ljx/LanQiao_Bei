#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
int ret[N];

// 维护递减栈;用于找元素左侧离得最近且比它大的元素
void test1()
{
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
       while(st.size() && a[st.top()] <= a[i]){
           st.pop();
       } 
       if(st.size())
           ret[i] = st.top();
       st.push(i);
    }

    for (int i = 1; i <= n; i++){
        cout << ret[i] << " ";
    }
}

// 维护递增栈；用于找元素左侧离得最近且比它小的元素
void test2(){
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        while (st.size() && a[st.top()] >= a[i])
        {
            st.pop();
        }
        if (st.size())
            ret[i] = st.top();
        st.push(i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ret[i] << " ";
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    test2();
    return 0;
}
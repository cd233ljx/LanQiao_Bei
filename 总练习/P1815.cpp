#include<bits/stdc++.h>
using namespace std;

int m;
struct node
{
    int x;
    int y;
    node* pre;
} body[25];


bool check()
{
    for (int i = 1; i <= 20;i++)
    {
        int a = body[i].x;
        int b = body[i].y;
        if ()
    }
}

int main()
{
    while(1)
    {
        cin >> m;

        if (m == 0)
            return 0;

        // 初始化
        for (int i = 1; i <= 20;i++)
        {
            for (int j = 11; j <= 30;j++)
            {
                body[i].x = 25;
                body[i].y = j;
                if (i > 1) 
                {
                    *(body[i].pre) = body[i - 1];
                }
            }
        }

        for (int i = 1; i <= m;i++)
        {
            char op;
            cin >> op;

            int h_x = body[1].x;
            int h_y = body[1].y;

            if(op == 'N') // 上
            {
                h_x--;
            }
            else if(op == 'W') // 左
            {
                h_y--;
            }
            else if(op == 'E')// 右
            {
                h_y++;
            }
            else if(op == 'S') // 下
            {
                h_x++;
            }
            
            if(check())
            {

            }


        }
    }
  

    

    return 0;
}
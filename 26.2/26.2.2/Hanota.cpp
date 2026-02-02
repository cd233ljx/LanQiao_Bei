#include <bits/stdc++.h>
using namespace std;

int n;
char a, b, c;

// x 借助 y 到 z
void Swap(int n, char x, char y, char z)// a c b
{
    if (n == 0)
        return;

    Swap(n - 1, x, z, y);
    printf("%c->%d->%c\n", x, n, z);
    Swap(n - 1, y, x, z);
}

int main()
{
    cin >> n >> a >> b >> c;

    Swap(n, a, c, b);

    return 0;
}
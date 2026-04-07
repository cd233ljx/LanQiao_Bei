#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x = 233, y = 666;

    printf("%.0lf", sqrt(x * x + y * y) * (1 + atan(y / x)));
    return 0;
}
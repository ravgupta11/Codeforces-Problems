#include <bits/stdc++.h>
using namespace std;

bool _flag = false;
void _set()
{
    if (_flag)
        return;
    srand(time(0));
    _flag = true;
}
int randint(int l, int r)
{
    _set();
    int v = (rand() << 15) ^ rand();
    v %= r - l + 1;
    return v + l;
}
char *randstring(int _n)
{
    char *tmp = (char *)malloc((_n + 1) * sizeof(char));
    for (int i = 0; i < _n; i++)
        tmp[i] = 'a' + randint(0, 25);
    return tmp;
}
int a[10];

int main()
{
    for (int i = 0; i < 10000000; i++)
    {
        int d = 5 + (rand() % (4));
        a[d]++;
    }
    
    cout << a[5] << " " << a[6] << " " << a[7] << " " << a[8];
    return 0;
}
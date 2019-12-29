#include <bits/stdc++.h>
using namespace std;

set<string> used;

bool _flag = false;
void _set()
{
    if (_flag)
        return;
    srand(time(0));
    _flag = true;
}
long long randint(long long l, long long r)
{
    _set();
    long long v = ((rand() * 1LL) << 15) ^ rand();
    v %= r - l + 1;
    return v + l;
}
string randstring(long long MAX_N)
{
    int _n = randint(0, MAX_N);
    string tmp = "";
    for (int i = 0; i < _n; i++)
        tmp += 'a' + (int)randint(0, 25);
    return tmp;
}

int main(int args, char *argv[])
{
    clock_t begin = clock();
    int tests;
    scanf("%d", &tests);
    string p;
    for (int i = 0; i < tests; i++)
    {
        do
        {
            p = randstring((args != 1 ? atoll(argv[1]) : 100005));
        } while (used.count(p));
        used.insert(p);
    }
    for (string p : used)
        printf("%d\n%s\n", p.length(), p.c_str());
    printf("%0.10lf\n", ((double)(clock() - begin) / CLOCKS_PER_SEC));
    return 0;
}
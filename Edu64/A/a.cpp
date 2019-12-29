#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int t;
	int n, x;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%d %d", &n, &x);
		printf("%d\n", 2 * x);
	}
	return 0;
}
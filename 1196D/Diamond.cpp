#include <bits/stdc++.h>
using namespace std;

int main()
{

	clock_t begin = clock();
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < i + 1; k++)
		{
			char p = 'a' + k;
			printf("%c", p);
		}
		printf("\n");
	}
	printf("%0.10lf\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
	/*for(int i =5; i >-1; i--){
		for(int j = i; j < 5;j++) printf(" ");
		for(int k = 0; k < 2*i + 1; k++) printf("*");
		printf("\n");
	}*/
	return 0;
}

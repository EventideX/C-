#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int i, j, k, n, m, s, t, a[100001], b[100001] = { 0 }, c[100001];

int main()
{
	FILE *istream;
	freopen_s(&istream, "in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	j = 0;
	k = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &t);
		if (t == 0) c[j++] = i;
		else a[k++] = t;
	}
	if (k != 0) sort(a, a + k - 1);
	k = 0;
	for (i = 0; i < m; i++) scanf("%d", &b[c[i]]);
	i = 0;
	j = 0;
	while (i < n)
	{
		while (b[i] == 0)
		{
			b[i] = a[j];
			i++;
			j++;
		}
		i++;
	}
	for (i = 0; i < n - 1; i++)
		if (!(b[i] < b[i + 1]))
		{
			printf("%d", -1);
			exit(0);
		}
	printf("%d", b[0]);
	for (i = 1; i < n; i++)
		printf(" %d", b[i]);
	return 0;
}

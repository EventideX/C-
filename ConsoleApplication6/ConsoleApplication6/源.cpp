#include<stdio.h>

int b[100001], a[300001], n, m, c[100001];

int min(int x, int y)
{
	return x<y ? x : y;
}
int max(int x, int y)
{
	return x>y ? x : y;
}
int getsum(int l, int r)
{
	int sum = 0;
	l += m - 1;
	r += m + 1;
	while (l^r != 1 && l != r)
	{
		if (l & 1 == 0) sum += a[l ^ 1];
		if (r & 1 == 1) sum += a[r ^ 1];
		l >>= 1;
		r >>= 1;
	};
	return sum;
}
void sifup(int k)
{
	k >>= 1;
	while (k>1)
	{
		a[k] = a[k << 1] + a[(k << 1) + 1];
		k >>= 1;
	};
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &b[i]);
	};
	m = 1;
	while (m <= n) m <<= 1;
	for (int i = m + 1; i <= m + n; ++i)
	{
		a[i] = 1;
	};
	for (int i = m - 1; i>0; --i)
	{
		a[i] = a[i << 1] + a[(i << 1) + 1];
	};
	for (int i = 1; i <= n; ++i)
	{
		int max_right = getsum(1, b[i] - 1) + i;
		c[b[i]] = max(b[i], max(max_right, i)) - min(b[i], min(max_right, i));
		a[m + b[i]] = 0;
		sifup(m + b[i]);
	};
	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", c[i]);
	};
	return 0;
}
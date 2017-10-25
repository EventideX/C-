#include<stdio.h>

int i, j, k, n, m, s, t, a[300001], b[100001], c[100001];

int min(int x, int y)
{
	return x < y ? x : y;
}
int max(int x, int y)
{
	return x > y ? x : y;
}
int p(int l, int r)
{
	int s;
	s = 0;
	l += m - 1;
	r += m + 1;
	while ((l^r != 1) && (l != r))
	{
		if (l & 1 == 0) s += a[l ^ 1];
		if (r & 1 == 1) s += a[r ^ 1];
		l >>= 1;
		r >>= 1;
	}
	return s;
}
void q(int k)
{
	k >>= 1;
	while (k > 1)
	{
		a[k] = a[k << 1] + a[(k << 1) + 1];
		k >>= 1;
	}
}
int main()
{
	FILE *istream;
	freopen_s(&istream, "in.txt", "r", stdin);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	m = 1;
	while (m <= n) m <<= 1;
	for (i = m + 1; i <= m + n; i++)
		a[i] = 1;
	for (i = m - 1; i >= 1; i--)
		a[i] = a[i << 1] + a[(i << 1) + 1];
	for (i = 1; i <= n; i++)
	{
		t = p(1, b[i] - 1) + i;
		c[b[i]] = max(b[i], max(t, i)) - min(b[i], min(t, i));
		a[m + b[i]] = 0;
		q(m + b[i]);
	}
	printf("%d", c[1]);
	for (i = 2; i <= n; i++)
		printf(" %d", c[i]);
	return 0;
}
#include<cstdio>
#include<cmath>

using namespace std;

int n, a, d, t, v, i;

double y=-1, x;

int main()
{
	scanf("%d%d%d", &n, &a, &d);
	for (i=0; i < n; ++i)
	{
		scanf("%d%d", &t, &v);
		if (2ll * d * a > (long long int )v * v)
		{
			x = v * 0.5 / a + d * 1.0 / v;
		}
		else 
			x = sqrt(d * 2.0 / a);
		
		x += t;
		if(x > y)
			y = x;
		printf("%.12lf\n", y);
	}
	return 0;
}
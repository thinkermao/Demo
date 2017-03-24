#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct point {
	int x;
	int y;
	int d;
	int t;
};

int path[2][12][12];
char map[2][12][12];
int n, m;
bool flag = false;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve(int t);
void find(queue<struct point> &open_table, const struct point &p);
void deal(queue<struct point> &open_table, const struct point &p);

int main()
{
	int c = 0, t = 0;
	scanf("%d", &c);
	while (c--)
	{
		flag = false;

		memset(path, 0, sizeof(path));
		memset(map, '*', sizeof(map));
		scanf("%d %d %d", &n, &m, &t);
		for (int floornum = 0; floornum < 2; floornum++)
		{
			for (int i = 0; i < n; i++)
			{
				scanf("%s", map[floornum][i]);
			}
		}
	
		solve(t);
	}
	getchar();

	return 0;
}

void solve(int t)
{
	queue<struct point> open_table;
	struct point p = { 0, 0, 0, t };
	open_table.push(p);

	path[0][0][0] = 1;
	while (open_table.size() > 0 && !flag)
	{
		struct point & o = open_table.front();
		find(open_table, o);
		open_table.pop();
	}

	if (flag) printf("YES\n");
	else printf("NO\n");
}

void find(queue<struct point> &open_table, const struct point &p)
{
	//printf("\n\n��ʼ���ҵ� %d �� x=%d, y=%d, t=%d\n",p.d, p.x, p.y, p.t);

	struct point o = { 0, 0, 0, 0 };

	for (int i = 0; i < 4; i++)
	{
		o.x = p.x + dx[i];
		o.y = p.y + dy[i];
		o.d = p.d;
		o.t = p.t - 1;
		if (o.x >= 0 && o.x < n && o.y >= 0 && o.y < m
			&& path[o.d][o.x][o.y] == 0)
			deal(open_table, o);
	}
}

void deal(queue<struct point> &open_table, const struct point &p)
{
	struct point i = p;
	//printf("��ʼ����� %d �� x=%d, y=%d, t=%d\n", p.d, p.x, p.y, p.t);
	//printf("�õ��ͼ��Ϊ %c \n", map[p.d][p.x][p.y]);
	if (i.t < 0) return ;  // С�����ʾ��ǰ��һ���Ѿ���ʱ��

	path[i.d][i.x][i.y] = 1;

	if (map[i.d][i.x][i.y] == '#')
	{
		path[i.d][i.x][i.y] = 1;
		i.d = 1 - i.d;
	}
	
	if (map[p.d][p.x][p.y] == 'P' || map[p.d][p.x][p.y] == 'p')
	{
		//printf("�ҵ�����\n");
		flag = true; 

	}
	else if (map[i.d][i.x][i.y] == '.')
	{
		path[i.d][i.x][i.y] = 1;
		open_table.push(i);
		//printf("�õ�Ϊ·����������С��� %d �� x=%d, y=%d, t=%d\n", p.d, p.x, p.y, p.t);
	}
}


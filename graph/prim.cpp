#include "stdio.h"
#include <iostream>
#include <algorithm>

using namespace std;

#define N 100
#define INT_MAX 2147483647

int parent[N],//父节点
key[N], //与父节点的距离
tb[N][N],//关系表
visited[N];//是否已进入树


void prim(int nodeNum)//结点个数
{
	fill_n(parent, N, 0);
	fill_n(key, N, INT_MAX);
	fill_n(visited, N, 0);

	int root = 1;//选取第一个点作为根节点，可随意选取
	key[root] = 0;
	//visited[root] = 1;
	
	//已经被访问点的数量
	for(int time =0;time < nodeNum;++time)
	{
		int min = INT_MAX;
		int next;//选取下一个进入生成树的点
		for (int i = 1;i <= nodeNum;++i)
		{
			if (!visited[i] && key[i] < min)
			{
				min = key[i];
				next = i;
			}
		}
		visited[next] = 1;//入队

		for (int i = 1;i <= nodeNum;++i)
		{
			if (next != i && tb[next][i] < key[i]&&!visited[i])
			{
				parent[i] = next;
				key[i] = tb[next][i];
			}
		}
	}

	int sum = 0;
	for (int i = 1;i <= nodeNum;++i)
	{
		if (key[i] == INT_MAX)
		{
			cout << "有不可达的点！";
			return;
		}
		if (parent[i])
			cout << "from " << parent[i] << " to " << i << endl;
		else
			cout << i << "is the root!" << endl;
		
		sum += key[i];
	}
	cout << "最小总代价为" << sum;
}

int main()
{
	int n, m;
	int i, j;
	int u, v, w;
	printf("请输入所求图的顶点数目和边的数目(以空格分隔各个数，输入两个0结束):\n"); //输入所求的顶点数目和边数
	while (scanf("%d%d", &n, &m))
	{
		if (m != 0 && n != 0)
		{
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
					tb[i][j] = INT_MAX;
			}
			printf("请输入两条边的节点序号以及它们的权值(以空格分隔各个数):\n");
			while (m--)	      //输入所有边数以及它们的权值
			{
				scanf("%d%d%d", &u, &v, &w);	  //输入边数以及它们的权值
				tb[u][v] = tb[v][u] = w;
			}
			prim(n);
			printf("\n");
			printf("请输入所求图的顶点数目和边的数目(以空格分隔各个数，输入两个0结束):\n"); //输入所求的顶点数目和边数
		}
		else if (n == 0 && m == 0)
			return 0;
	}
	return 0;
}

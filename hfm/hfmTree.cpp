#include <queue>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>

const int N = 100;
//int frequency[N];
int nodeNum = -1;

struct node {
	node* left = nullptr;
	node* right = nullptr;
	int frequency = 0;//记录结点出现的次数
};

struct comp {
	bool operator()(const node* lhs, const node* rhs)
	{
		return lhs->frequency > rhs->frequency;
	}
};

node pool[N];//结点池

node* getFreeNode()
{
	assert(nodeNum > 0);
	static int count = nodeNum;

	return &pool[count++];
}

using namespace std;

void print(node* xi);//前序遍历

void hfmTree()
{
	priority_queue<node*,vector<node*>,comp> pq;
	for (int i = 0;i < nodeNum;++i)
		pq.push(&pool[i]);

	while (!pq.empty())
	{
		//取次数最小的两个结点
		auto xi = pq.top();
		pq.pop();
		if (pq.empty())//完成树的构造
		{
			print(xi);
			break;
		}
		auto xixi = pq.top();
		pq.pop();

		auto xixixi = getFreeNode();
		xixixi->left = xi;
		xixixi->right = xixi;
		xixixi->frequency = xi->frequency + xixi->frequency;
		pq.push(xixixi);
	}

}

int main(void)
{
	cout << "请输入结点个数" << endl;
	cin >> nodeNum;
	assert(nodeNum > 0);
	
	for (int i = 0;i < nodeNum;++i)
	{
		cin >> pool[i].frequency;
	}

	hfmTree();
	system("pause");

	return 0;
}

void print(node* xi)//前序遍历
{
	static char code[2][2] = { "0","1" };
	static string result("0");


	if (xi - pool < nodeNum)
	{
		cout << xi->frequency << " " << result << endl;
	}
	if (xi->left != nullptr)
	{
		result.append(code[0]);
		print(xi->left);
		result.pop_back();
	}
	if (xi->right != nullptr)
	{
		result.append(code[1]);
		print(xi->right);
		result.pop_back();
	}
}
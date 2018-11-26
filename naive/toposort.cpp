#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cassert>
#include <fstream>
#include <sstream>

using namespace std;

//参数自左而右分别为事务数组，关系表，拓扑排序后的结果
void DFS(int count, vector<int> &result);
int table[100][100];//关系表

int main(void)
{
	ifstream fs("testTopo.txt");
	map<string, int> flag;
	vector<string> getstring;
	getstring.reserve(10);
	
	fill_n(table[0], 100 * 100, 0);

	//预处理
	int count = 0;
	string aline;
	while (getline(fs, aline))
	{
		istringstream iss(aline);
		string s1, s2;
		iss >> s1 >> s2;
		//判断特立独行的事件
		if (s2.compare("NULL") == 0)
		{
			cout << s1 << " ";
			continue;
		}

		if (flag.count(s1) == 0) {
			flag.insert(make_pair(s1, count));
			getstring.push_back(s1);
			++count;
		}
		if (flag.count(s2) == 0) {
			flag.insert(make_pair(s2, count));
			getstring.push_back(s2);
			++count;
		}

		table[flag[s1]][flag[s2]] = 1;
	}

	vector<int> result;
	DFS(count, result);
	for (int i = result.size() - 1; i >=0; --i)
	{
		cout << getstring[result[i]] << " ";
	}
 	cout << endl;

	return 0;
}

bool dfs(int cur, int count, vector<int>& result);
bool visited[100];//访问标志

void DFS(int count, vector<int>& result)
{
	fill_n(visited, 100, 0);
	for (int i = 0;i < count;++i)
	{
		if (!visited[i]) {
			if (!dfs(i, count, result)) {
				cout << "oh no!" << endl;
				break;
			}
		}
	}
}

bool dfs(int cur, int count, vector<int>& res)
{
	visited[cur] = -1;//标识正在访问

	for (int i = 0; i < count;++i)
	{
		if (i == cur)continue;
		if (table[cur][i]) {
			if (visited[i] == -1)return false;//出现环
			if (visited[i] == 0 && !dfs(i, count, res))
				return false;
		}
	}

	visited[cur] = 1;//标识访问结束
	res.push_back(cur);

	return true;
}

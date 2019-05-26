#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

struct node{
    node(const string& s){
        if(s[0] == 'n'){
            assert(s=="null");
            isNull = true;
        }else{
            val = stoi(s);
        }
    }
    int val = -1;
    bool isNull = false;
};

int main()
{
    //两个输入数组的缓冲区
    vector<node> inputs[2];
    //假定两个数组分行输入
    string line;
    //用来存储一行输入也即是一个数组，格式化输入
    istringstream iss;
    
    for(int i = 0;i<2;i++){
        //获取一行输入
        getline(cin, line);
        
        iss.clear();//清空缓冲
        iss.str(line);//设置str

        string word;
        //格式化输入
        while(iss>>word){
            // cout<<word<<"\n";
            inputs[i].emplace_back(word);
        }
    }
    
    //让input[0]成为数组中size中较大的那个
    if(inputs[0].size()<inputs[1].size()){
        inputs[0].swap(inputs[1]);
    }

    //依照题意合并数组
    for(int i = 0;i<inputs[1].size();i++){
        if(inputs[1][i].isNull){
            continue;
        }
        //
        if(inputs[0][i].isNull){
            inputs[0][i] = inputs[1][i];
        }else{
            inputs[0][i].val += inputs[1][i].val;
        }
    }

    for(auto result_node:inputs[0]){
        //输出
        if(result_node.isNull){
            cout << "null" << ' ';
        }else{
            cout << result_node.val << ' ';
        }
    }
    cout<<'\n';

    return 0;
}
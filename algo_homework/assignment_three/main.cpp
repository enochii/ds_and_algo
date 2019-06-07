#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

//代表切剪绳子的一个状态
//ropes代表切割后所有的绳子,以长度表示
//product代表绳子的乘积
struct state{
    vector<int> ropes;
    int product;
};

//前置声明
void dp_iter(int n, vector<state >& mem);
void display(int n, vector<state>& res);


int main()
{
    //存储剪绳子的方案
    vector<state > mem;
    int n; // 绳子的总长度

    static string hint = "Please input the original length of the rope: ";
    cout<< hint;
    while(cin>>n){
        //特殊情况
        if(n==2||n==3){
            mem.push_back(state{{n-1,1},n-1});
        }else{
            //初始化
            mem.assign(n+1, state{{},1});
            mem[1] = {{1},1};
            dp_iter(n, mem);
        }
        
        
        display(n, mem);
        cout<<hint;
    }
}

//
//这里很自然的想到动态规划，对一个长度为n的绳子，切割的结果必然是
//多次一分为二的切割。在考虑如何切割n时，我们可以利用小于n的绳子的最优切割结果


void dp_iter(int n, vector<state >& mem)
{
    for(int i=2;i<n+1;i++){
        //从底层选择组合
        int res_product = i;
        int split_pos = 0;

        // int limit = i/2;
        for(int j=1;j<=i/2;j++){
            if(mem[j].product*mem[i-j].product>res_product){
                res_product = mem[j].product*mem[i-j].product;
                split_pos = j;
            }
        }

        //写回结果
        mem[i].product = res_product;
        //没有发生切割
        if(split_pos==0){
            mem[i].ropes.push_back(i);
        }else{
            //把切割的两块的所有绳子加入ropes
            for(auto item: mem[split_pos].ropes){
                mem[i].ropes.push_back(item);
            }
            for(auto item: mem[i - split_pos].ropes){
                mem[i].ropes.push_back(item);
            }
        }
    }
}

//
void display(int n, vector<state>& res)
{
    //输出总段数以及各段的长度
    cout<<"Split the " << n << " rope into " <<res[res.size()-1].ropes.size()
    <<" pieces: ";

    for(auto & item:res[res.size()-1].ropes){
        cout<<item<<" ";
    }

    //输出乘积
    cout<<", total product is: "<<res[res.size()-1].product<<"\n\n";
}
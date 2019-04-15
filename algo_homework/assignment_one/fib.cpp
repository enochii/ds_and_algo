/*
* created by 施程航, 2019/3/31
*/

#include <iostream>
#include <cassert>
#include <vector>

#include "test.h"//测试程序正确性和性能

/*
* 函数名: fib
* 功能描述: 求出第n（n作为函数参数由用户给出）个Fibnacci数
* 输入: 所求Fibnacci数的序号
* 输出/返回值: 第n个Fibnacci数
*/
inline long long int fib(int n)
{
	assert(n >= 0);
	long long int ans = 0, next = 1;
	
	//第一次进入循环时，ans=fib(0) next=fib(1)
	for (int i = 0;i<n;++i) {
		//计算fib(i+1),fib(i+2)的值，分别存入ans、next中
		long long int temp = ans + next;
		ans = next;
		next = temp;
	}
	//当循环结束时，ans存的值为fib(n)，即为所求结果
	return ans;
}

//前置声明
std::vector<long long> fib_iter(int, std::vector<long long>&);

/*
* 函数名: fib_by_matrix
* 功能描述: 求出第n（n作为函数参数由用户给出）个Fibnacci数
* 输入: 所求Fibnacci数的序号
* 输出/返回值: 第n个Fibnacci数
*/
inline long long int fib_by_matrix(int n)
{
    static std::vector<long long> one = {1,1,1,0};
    //利用矩阵乘法的可结合性
    if(n == 0)return 0;
    //取出结果矩阵(2*2)右上角的数值，即为所求fib(n)
    else return (fib_iter(n, one))[1];
}



int main()
{	
    //这里先对正确性进行测试
    std::cout<<"Function fib() test result:\n";
    test_all(fib);

    std::cout<<"\nFunction fib_by_matrix() test result:\n";
    test_all(fib_by_matrix);

    //测试两个函数各自的性能
    std::cout<<"---------------How much time they cost------------------\n\n";
    print_total_time("fib", fib, 90, 1000000);
    print_total_time("fib_by_matrix", fib_by_matrix, 90, 1000000);
    //fib(1000) * 100000
    print_total_time("fib", fib, 1000, 100000);
    print_total_time("fib_by_matrix", fib_by_matrix, 1000, 100000);
    //fib(10000) * 10000
    print_total_time("fib", fib, 10000, 10000);
    print_total_time("fib_by_matrix", fib_by_matrix, 10000, 10000);
	
    
	return 0;
}

/*
* 矩阵乘法，计算m1*m2，这里m1和m2都是2*2的二维方阵
* 考虑到性能和方便，这里我们用一个大小为4的一维vector<long long>来表示一个2*2的矩阵
* matrix[i][j]对应vec[2*i+j]
*/
std::vector<long long> mul_matrixs(std::vector<long long>& m1, std::vector<long long>& m2)
{
    //初始化返回矩阵
    std::vector<long long> product(4, 0LL);
    //由于我们这里默认矩阵都是2*2，所以直接把矩阵乘法展开
    product[0] = m1[0]*m2[0]+m1[1]*m2[2];
    product[1] = m1[0]*m2[1]+m1[1]*m2[3];
    product[2] = m1[2]*m2[0]+m1[3]*m2[2];
    product[3] = m1[2]*m2[1]+m1[3]*m2[3];

    return product;
}

/*
* 求mat^n也即mat矩阵的n次方，通过矩阵乘法的可结合性降低时间复杂度
*/
std::vector<long long> fib_iter(int n, std::vector<long long>& mat)
{
    if(n==1)return mat;
    else if(n%2==0){
        //当n为偶数时，先计算结果的平方根然后再做乘法，这是算法复杂度为log(n)的关键
        auto half = fib_iter(n/2, mat);
        return mul_matrixs(half, half);
    }
    else{
        //n为奇数，拆成mat*(mat^(n-1))
        auto part = fib_iter(n-1,mat);
        return mul_matrixs(part, mat);
    }
}


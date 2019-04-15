#include "test.h"

#include <ctime>
#include <iostream>

static inline void test(const char * test_info, int* test_arr, unsigned size, long long (*fib)(int n));
static inline clock_t total_time(long long (*fib_fun)(int n), int fib_index, int times);

void print_total_time(const char* func_name, long long (*fib_fun)(int n), int fib_index, int times)
{
    std::cout << "Function " << func_name << " takes "<<total_time(fib_fun, fib_index, times)*1.0/CLOCKS_PER_SEC <<" (s)";
    std::cout << "for computing fib(" << fib_index << ") " << times << " times.\n\n";
}


void test_all(long long (*fib_fun)(int n))
{
    static int function_test[] = { 3, 5, 10 };
	static int bound_test[] = { 0,1,2 };
	static int performance_test[] = { 40,50,90 };

    test("Functionality Test: ", function_test, 3, fib_fun);
	test("Bound Test", bound_test, 3, fib_fun);
	test("Performance Test", performance_test, 3, fib_fun);
}


/*
* 函数名: test
* 功能描述: 打印具体的测试结果
* 输入: 测试信息 test_info ，测试数据 test_arr，测试数据的个数
* 输出: 输出测试结果
*/
static inline void test(const char * test_info, int* test_arr, unsigned size, long long (*fib)(int n))
{
	std::cout << test_info << ": \n";
	for (int i = 0;i < size;i++) {
		std::cout 
		<< "fib(" << test_arr[i] << ") = " 
		<< fib(test_arr[i]) << '\n';
	}
	std::cout << '\n';
}


/*
* 返回fib_fun函数指针代表的函数计算fib(fib_index) (time)次所需要的总时间
*/
static inline clock_t total_time(long long (*fib_fun)(int n), int fib_index, int times)
{
    clock_t start = clock();
    for(int i =0;i<times;i++){
        fib_fun(fib_index);
    }
    return clock() - start;
}
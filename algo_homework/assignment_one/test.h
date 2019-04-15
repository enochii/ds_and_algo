#ifndef FIB_TEST_H
#define FIB_TEST_H

/*
* 打印fib_fun函数指针代表的函数计算fib(fib_index) (time)次所需要的总时间
*/
void print_total_time(const char* func_name, long long (*fib_fun)(int n), int fib_index, int times);

/*
* 分别进行文档所要求的功能测试、边界测试和性能测试
*/
void test_all(long long (*fib_fun)(int n));

#endif//FIB_TEST_H
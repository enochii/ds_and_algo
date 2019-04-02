#include <iostream>
#include "magic_square.h"
#include <string>

using namespace std;

int main()
{
	std::cout << "\n" << std::string(50, '=') << "\n\n";
	while (true) {
		std::cout << "请输入数字n，将会为您生成(4*n+2)的单偶数阶幻方： ";
		int num;
		std::cin >> num;
		
		process_single_even(num * 4 + 2);
	}

	system("pause");
	return 0;
}
#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>

#include "magic_square.h"


void display(std::vector<std::vector<int> > &container)
{
	int n = container.size();
	for (auto row = 0;row < n;++row) {
		for (auto col = 0;col < n;++col)
			std::cout << std::setw(5) << container[row][col];
		std::cout << std::endl;
	}
}

void process_odd(int n, std::vector<std::vector<int > > &container)
{
	assert(n % 2 == 1);
	//std::vector<std::vector<int> > container(n, std::vector<int>(n, 0));

	int row = 0, col = n / 2;
	for (int num = 1;num <= n * n;++num) {
		container[row][col] = num;
		if (container[(row + n - 1) % n][(col + 1) % n] == 0) {
			row = (row + n - 1) % n;
			col = (col + 1) % n;
		}
		else
			row = (row + 1) % n;
	}

	//display(container);
}

std::vector<std::vector<int> > process_single_even(int n)
{
	assert(n % 4 == 2 && n != 2);

	std::vector<std::vector<int> > container(n, std::vector<int>(n, 0));

	//step1
	int half_n = n / 2;
	process_odd(half_n, container);
	for (int row = 0;row < half_n;++row)
		for (int col = 0;col < half_n;++col) {
			int cur = container[row][col];
			container[row][col + half_n] = cur + 2 * half_n*half_n;
			container[row + half_n][col] = cur + 3 * half_n*half_n;
			container[row + half_n][col + half_n] = cur + half_n * half_n;
		}
	//display(container);
	//5 2
	using std::swap;
	int quarter = (n - 2) / 4;
	//step2
	for (int row = 0;row < half_n;++row)
		for (int col = 0;col < quarter;++col) {
			if (row != quarter)
				swap(container[row][col], container[row + half_n][col]);
			else
				swap(container[row][col + quarter],
					container[row + half_n][col + quarter]);
		}
	//display(container);
	//step3
	for (int row = 0;row < half_n;++row) {
		for (int col = n - quarter - 1;col > half_n + 1;--col)
			swap(container[row][col], container[row + half_n][col]);
	}

	check(container);

	std::cout << "\n" << n << "阶幻方：:\n";
	display(container);
	std::cout << std::string(50, '=') << "\n\n";

	return container;
}

bool check(std::vector<std::vector<int> >& container)
{
	int row_size = container.size();
	int col_size = container[0].size();//actually, the row_size and col_size should be equal
									   //
	int row_sum = 0,
		col_sum = 0,
		diagonal_sum_1 = 0, diagonal_sum_2 = 0;

	//calculate row_sum
	for (int row = 0;row < row_size;++row) {
		int temp_sum = 0;
		for (int col = 0;col < col_size;++col)
			temp_sum += container[row][col];
		if (row_sum != 0 && row_sum != temp_sum) {
			std::cout << "各行的和不相等\n";
			return false;
		}
		//update row_sum
		row_sum = temp_sum;
	}
	//calculate col_sum
	for (int col = 0;col < col_size;++col) {
		int temp_sum = 0;
		for (int row = 0;row < row_size;++row)
			temp_sum += container[row][col];
		if (row_sum != 0 && row_sum != temp_sum) {
			std::cout << "各列的值不相等!\n";
			return false;
		}
		//update
		col_sum = temp_sum;
	}
	//diagonal_sum
	for (int step = 0;step < row_size;++step) {
		diagonal_sum_1 += container[step][step];
		diagonal_sum_2 += container[step][col_size - step - 1];
	}
	if (diagonal_sum_1 != diagonal_sum_2) {
		std::cout << "两对角线的和不相等!\n";
		return false;
	}
	if (row_sum != col_sum || row_sum != diagonal_sum_1) {
		std::cout << "行、列、对角线的值不全相等!\n";
		return false;
	}
	std::cout << "行的和为 :" << row_sum;
	std::cout << "\n列的和为 :" << col_sum;
	std::cout << "\n对角线的和为 :" << diagonal_sum_1;

	return true;
}

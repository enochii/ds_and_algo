#pragma once
#include <vector>


bool check(std::vector<std::vector<int> >& container);

void display(std::vector<std::vector<int> > &container);

//todo: add offset arg to generalize
void process_odd(int n, std::vector<std::vector<int > > &container);

std::vector<std::vector<int> > process_single_even(int n);

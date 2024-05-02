// aisd_lab2_var12.cpp: определяет точку входа для приложения.
// 2,1,4

#include "hash_table.h"

using namespace std;
using namespace my;

int main()
{	
    vector<int>input_vec = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
    print_numbers_count(count_numbers(input_vec), input_vec.size());
    return 0;
}

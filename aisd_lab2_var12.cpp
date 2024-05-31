// aisd_lab2_var12.cpp: определяет точку входа для приложения.
// 2,1,4

#include "hash_table.h"

using namespace std;
using namespace my;

int main()
{	
   /* vector<int>input_vec = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
    print_numbers_count(count_numbers(input_vec), input_vec.size());
    return 0;*/

    HashTable<int, int> a;
    int key = 1;
    int key2 = 2;
    int key3 = 3;
    int value = 1;
    int value2 = 2;
    int value3 = 3;
    a.insert(key, value);
    a.insert(key2, value2);
    a.insert(key3, value3);
    a.erase(1);
    a.print();
}

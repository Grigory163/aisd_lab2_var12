// aisd_lab2_var12.cpp: определяет точку входа для приложения.
// 2,1,4

#include "hash_table.h"

using namespace std;
using namespace my;

int main()
{
	HashTable<string, string> zopa(4);
	zopa.insert("1", "a");
	zopa.insert("2", "b");
	zopa.insert("2", "c");
	zopa.insert("3", "d");
	zopa.insert_or_assign("2", "ebal hesh tablicy");
	zopa.print();

	
}

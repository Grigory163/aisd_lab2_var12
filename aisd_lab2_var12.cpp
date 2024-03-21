// aisd_lab2_var12.cpp: определяет точку входа для приложения.
// 2,1,4

#include "hash_table.h"

using namespace std;
using namespace my;

int main()
{
	HashTable<int, string> zopa(4);
	
	zopa.insert(1, "hui");
	zopa.insert(2, "govno");
	zopa.insert(2, "asshole");
	zopa.insert_or_assign(3, " 10 ");
	zopa.insert_or_assign(1, "hz");
	zopa.insert(2, "govno");
	zopa.insert(2, "asshole");
	zopa.insert(2, "govno");
	zopa.insert(2, "asshole");
	zopa.insert(2, "govno");
	zopa.insert(2, "asshole");
	auto aaa = zopa;
	aaa.print();
	/*my::Hash_table<int, int> penis{6};
	zopa = penis;*/
	//cout << zopa.Get_size();
	
}

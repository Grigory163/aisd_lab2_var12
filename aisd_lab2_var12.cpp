﻿// aisd_lab2_var12.cpp: определяет точку входа для приложения.
// 2,1,4

#include "hash_table.h"

using namespace std;
using namespace my;

int main()
{
	my::Hash_table<int, std::string> zopa{4};
	zopa.insert(3, "pipiska");
	zopa.print();
	/*my::Hash_table<int, int> penis{6};
	zopa = penis;*/
	//cout << zopa.Get_size();
}

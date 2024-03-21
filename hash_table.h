// aisd_lab2_var12.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <vector>
#include <iostream>
namespace my
{
	using namespace std;
	template <typename Key, typename Value>
	class Hash_table
	{
	private:

		int size;
		vector<pair<Key, Value>> table;

	public:

		Hash_table(int size) : size(size), table(size, std::make_pair(Key{}, Value{})) {}

		int hash_function(Key key) {
			return key % size;
		}

		Hash_table(const Hash_table& other): size(other.size), table(other.table) {}

		~Hash_table() {}

		void swap(Hash_table& other)
		{
			std::swap(size, other.size);
			std::swap(table, other.table);
		}

		Hash_table& operator=(Hash_table other)
		{
			if (this == &other)
			{
				return *this;
			}
			swap(other);
			return *this;
		}
	};
}
// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.

// aisd_lab2_var12.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.
#pragma once

#include  <vector>
#include <iostream>
namespace my
{
	using namespace std;
    template <typename Key, typename Value>
    class HashTable {
    private:
        int TABLE_SIZE;// Размер таблицы
        std::vector<std::pair<Key, Value>> table;
        int numElements; // Количество элементов в таблице
        double loadFactor() {
            return static_cast<double>(numElements) / TABLE_SIZE;
        }
        void rehash() {
            int oldSize = TABLE_SIZE;
            TABLE_SIZE = TABLE_SIZE * 2; // Увеличиваем размер таблицы вдвое

            std::vector<std::pair<Key, Value>> oldTable = table;
            table = std::vector<std::pair<Key, Value>>(TABLE_SIZE, std::make_pair(Key(), Value()));
            numElements = 0;

            for (int i = 0; i < oldSize; i++) {
                if (oldTable[i].first != Key()) {
                    int index = hashFunction(oldTable[i].first);

                    while (table[index].first != Key()) {
                        index = (index + 1) % TABLE_SIZE; // Простое линейное пробирование
                    }

                    table[index] = oldTable[i];
                    numElements++;
                }
            }
        }
        void swap(HashTable& b) {
            using std::swap;
            swap(this->table, b.table);
            swap(this->TABLE_SIZE, b.TABLE_SIZE);
            swap(this->numElements, b.numElements);
        }
        int hashFunction(Key key) {
            const double A = (sqrt(5) - 1) / 2; // Константа A для мультипликативного метода
            size_t hashValue = std::hash<Key>{}(key);
            return static_cast<int>(TABLE_SIZE * (hashValue * A - static_cast<size_t>(hashValue * A)));
        }
    public:
        HashTable(int size = 101) : TABLE_SIZE(size), table(TABLE_SIZE, std::make_pair(Key(), Value())), numElements(0) {}

        int GetnumElements()
        {
            return numElements;
        }

        HashTable(const HashTable& other) {
            // Копируем размер таблицы
            this->TABLE_SIZE = other.TABLE_SIZE;
            this->numElements = other.numElements;
            // Инициализируем элементы в текущей таблице копиями элементов из другой таблицы
            this->table.assign(other.table.begin(), other.table.end());
            
        }

        ~HashTable() {

        }

        int Getsize()
        {
            return TABLE_SIZE;
        }

        // Вставка элемента в таблицу
        void insert(Key &key, Value &value) {
            int index = hashFunction(key);

            while (table[index].first != Key()) {
                index = (index + 1) % TABLE_SIZE; 
            }

            table[index] = std::make_pair(key, value);
            numElements++;

            if (loadFactor() > 0.7) {
                rehash();
            }
        }


        HashTable& operator=(HashTable other) {

            swap(other);
            return *this;
        }
       

        void insert_or_assign(Key &key, Value &value)
        {
            int index = hashFunction(key);

            while (table[index].first != Key() && table[index].first != key) {
                index = (index + 1) % TABLE_SIZE; // Простое линейное пробирование
            }

            if (table[index].first == Key()) {
                table[index] = std::make_pair(key, value);
                numElements++;
            }
         else {
          table[index].second = value;
        }

        if (loadFactor() > 0.7) {
            rehash();
        }
        }

        // Поиск элемента в таблице
        Value* search(Key key) {
            int index = hashFunction(key);
            int startIndex = index; 

            while (table[index].first != Key()) { 
                if (table[index].first == key) { 
                    return &table[index].second;
                }
                index = (index + 1) % TABLE_SIZE;
                if (index == startIndex) break;
            }

            return nullptr; // Если элемент не найден, возвращаем nullptr
        }
   

        void print() {
            for (const auto& entry : table) {
                if (entry.first != Key()) {
                    std::cout << "Key: " << entry.first << ", Value: " << entry.second << std::endl;
                }
            }
        }

        bool contains(Value value) {
            for (int i = 0; i < TABLE_SIZE; ++i) {
                if (table[i].first != Key() && table[i].second == value) {
                    return true;
                }
            }
            return false;
        }
        int count(Key key) {
            int index = hashFunction(key);
            int count = 0;

            while (table[index].first != Key()) {
                if (table[index].first == key) {
                    count++;
                }
                index = (index + 1) % TABLE_SIZE;
            }

            return count;
        }

        bool erase(const Key& key) {
            int index = hashFunction(key);
            int startIndex = index;

            while (table[index].first != Key() && table[index].first != key) {
                index = (index + 1) % TABLE_SIZE; // Простое линейное пробирование
                if (index == startIndex) {
                    return false; // Key not found
                }
            }

            if (table[index].first == Key()) {
                return false; // Key not found
            }

            table[index] = std::make_pair(Key(), Value()); // Mark as empty
            numElements--;

            // Rehash if load factor is too low
            if (loadFactor() < 0.25) {
                HashTable<Key, Value> newTable;
                newTable.TABLE_SIZE = TABLE_SIZE / 2;
                newTable.numElements = 0;

                for (int i = 0; i < TABLE_SIZE; i++) {
                    if (table[i].first != Key()) {
                        newTable.insert(table[i].first, table[i].second);
                    }
                }

                swap(newTable);
            }

            return true; // Key found and erased
        }
    };


    HashTable<int, int> count_numbers(const std::vector<int>& vec)
    {
        HashTable<int, int> table(vec.size());

        for (int i = 0; i < vec.size(); ++i) {
            table.insert_or_assign(vec[i], std::count(std::cbegin(vec), std::cend(vec), vec[i]));
        }
        return table;
    }

    void print_numbers_count(HashTable<int, int> table, int size) {
        for (int i = 0; i < size; ++i) {
            int* count_ptr = table.search(i);
            if (count_ptr != nullptr) {
                std::cout << "Number " << i << " counts " << *count_ptr << " times" << std::endl;
            }
        }
    }
}
// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.

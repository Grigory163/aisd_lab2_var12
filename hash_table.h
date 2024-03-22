// aisd_lab2_var12.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.
// паспорт снилс инн прописное 3 фотки рез флюры реквизиты сбера 
#pragma once

#include <vector>
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

        // Хеш-функция h(k) = k mod m
        int hashFunction(Key key) {
            return std::hash<Key>{}(key) % TABLE_SIZE;
        }

        // Рассчет коэффициента заполненности
        double loadFactor() {
            return static_cast<double>(numElements) / TABLE_SIZE;
        }

        // Вставка элемента в таблицу
        void insert(Key key, Value value) {
            int index = hashFunction(key);

            while (table[index].first != Key()) {
                index = (index + 1) % TABLE_SIZE; // Простое линейное пробирование
            }

            table[index] = std::make_pair(key, value);
            numElements++;

            // Проверка и перехеширование, если коэффициент заполненности превышает порог
            if (loadFactor() > 0.7) {
                rehash();
            }
        }

        void swap(HashTable& b) {
            using std::swap;
            swap(this->table, b.table);
            swap(this->TABLE_SIZE, b.TABLE_SIZE);
            swap(this->numElements, b.numElements);
        }

        HashTable& operator=(HashTable other) {

            swap(other);
            return *this;
        }

        // Перехеширование
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

        void insert_or_assign(Key key, Value value)
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
        Value search(Key key) {
            int index = hashFunction(key);
    
            while (table[index].first != Key()) {
                if (table[index].first == key) {
                    return table[index].second; // Возвращаем значение
                }
                index = (index + 1) % TABLE_SIZE;
            }

            return Value(); // Возвращаем пустое значение, если элемент не найден
        }
        // Удаление элемента из таблицы
        void remove(Key key) {
            int index = hashFunction(key);

            while (table[index].first != Key()) {
                if (table[index].first == key) {
                    table[index] = std::make_pair(Key(), Value()); // Удаляем элемент
                    numElements--;
                    return;
                }
                index = (index + 1) % TABLE_SIZE;
            }
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
    };
}
// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.

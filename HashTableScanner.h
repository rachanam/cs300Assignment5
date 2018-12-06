/*
 * Name: Rachana Mandal
 * Student id: 950699300 
 * Assignment 5 : Barcode scanner using Hash Table
 * */

#ifndef _HASHTABLESCANNER_
#define _HASHTABLESCANNER_
#include "HashTable.h"
#include "Scanner.h"

template <class T>
class HashTableScanner : Scanner<T>
{
  private:
    HashTable<T> hashTable;

  public:
    T scan(T &product)
    {
        T result = hashTable.search(product);
        return result;
    };
    void insert(T& item)
    {
        hashTable.insert(item);
    };
};
#endif //_HASHTABLESCANNER_
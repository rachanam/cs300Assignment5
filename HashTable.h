/*
 * Name: Rachana Mandal
 * Student id: 950699300 
 * Assignment 5: Barcode scanner using HashTable
 * */

#ifndef _HASHTABLE_
#define _HASHTABLE_
#include "LinkedList.h"

template <class T>
class HashTable
{
  private:
    int tableSize = 1000;
    LinkedList<T> *table = new LinkedList<T>[tableSize];

  public:
    void insert(T &item)
    {
        int bucket = item % tableSize; // find the bucket for the item to be inserted.

        table[bucket].insertFirst(item); // insert the item to the beginning of the linkedlist
    };

    T search(T &item)
    {
        int bucket = item % tableSize; // find the bucket for the item to be searched.
        return table[bucket].search(item);
    };

    ~HashTable()
    {
        delete table;
    }
};
#endif //_HASHTABLE_
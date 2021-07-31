#pragma once
#include <iostream>
#include <cstring>

using namespace std;

template <typename K, typename V>

class MyData {
   
public:
    K k;
    V val;
    int index;

    MyData(K k, V val, int index) {
        this->k = k;
        this->val = val;
        this->index = index ;
    }
};

template <typename K, typename V>

class MyIterator {
    K* k;
    V* v;
    int index;

public :

    MyIterator(K* addr1, V* addr2)
    {
        k = addr1;
        v = addr2;
        index = 0;
    }

    MyIterator& operator++()
    {
        k++;
        v++;
        index++;

        return *this;
    }

    bool operator != (MyIterator& m)
    {
        return (k != m.k && v != m.v && index != m.index);
    }
   
    MyData<K, V> operator*()
    {
        MyData<K, V> t(*k, *v, index);
        return t;
    }

   
};

template <typename K, typename V>

class Map
{

public:

    K keys[1000];
    V vals[1000];
    int index;

    Map() {

        index = 0;
    }

    V& operator[] (K key)
    {
        for (int i = 0; i < index; i++)
            if (keys[i] == key)
                return vals[i];

        keys[index] = key;
        vals[index] = "";
        index++;
        return vals[index - 1];
    }

    MyIterator<K, V> begin()
    {
        MyIterator<K, V> tmp;

        tmp.k = &keys[0];
        tmp.v = &vals[0];
        tmp.index = 0;

        return tmp;
    }

    MyIterator<K, V> end()
    {
        MyIterator<K, V> tmp;

        tmp.k = &keys[index];
        tmp.v = &vals[index];
        tmp.index = index;

        return tmp;
    }

   
};

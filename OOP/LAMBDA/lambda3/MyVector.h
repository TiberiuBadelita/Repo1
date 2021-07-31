#pragma once

class MyVector {

    int* v;

public:

    int size;

    MyVector() {

        size = 0;
    }

    bool Add(int x) {
        v = new int(x);
        size++;

        return true;
    }// return true if the value was added. As a result, the size of the vector increases with one.


    bool Delete(int index) {
        delete int(v[index]);

        size--;

        return true;
    } // returns true if the value from the index was removed. As a result, the size of the vector decreases with one.

    void Iterate((void)(*f)())
    {
            f();

    }
};

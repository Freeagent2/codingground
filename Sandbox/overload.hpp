#include <iostream>

using namespace std;

class Overload
{
public:
    Overload() { nextIndex = 0; cout << "Overload() constructor, pointer at " << this << endl; }
    virtual ~Overload() { cout << "Overload() destructor, pointer at " << this << endl; }
    
    void *operator new(size_t size)
    {
        void *rtrn = &Storage[nextIndex];
        nextIndex++;
        cout << "Overload::new() use memory location " << nextIndex << endl;
        return rtrn;
    }
    
    void operator delete(void *ptr)
    {
        cout << "Overload::delete() release memory location " << &Storage[nextIndex] << endl;
        nextIndex--;
    }
    static int nextIndex;
    static Overload Storage[5];
};
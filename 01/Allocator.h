#include <cstdio>
#include <iostream>
using namespace std;

class Allocator
{
public:
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
    Allocator();
    ~Allocator();

    size_t getSize();
    char* getStart();
    char* getOffset();

private:
    size_t size = 0;
    char* start = nullptr;
    char* offset = nullptr;
};
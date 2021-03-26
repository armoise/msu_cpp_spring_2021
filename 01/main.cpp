#include "Allocator.h"

#include <cstddef>
#include <iostream>
#include <cassert>

using namespace std;


void test_1(){
    Allocator al;
    al.makeAllocator(5);
    assert(al.getStart() != nullptr);
    cout << "Test 1 - success" << endl;
}


void test_2(){
    Allocator al;
    al.makeAllocator(5);
    char *mem = al.alloc(3);
    assert(mem != nullptr);
    cout << "Test 2 - success" << endl;
}


void test_3(){
    Allocator al;
    al.makeAllocator(5);
    al.alloc(2);
    char *mem = al.alloc(3);
    assert(mem != nullptr);
    cout << "Test 3 - success" << endl;
}


void test_4(){
    Allocator al;
    al.makeAllocator(5);
    al.alloc(3);
    char* mem = al.alloc(3);
    assert(mem != nullptr);
    cout << "Test 4 - success" << endl;
}


void test_5(){
    Allocator al;
    al.makeAllocator(5);
    al.alloc(5);
    al.reset();
    assert(al.getStart() == al.getOffset());
    assert(al.getSize() == 5);
    cout << "Test 5 - success" << endl;
}

int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();

    return 0;
}

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
    assert(mem == nullptr);
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


void test_6(){
    Allocator al;
    al.makeAllocator(3);
    al.alloc(4);
    al.makeAllocator(5);
    assert(al.getSize() == 5);
    assert(al.getStart() != nullptr);
    cout << "Test 6 - success" << endl;
}


void test_7(){
    Allocator al;
    char* mem = al.alloc(4);
    al.makeAllocator(5);
    assert(al.getSize() == 5);
    assert(mem == nullptr);
    assert(al.getStart() != nullptr);
    cout << "Test 7 - success" << endl;
}

int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();

    return 0;
}

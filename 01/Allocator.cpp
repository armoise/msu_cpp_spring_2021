#include "Allocator.h"


void Allocator::makeAllocator(size_t maxSize) {
    if(start != nullptr)
        delete []start;
    start = new char[maxSize];
    offset = start;
    size = maxSize;
}


char* Allocator::alloc(size_t size) {
    if(this->size - size < 0 || start == nullptr) {
        return nullptr;
    }
    char *result = offset;
    offset += size;
    this->size -= size;

    return result;
}


void Allocator::reset() {
    size += offset - start;
    offset = start;
}


Allocator::Allocator() {
    size = 0;
    start = nullptr;
    offset = nullptr;
}


Allocator::~Allocator() {
    delete []start;
}


char* Allocator::getOffset() {
    return offset;
}


size_t Allocator::getSize() {
    return size;
}


char* Allocator::getStart() {
    return start;
}

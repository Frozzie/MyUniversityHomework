#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "vector.h"

void test_pushBack_emptyVector()
{
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(v.size == 1);
}

void test_pushBack_fullVector()
{
    vector v = createVector(1);
    pushBack(&v, 1);
    pushBack(&v, 1);
    assert(v.size == 2);
    assert(v.capacity == 2);
}

void test_popBack_notEmptyVector() 
{
    vector v = createVector(0);

    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test() 
{
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    // ����������� �����
}

int main() 
{
    // vector v = createVector(SIZE_MAX);t
    test();

    return 0;
}
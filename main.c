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

void test_atVector_notEmptyVector()
{
    vector v = createVector(2);
    
    pushBack(&v, 1);
    int *answ = atVector(&v, 0);

    assert(*answ == 1);
}

void test_atVector_requestToLastElement()
{
    vector v = createVector(2);
    
    pushBack(&v, 1);
    pushBack(&v, 2);
    int *answ = atVector(&v, 1);

    assert(*answ == 2);
}

void test_back_oneElementInVector()
{
    vector v = createVector(2);
    
    pushBack(&v, 1);
    pushBack(&v, 2);

    int *answ = back(&v);

    assert(*answ == 2);
}   

void test_front_oneElementInVector()
{
    vector v = createVector(2);
    
    pushBack(&v, 1);

    int *answ = back(&v);

    assert(*answ == 1);
}

void test() 
{
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
    // последующие тесты
}

int main() 
{
    // vector v = createVector(SIZE_MAX);t
    test();

    return 0;
}
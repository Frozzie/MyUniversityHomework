#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "vector.h"
#include "vectorVoid.h"

void test_pushBack_emptyVector()
{
    vector v = createVector(0);

    pushBack(&v, 1);
    assert(v.size == 1);

    deleteVector(&v);
}

void test_pushBack_fullVector()
{
    vector v = createVector(1);

    pushBack(&v, 1);
    pushBack(&v, 1);
    assert(v.size == 2);
    assert(v.capacity == 2);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() 
{
    vector v = createVector(0);

    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_atVector_notEmptyVector()
{
    vector v = createVector(2);
    
    pushBack(&v, 1);
    int *answ = atVector(&v, 0);

    assert(*answ == 1);

    deleteVector(&v);
}

void test_atVector_requestToLastElement()
{
    vector v = createVector(2);
    
    pushBack(&v, 1);
    pushBack(&v, 2);
    int *answ = atVector(&v, 1);

    assert(*answ == 2);

    deleteVector(&v);
}

void test_back_oneElementInVector()
{
    vector v = createVector(2);
    
    pushBack(&v, 1);
    pushBack(&v, 2);

    int *answ = back(&v);

    assert(*answ == 2);

    deleteVector(&v);
}   

void test_front_oneElementInVector()
{
    vector v = createVector(2);
    
    pushBack(&v, 1);

    int *answ = back(&v);

    assert(*answ == 1);

    deleteVector(&v);
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
    uint32_t n;

    scanf("%ud", &n);

    vectorVoid v = createVectorV(0, sizeof(float));

    for (size_t i = 0; i < n; i++)
    {
        float x;
        scanf("%f", &x);
        pushBackV(&v, &x);
    }

    for (size_t i = 0; i < n; i++)
    {
        float x;
        getVectorValueV(&v, i, &x);
        printf("%f ", x);
    }

    return 0;
}
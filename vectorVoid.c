#include <stdint.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize)
{
    vectorVoid new_vector;

    if(n > 0)
    {
        new_vector.data = malloc(baseTypeSize * n);

        if(new_vector.data != NULL)
        {
            new_vector.capacity = n;
        }
        else
        {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
    else
    {
        new_vector.data = NULL;
        new_vector.capacity = 0;
    }

    new_vector.size = 0;
    new_vector.baseTypeSize = baseTypeSize;

    return new_vector;
}

void reserveV(vectorVoid *v, size_t newCapacity)
{
    int *new_data;
    
    if(newCapacity > 0)
    {
        new_data = malloc(v->baseTypeSize * newCapacity);

        if(new_data == NULL)
        {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        // размер больше
        if(v->capacity < newCapacity)
        {
            memcpy(new_data, v->data, v->capacity * v->baseTypeSize);
        }
        else
        {
            memcpy(new_data, v->data, newCapacity * v->baseTypeSize);
        }   

        v->capacity = newCapacity;

        if(v->data != NULL)
        {
            free(v->data);
        }
        v->data = new_data;
    }
    else
    {
        free(v->data);
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
    }
}

void shrinkToFitV(vectorVoid *v)
{
    v->capacity = v->size;
}

void clearV(vectorVoid *v)
{
    v->size = 0;
}

void deleteVectorV(vectorVoid *v)
{
    free(v->data);
    v->data = 0;
    v->size = 0;
    v->capacity = 0;
}

bool isEmptyV(vectorVoid *v)
{
    return v->size == 0;
}

bool isFullV(vectorVoid *v)
{
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination)
{
    void *source = (void *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source)
{
    void *destination = (void *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v)
{
    if(v->size == 0)
    {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->size--;
}

void pushBackV(vectorVoid *v, void *source)
{
    if(v->size == v->capacity) // нет места
    {
        if(v->capacity == 0)
        {
            reserve(v, 1);
        }
        else
        {
            reserve(v, v->capacity * 2);
        }
    }

    setVectorValueV(v, v->size, source);
    v->size++;
}
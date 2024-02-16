#include <stdint.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "vector.h"

vector createVector(int size)
{
    vector new_vector;

    if(size > 0)
    {
        new_vector.data = malloc(sizeof(int) * size);

        if(new_vector.data != NULL)
        {
            new_vector.capacity = size;
        }
        else
        {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }

    new_vector.data = NULL;
    new_vector.capacity = 0;
    new_vector.size = 0;

    return new_vector;
}

void reserve(vector *v, size_t newCapacity)
{
    int *new_data;

    
    if(newCapacity > 0)
    {
        new_data = malloc(sizeof(int) * newCapacity);

        if(new_data == NULL)
        {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        // размер больше
        if(v->capacity < newCapacity)
        {
            memcpy(new_data, v->data, v->capacity * sizeof(int));
            v->size = newCapacity;
        }
        else
        {
            memcpy(new_data, v->data, newCapacity * sizeof(int));
        }   

        v->capacity = newCapacity;

        free(v->data);
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

void clear(vector *v)
{
    v->size = 0;
}

void shrinkToFit(vector *v)
{
    v->capacity = v->size;
}

void deleteVector(vector *v)
{
    free(v->data);
    v->data = 0;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v)
{
    return v->size == 0;
}

bool isFull(vector *v)
{
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i)
{
    return v->data[i];
}

void pushBack(vector *v, int x)
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

    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v)
{
    if(v->size == 0)
    {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->size--;
}

int* atVector(vector *v, size_t index)
{
    if(index > v->size)
    {
        fprintf(stderr, "IndexError: v->data[index] does not exist");
        exit(1);
    }
    else
    {
        return v->data[index];
    }
}

int* back(vector *v)
{
    return v->data[v->size];
}

int* front(vector *v)
{
    return v->data[v->size];
}

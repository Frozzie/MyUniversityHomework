#include <stdint.h>
#include <stdio.h>
#include <malloc.h>
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
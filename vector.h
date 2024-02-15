#include <stddef.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

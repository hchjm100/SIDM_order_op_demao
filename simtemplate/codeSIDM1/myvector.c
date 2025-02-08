// *********************************
// Created by Asher Sang on 2025/2/7.
// *********************************

#include <stdio.h>
#include <stdlib.h>
#include "proto.h"

// Function to initialize the vector with an initial capacity
void vector_init(myVector *vec, size_t initial_capacity) {
    vec->data = malloc(initial_capacity * sizeof(double));
    if (vec->data == NULL) {
        printf(stderr, "Memory allocation failed.\n");
        endrun(EXIT_FAILURE);
    }
    vec->size = 0;
    vec->capacity = initial_capacity;
}

// Function to append a new element to the vector
void vector_push_back(myVector *vec, double value) {
    // If we run out of space, double the capacity
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        double *temp = realloc(vec->data, vec->capacity * sizeof(double));
        if (temp == NULL) {
            fprintf(stderr, "Memory reallocation failed.\n");
            free(vec->data);
            endrun(EXIT_FAILURE);
        }
        vec->data = temp;
    }
    vec->data[vec->size++] = value;
}

// Function to free the allocated memory
void vector_free(myVector *vec) {
    free(vec->data);
    vec->data = NULL;
    vec->size = vec->capacity = 0;
}
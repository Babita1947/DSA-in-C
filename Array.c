#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the Array struct
struct Array {
    int capacity;
    int lastIndex;
    int *ptr;
};

// Function to create an array
void createArray(struct Array *arr, int cap) {
    arr->capacity = cap;
    arr->lastIndex = -1;
    arr->ptr = (int *)malloc(sizeof(int) * cap);
}

// Function to insert an element at a given index
void insert(struct Array *arr, int index, int data) {
    if (index < 0 || index > arr->lastIndex + 1) {
        printf("Invalid Index\n");
        return;
    }
    if (arr->lastIndex == arr->capacity - 1) {
        printf("Overflow\n");
        return;
    }
    
    for (int i = arr->lastIndex; i >= index; i--) {
        arr->ptr[i + 1] = arr->ptr[i];
    }
    
    arr->ptr[index] = data;
    arr->lastIndex++;
}

// Function to append an element to the end of the array
void append(struct Array *arr, int data) {
    if (arr->lastIndex < arr->capacity - 1) {
        arr->lastIndex++;
        arr->ptr[arr->lastIndex] = data;
    } else {
        printf("Overflow: Append not performed\n");
    }
}

// Function to get an item at a given index
int getItem(struct Array *arr, int index) {
    if (index < 0 || index > arr->lastIndex) {
        printf("Invalid Index or Array is empty\n");
        return -1;
    }
    return arr->ptr[index];
}

// Function to check if the array is empty
bool isEmpty(struct Array *arr) {
    return (arr->lastIndex == -1);
}

// Function to check if the array is full
bool isFull(struct Array *arr) {
    return (arr->lastIndex == arr->capacity - 1);
}

// Function to delete an element at a given index
void del(struct Array *arr, int index) {
    if (index < 0 || index > arr->lastIndex) {
        printf("Invalid Index or Underflow\n");
        return;
    }
    
    for (int i = index; i < arr->lastIndex; i++) {
        arr->ptr[i] = arr->ptr[i + 1];
    }
    
    arr->lastIndex--;
}

// Function to edit an element at a given index
void edit(struct Array *arr, int index, int newdata) {
    if (index < 0 || index > arr->lastIndex) {
        printf("Invalid Index\n");
        return;
    }
    
    arr->ptr[index] = newdata;
}

// Function to get the count of elements in the array
int count(struct Array *arr) {
    return (arr->lastIndex + 1);
}

// Function to get the capacity of the array
int getCapacity(struct Array *arr) {
    return arr->capacity;
}

void display(struct Array *arr)
{
    for(int i=0;i<=arr->lastIndex;i++)
    {
        printf("%d ",arr->ptr[i]);
    }
}

// Function to release memory
void destroyArray(struct Array *arr) {
    free(arr->ptr);
    arr->ptr = NULL;
}

int main() {
    struct Array arr1;
    createArray(&arr1, 12);
    append(&arr1, 10);
    append(&arr1, 20);
    append(&arr1, 30);
    append(&arr1, 40);
    append(&arr1, 50);
    append(&arr1, 60);
    append(&arr1, 70);
    append(&arr1, 80);
    append(&arr1, 90);
    append(&arr1, 100);
    append(&arr1, 110);
    append(&arr1, 120);
    edit(&arr1,4,19);
    display(&arr1);
    struct Array arr2;
    createArray(&arr2, arr1.capacity);
    
    // Copy elements from arr1 to arr2
    // for (int i = 0; i <= arr1.lastIndex; i++) {
    //     arr2.ptr[i] = arr1.ptr[i];
    //     arr2.lastIndex++;
    // }
    
    // You can now use arr1 and arr2 in a similar way as in your C++ code
    
    // Don't forget to release memory when done
    // destroyArray(&arr1);
    // destroyArray(&arr2);
    
    return 0;
}

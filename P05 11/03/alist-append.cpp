#include "alist.h"
#include <iostream>

using namespace std;

void append(alist* a, const alist* b) {
    // If list 'a' is empty, simply copy the elements from list 'b' to 'a'
    if (a->size == 0) {
        // Copy elements of list 'b' to 'a'
        a->size = b->size;
        a->elements = new int[a->size];
        for (int i = 0; i < a->size; ++i) {
            a->elements[i] = b->elements[i];
        }
        return;
    }

    // If list 'b' is empty or both lists are empty, no need to append, just return
    if (b->size == 0)
        return;

    // Calculate the size of the new list
    int newSize = a->size + b->size;

    // Create a new array to hold the appended elements
    int* newElements = new int[newSize];

    // Copy elements of list 'a' to the new array
    for (int i = 0; i < a->size; ++i) {
        newElements[i] = a->elements[i];
    }

    // Copy elements of list 'b' to the new array
    for (int i = 0; i < b->size; ++i) {
        newElements[a->size + i] = b->elements[i];
    }

    // Free memory allocated for the original 'a->elements'
    delete[] a->elements;

    // Update 'a' to point to the new array and update its size
    a->elements = newElements;
    a->size = newSize;
}



int main() {
    { alist* a = empty();
  const alist* b = empty();
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }
    { alist* a = empty();
  const int nB = 2;
  int eB[nB] = { 1, 2 };
  const alist* b = build(nB, eB);
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }

    { const int nA = 2;
  int eA[nA] = { 1, 2 }; 
  alist* a = build(nA, eA);
  const alist* b = empty();
  append(a, b);
  print(a);
  destroy(a); 
  destroy(b); }

    { const int nA = 2;
  int eA[nA] = { 1, 2 };
  alist* a = build(nA, eA);
  const int nB = 3;
  int eB[nB] = { 3, 4, 5 };
  const alist* b = build(nB, eB);
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }

    { const int nA = 4;
  int eA[nA] = { 1, 2, 3, 4 };
  alist* a = build(nA, eA);
  const int nB = 3;
  int eB[nB] = { 5, 6, 7 };
  const alist* b = build(nB, eB);
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }

    return 0;
}
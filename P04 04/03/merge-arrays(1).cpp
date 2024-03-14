#include <iostream>
#include "print_array.h" // Importa a função print_array para imprimir arrays

void merge_arrays(const int a[], int na, const int b[], int nb, int c[]) {
    int i = 0, j = 0, k = 0;
    
    // Merge dos dois arrays até que um deles seja totalmente percorrido
    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    
    // Adiciona os elementos restantes de a (se houver)
    while (i < na) {
        c[k++] = a[i++];
    }
    
    // Adiciona os elementos restantes de b (se houver)
    while (j < nb) {
        c[k++] = b[j++];
    }
}

int main() {
    // Teste 1
    const int NA1 = 4, NB1 = 6;
    int a1[NA1] = { 1, 2, 4, 7 };
    int b1[NB1] = { 0, 3, 5, 6, 8, 9 };
    int c1[NA1 + NB1];
    merge_arrays(a1, NA1, b1, NB1, c1);
    print_array(c1, NA1 + NB1);

    // Teste 2
    const int NA2 = 6, NB2 = 4;
    int a2[NA2] = { 0, 3, 5, 6, 8, 9 };
    int b2[NB2] = { 1, 2, 4, 7 };
    int c2[NA2 + NB2];
    merge_arrays(a2, NA2, b2, NB2, c2);
    print_array(c2, NA2 + NB2);

    // Teste 3
    const int NA3 = 2, NB3 = 3;
    int a3[NA3] = { 0, 1 };
    int b3[NB3] = { 2, 3, 4 };
    int c3[NA3 + NB3];
    merge_arrays(a3, NA3, b3, NB3, c3);
    print_array(c3, NA3 + NB3);

    // Teste 4
    const int NA4 = 3, NB4 = 2;
    int a4[NA4] = { 2, 3, 4 };
    int b4[NB4] = { 0, 1 };
    int c4[NA4 + NB4];
    merge_arrays(a4, NA4, b4, NB4, c4);
    print_array(c4, NA4 + NB4);

    // Teste 5
    const int NA5 = 15, NB5 = 15;
    int a5[NA5] = { 0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 9 };
    int b5[NB5] = { 0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
    int c5[NA5 + NB5];
    merge_arrays(a5, NA5, b5, NB5, c5);
    print_array(c5, NA5 + NB5);

    return 0;
}

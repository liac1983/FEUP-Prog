#include <iostream>
#include <climits>

int max(const int a[], int n) {
    if (n <= 0) {
        // Se não houver elementos no array, retornar um valor inválido
        return INT_MIN; // Valor mínimo representável para int
    }
    
    int maxVal = a[0]; // Assume que o primeiro elemento é o máximo inicialmente
    
    for (int i = 1; i < n; ++i) {
        if (a[i] > maxVal) {
            maxVal = a[i]; // Se encontrar um valor maior, atualiza o máximo
        }
    }
    
    return maxVal;
}

int main() {
    const int n1 = 1;
    const int a1[n1] = { -123 };
    std::cout << max(a1, n1) << '\n'; // Output: -123
    
    const int n2 = 3; 
    const int a2[n2] = { -3, -2, -1 };
    std::cout << max(a2, n2) << '\n'; // Output: -1
    
    const int n3 = 4; 
    const int a3[n3] = { 4, -2, 3, 1 };
    std::cout << max(a3, n3) << '\n'; // Output: 4
    
    const int n4 = 9;
    const int a4[n4] = { 10, 20, 30, -2, 50, 3, 1, 50, 49 };
    std::cout << max(a4, n4) << '\n'; // Output: 50
    
    return 0;
}

#include <iostream>

const int MAX_N = 100; // Definindo um tamanho máximo para o array

unsigned long bc(unsigned long n, unsigned long k) {
    // Se k for maior que n-k, calcular n choose n-k para minimizar os cálculos
    if (k > n - k) {
        k = n - k;
    }

    // Inicializar o resultado como 1
    unsigned long result = 1;

    // Calcular o coeficiente binomial usando a fórmula: (n choose k) = n! / (k! * (n - k)!)
    for (unsigned long i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}

unsigned long bell(unsigned long n) {
    unsigned long bell_numbers[MAX_N + 1]; // Definindo um array com tamanho máximo
    bell_numbers[0] = 1;

    for (unsigned long i = 1; i <= n; ++i) {
        bell_numbers[i] = 0;
        for (unsigned long j = 0; j < i; ++j) {
            bell_numbers[i] += bc(i - 1, j) * bell_numbers[j];
        }
    }

    return bell_numbers[n];
}

int main() {
    std::cout << bell(0) << '\n';
    std::cout << bell(1) << '\n';
    std::cout << bell(2) << '\n';
    std::cout << bell(3) << '\n';
    std::cout << bell(4) << '\n';
    std::cout << bell(6) << '\n';

    return 0;
}

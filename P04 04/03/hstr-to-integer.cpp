#include <iostream>

unsigned long hstr_to_integer(const char hstr[]) {
    unsigned long result = 0;

    
    for (int i = 0; hstr[i] != '\0'; ++i) {
        char c = hstr[i];

        // Converte o caractere para o valor correspondente em decimal
        unsigned long digit = 0;
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
        } else {
            // Caractere inválido, retorna 0
            return 0;
        }

        // Multiplica o resultado atual por 16 e adiciona o valor do dígito
        result = result * 16 + digit;
    }

    return result;
}

int main() {
    // Teste 1
    std::cout << hstr_to_integer("0") << '\n';

    // Teste 2
    std::cout << hstr_to_integer("A") << '\n';

    // Teste 3
    std::cout << hstr_to_integer("19") << '\n';

    // Teste 4
    std::cout << hstr_to_integer("fF") << '\n';

    // Teste 5
    std::cout << hstr_to_integer("CafeBabe2022") << '\n';

    return 0;
}

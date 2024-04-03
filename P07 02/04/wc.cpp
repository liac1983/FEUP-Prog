#include <iostream>
#include <fstream>
#include <string>
#include "wc.h" // Assume que o arquivo wc.h está na mesma pasta do código-fonte

wcresult wc(const std::string& filename) {
    wcresult result = {0, 0, 0}; // Inicializa a estrutura wcresult

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return result; // Retorna a estrutura wcresult vazia em caso de falha
    }

    std::string line;
    while (std::getline(file, line)) {
        result.lines++; // Incrementa o contador de linhas

        // Conta o número de palavras na linha
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            result.words++; // Incrementa o contador de palavras
        }

        // Atualiza o número de bytes
        result.bytes += line.size() + 1; // Adiciona o tamanho da linha mais 1 para o caractere de nova linha
    }

    file.close();
    return result;
}

int main() {
    // Teste com os arquivos fornecidos
    wcresult r1 = wc("ex2/p2_test1.txt");
    std::cout << r1.lines << ' ' << r1.words << ' ' << r1.bytes << '\n';

    wcresult r2 = wc("ex2/p2_test2.txt");
    std::cout << r2.lines << ' ' << r2.words << ' ' << r2.bytes << '\n';

    wcresult r3 = wc("ex2/p2_test3.txt");
    std::cout << r3.lines << ' ' << r3.words << ' ' << r3.bytes << '\n';

    wcresult r4 = wc("ex2/p2_test4.txt");
    std::cout << r4.lines << ' ' << r4.words << ' ' << r4.bytes << '\n';

    wcresult r5 = wc("ex2/p2_test5.txt");
    std::cout << r5.lines << ' ' << r5.words << ' ' << r5.bytes << '\n';

    return 0;
}

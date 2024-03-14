#include <iostream>

void int_to(int n, char str[], int& pos) {
    if (n == 0) {
        str[pos++] = '0'; // Adiciona o dígito 0
        return;
    }

    int digitCount = 0;
    int temp = n;
    
    // Count the number of digits in the number
    while (temp != 0) {
        temp /= 10;
        digitCount++;
    }

    
    while (n != 0) {
        str[pos + digitCount - 1] = '0' + n % 10;
        n /= 10;
        digitCount--;
        pos++; // Increment position after writing each digit
    }
}



void rle_encode(const char str[], char rle[]) {
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        char currentChar = str[i];
        int count = 1;
        
        // Count consecutive occurrences of the current character
        while (str[i + 1] == currentChar) {
            count++;
            i++;
        }
        
        
        int_to(count, rle, j);
        
        // Append character to rle
        rle[j] = currentChar;
        j++;

        
        i++;
    }
    
   
    rle[j] = '\0';
}


int main() {
    char rle1[1] = { -1 };
    rle_encode("", rle1);
    std::cout << rle1 << std::endl;

    char rle2[2 + 1] = { -1, -1, -1 };
    rle_encode("a", rle2);
    std::cout << rle2 << std::endl;

    char rle3[10 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    rle_encode("abcde", rle3);
    std::cout << rle3 << std::endl;

    char rle4[9 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    rle_encode("aaaaabbbbbbbbbbbcccd", rle4);
    std::cout << rle4 << std::endl;

    char rle5[3 + 1] = { -1, -1, -1, -1 };
    rle_encode("xxxxxxxxxxxxxxxxxxxx", rle5);
    std::cout << rle5 << std::endl;

    return 0;
}

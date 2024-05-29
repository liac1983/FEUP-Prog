#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>

using namespace std;

void count_words(const string& str, map<string, size_t>& count) {
    // Converter a string para minúsculas
    string lower_str = str;
    for (char& c : lower_str) {
        c = tolower(c);
    }
    
    // Contar as palavras
    istringstream iss(lower_str);
    string word;
    while (iss >> word) {
        // Remover qualquer pontuação no final da palavra
        while (!word.empty() && !isalnum(word.back())) {
            word.pop_back();
        }
        // Incrementar o contador para a palavra
        if (!word.empty()) {
            count[word]++;
        }
    }
}

void show_map(const map<string, size_t>& count) {
    cout << "[ ";
    for (const auto& e : count) {
        cout << e.first << ":" << e.second << ' ';
    }
    cout << "]\n";
}

int main() {
    // Teste 1
    string s1 = "If you want to buy  buy  if you don't want to buy  bye bye";
    map<string, size_t> count1;
    count_words(s1, count1);
    show_map(count1); // Saída: [ buy:3 bye:2 don't:1 if:2 to:2 want:2 you:2 ]
    
    // Teste 2
    string s2 = "You can fool some of the people all of the time and all of the people some of the time  but you cannot fool all of the people all of the time";
    map<string, size_t> count2;
    count_words(s2, count2);
    show_map(count2); // Saída: [ all:4 and:1 but:1 can:1 cannot:1 fool:2 of:6 people:3 some:2 the:6 time:3 you:2 ]
    
    // Teste 3
    string s3 = "A tutor who tooted the flute tried to tutor two young tooters to toot   Said the two to the tutor is it tougher to toot or to tutor two young tooters to toot";
    map<string, size_t> count3;
    count_words(s3, count3);
    show_map(count3); // Saída: [ a:1 flute:1 is:1 it:1 or:1 said:1 the:3 to:6 toot:3 tooted:1 tooters:2 tougher:1 tried:1 tutor:4 two:3 who:1 young:2 ]
    
    // Teste 4
    string s4 = "You do not need to turn on a night light on a clear night like tonight because in a clear night there is always a light light and tonight is a clear night";
    map<string, size_t> count4;
    count_words(s4, count4);
    show_map(count4); // Saída: [ a:5 always:1 and:1 because:1 clear:3 do:1 in:1 is:2 light:3 like:1 need:1 night:4 not:1 on:2 there:1 to:1 tonight:2 turn:1 you:1 ]
    
    // Teste 5
    string s5 = "If one doctor doctors another doctor  Does the doctor who doctors the doctor  Doctor the way the doctor he is doctoring doctor  Or does he doctor the doctor  The way the doctor who doctors doctor";
    map<string, size_t> count5;
    count_words(s5, count5);
    show_map(count5); // Saída: [ another:1 doctor:11 doctoring:1 doctors:3 does:2 he:2 if:1 is:1 one:1 or:1 the:7 way:2 who:2 ]
    
    return 0;
}

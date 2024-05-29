#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

// Function to convert a string to lowercase
string toLowercase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to count the occurrences of words in a string
void count_words(const string& str, vector<pair<string, size_t>>& count) {
    count.clear();
    // Convert the input string to lowercase
    string lowercase_str = toLowercase(str);
    // Initialize a map to store word counts
    unordered_map<string, size_t> word_counts;
    // Tokenize the string and count word occurrences
    istringstream iss(lowercase_str);
    string word;
    while (iss >> word) {
        word_counts[word]++;
    }
    // Populate the result vector with word counts
    for (const auto& pair : word_counts) {
        count.push_back(pair);
    }
    // Sort the result vector alphabetically by word
    sort(count.begin(), count.end());
}

// Function to print the contents of the vector
void show_vector(const vector<pair<string, size_t>>& count) {
    cout << "[ ";
    for (const auto& e : count) {
        cout << e.first << ":" << e.second << ' ';
    }
    cout << "]\n";
}

int main() {
    // Test cases
    string s1 = "If you want to buy  buy  if you don't want to buy  bye bye";
    string s2 = "You can fool some of the people all of the time and all of the people some of the time  but you cannot fool all of the people all of the time";
    string s3 = "A tutor who tooted the flute tried to tutor two young tooters to toot   Said the two to the tutor is it tougher to toot or to tutor two young tooters to toot";
    string s4 = "You do not need to turn on a night light on a clear night like tonight because in a clear night there is always a light light and tonight is a clear night";
    string s5 = "If one doctor doctors another doctor  Does the doctor who doctors the doctor  Doctor the way the doctor he is doctoring doctor  Or does he doctor the doctor  The way the doctor who doctors doctor";

    vector<pair<string, size_t>> count;

    count_words(s1, count);
    show_vector(count);

    count_words(s2, count);
    show_vector(count);

    count_words(s3, count);
    show_vector(count);

    count_words(s4, count);
    show_vector(count);

    count_words(s5, count);
    show_vector(count);

    return 0;
}

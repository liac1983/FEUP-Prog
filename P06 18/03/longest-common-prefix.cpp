#include <iostream>
#include <vector>
#include <string>

std::string longest_prefix(const std::vector<std::string>& v) {
    if (v.empty()) return ""; // If the vector is empty, return an empty string

    // Iterate through the characters of the first string
    for (std::size_t i = 0; i < v[0].size(); ++i) {
        // Compare the character at position i of the first string with all other strings
        for (std::size_t j = 1; j < v.size(); ++j) {
            // If the current string is shorter than i or the character at position i is different,
            // return the substring of the first string from index 0 to i
            if (i >= v[j].size() || v[j][i] != v[0][i]) {
                return v[0].substr(0, i);
            }
        }
    }

    // If we haven't returned yet, the entire first string is the longest common prefix
    return v[0];
}

int main() {
    // Test cases
    std::cout << "\"" << longest_prefix({ "apple", "apply", "ape", "april" }) << "\"\n";
    std::cout << "\"" << longest_prefix({ "ap", "apple", "apply", "ape", "april", "aq", "x" }) << "\"\n";
    std::cout << "\"" << longest_prefix({ "geezer", "geeksforgeeks", "geeks", "geek" }) << "\"\n";
    std::cout << "\"" << longest_prefix({ "sedatesingratiateconcomitant", "sedatesparleypoliteness", "sedateselbowsHahn", "sedatesgloweringimbecility's", "sedatesbuttershexing", "sedatesKwangju'smulch's", "sedatesunwiserN", "sedatesprepossessedboggles", "sedatesinterrelationshipdialings", "sedatesgropesNelsen's", "sedatesMayfaircondemnations" }) << "\"\n";
    std::cout << "\"" << longest_prefix({ "symmetricstalwartscorn'flowers", "symmetricShetland'ssuccessfully", "symmetricreceiver'shipsteed", "symmetricGrailsflown", "symmetricpromenadingoutflank", "symmetricdrugg'ingseizure", "symmetricsanctumsove'rprinting", "symmetricCitroentransgr'essed", "symmetricdissembledwinging", "symmetric'recoupingCinderella" }) << "\"\n";
    return 0;
}

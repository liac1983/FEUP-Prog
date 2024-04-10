#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Person {
public:
    Person(const std::string& name, const std::string& address, const std::string& phone)
        : name_(name), address_(address), phone_(phone) {}

    std::string get_name() const { return name_; }
    std::string get_address() const { return address_; }
    std::string get_phone() const { return phone_; }

private:
    std::string name_;    // Name
    std::string address_; // Address
    std::string phone_;   // Phone
};

void show_persons_data(const std::vector<Person>& persons) {
    std::cout << '[' << std::endl;
    for (const auto& person : persons) {
        std::cout << "  " << person.get_name() << " : " << person.get_address() << " : " << person.get_phone() << std::endl;
    }
    std::cout << ']' << std::endl;
}

void read_persons_data(const std::string& file_name, std::vector<Person>& persons) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Error opening file " << file_name << std::endl;
        return;
    }

    std::string line;
    std::string name, address, phone;
    while (std::getline(file, line)) {
        name = line;
        std::getline(file, address);
        std::getline(file, phone);
        persons.emplace_back(name, address, phone);
    }

    file.close();
}

bool compare_persons(const Person& p1, const Person& p2) {
    return p1.get_name() < p2.get_name();
}

void sort_persons_by_name(std::vector<Person>& persons) {
    std::sort(persons.begin(), persons.end(), compare_persons);
}

int main() {
    

    { vector<Person> persons { 
    Person("Pedro Miguel Faria", "Rua de Santa Catarina, 1234, Porto", "911123456"),
    Person("Maria Roberta Fernandes", "Rua do Santo Silva, 4321, Porto", "987654321") };
  show_persons_data(persons); }

    { vector<Person> persons;
 read_persons_data("persons/persons-1.txt", persons);
 show_persons_data(persons); }

    { vector<Person> persons;
  read_persons_data("persons/persons-1.txt", persons);
  sort_persons_by_name(persons);
  show_persons_data(persons); }

    { vector<Person> persons;
  read_persons_data("persons/persons-2.txt", persons);
  sort_persons_by_name(persons);
  show_persons_data(persons); }

    return 0;
}

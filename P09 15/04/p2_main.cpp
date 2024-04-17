#include <iostream>
#include <vector>
#include "Person.h"

void born_before(const std::vector<Person>& persons, const Date& date) {
  date.show();
  std::cout << ": ";
  for (const auto& person : persons) {
    if (person.get_birth_date().is_before(date)) {
      person.show();
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}


int main() {
  Date date(1990, 1, 1);
  std::vector<Person> persons;
  persons.push_back(Person("Alice", Date(1988, 3, 12)));
  persons.push_back(Person("Bob", Date(1992, 5, 23)));
  persons.push_back(Person("Charlie", Date(1985, 11, 2)));
  persons.push_back(Person("David", Date(1994, 9, 7)));
  persons.push_back(Person("Emma", Date(1983, 7, 29)));

  born_before(persons, date);

  return 0;
}

#ifndef STUDENT_H  // Evita inclusões múltiplas do arquivo header
#define STUDENT_H

#include "Person.h" // Include the base class header file

class Student : public Person { // Inherit from the Person class
public:
  // Constructor that takes id, name, and course
  Student(int id, const string& name, const string& course)
    : Person(id, name), course_(course) {}

  // Accessor function for the course information
  const string& course() const { return course_; }

  // Override the to_string() function to include course information
  string to_string() const override {
    return Person::to_string() + "/" + course_;
  }

private:
  string course_; // Course information
};

#endif // STUDENT_H

#include "Student.h" // Include the base class header file

class ErasmusStudent : public Student { // Inherit from the Student class
public:
  // Constructor that takes id, name, course, and country
  ErasmusStudent(int id, const string& name, const string& course, const string& country)
    : Student(id, name, course), country_(country) {}

  // Accessor function for the country information
  const string& country() const { return country_; }

  // Override the to_string() function to include country information
  string to_string() const override {
    return Student::to_string() + "/" + country_;
  }

private:
  string country_; // Country information
};

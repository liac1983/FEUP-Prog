#include "Student.h"

// Constructor
Student::Student(const std::string& name, const std::string& id, 
                 short ac, short p1, short p2)
    : name_(name), id_(id), ac_(ac), p1_(p1), p2_(p2) {}

// Accessor for ID
std::string Student::get_id() const {
    return id_;
}

// Accessor for name
std::string Student::get_name() const {
    return name_;
}

// Calculate the actual grade
double Student::actual_grade() const {
    return 0.1 * ac_ + 0.45 * p1_ + 0.45 * p2_;
}

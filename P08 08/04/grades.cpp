#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct course {
    std::string name;
    float credits;
    short grade;
};

class Student {
public:
    // Constructor
    Student(const std::string& id) : id_(id) {}

    // Accessor
    std::string get_id() const { return id_; }

    // Member functions
    void add(const course& c) {
        if (c.grade >= 10) { // Only add courses with passing grades
            courses_.push_back(c);
        }
    }

    double avg() const {
        if (courses_.empty()) return 0.0;
        
        double sum_grades_times_credits = 0.0;
        double sum_credits = 0.0;

        for (const auto& c : courses_) {
            sum_grades_times_credits += c.grade * c.credits;
            sum_credits += c.credits;
        }

        return sum_grades_times_credits / sum_credits;
    }

private:
    std::string id_;
    std::vector<course> courses_;
};

int main() {
    {
        Student s("up2022001111");
        s.add({"FP", 6, 20});
        std::cout << "[" << s.get_id() << "]/";
        std::cout << std::fixed << std::setprecision(2) << s.avg() << std::endl;
    }

    {
        Student s("up2022002222");
        s.add({"MD", 6, 18});
        s.add({"AMI", 6, 16});
        s.add({"FSC", 6, 14});
        std::cout << "[" << s.get_id() << "]/";
        std::cout << std::fixed << std::setprecision(2) << s.avg() << std::endl;
    }

    {
        Student s("up2022003333");
        s.add({"ALGA", 4.5, 18});
        s.add({"AMI", 6, 16});
        s.add({"PUP", 1.5, 14});
        std::cout << "[" << s.get_id() << "]/";
        std::cout << std::fixed << std::setprecision(2) << s.avg() << std::endl;
    }

    {
        Student s("up2022004444");
        std::cout << "[" << s.get_id() << "]/";
        std::cout << std::fixed << std::setprecision(2) << s.avg() << std::endl;
    }

    return 0;
}

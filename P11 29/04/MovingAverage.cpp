#include "MovingAverage.h"

MovingAverage::MovingAverage(std::size_t n) : n_(n) {}

void MovingAverage::update(double value) {
    values_.push_back(value);
    if (values_.size() > n_) {
        values_.pop_front();
    }
}

double MovingAverage::get() const {
    if (values_.empty()) {
        return 0.0; // or any default value
    }

    double sum = 0.0;
    for (double val : values_) {
        sum += val;
    }

    return sum / values_.size();
}

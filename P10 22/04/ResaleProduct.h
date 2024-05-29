#include "Product.h" // Include the base class header file

class ResaleProduct : public Product { // Inherit from the Product class
public:
  // Constructor that takes id, price, and profit margin
  ResaleProduct(int id, float price, int profit_margin) : Product(id, price), profit_margin_(profit_margin) {}

  // Function to get the profit margin
  int get_profit_margin() const { return profit_margin_; }

  // Function to set the profit margin
  void set_profit_margin(int margin) { profit_margin_ = margin; }

  // Redefinition of get_sell_price according to the requirements
  float get_sell_price() const override {
    // Calculate the final price including the profit margin
    return price_ * (100 + profit_margin_) / 100;
  }

private:
  int profit_margin_; // Profit margin of the company
};

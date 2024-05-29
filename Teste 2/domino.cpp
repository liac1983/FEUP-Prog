#include <iostream>
#include <iomanip>
#include "Piece.h"
#include "Domino.h"

using namespace std;

//! determine if this piece can be placed on the left of other
bool Piece::can_be_left_to(const Piece& other) const { 
  return right_ == other.left_;
}

//! determine if this piece can be placed on the right of other
bool Piece::can_be_right_to(const Piece& other) const {
  return other.right_ == left_;
}

//! get the piece on the left side of the domino line
const Piece& Domino::left() const { 
  return pieces_.front(); 
}

//! get the piece on the right side of the domino line
const Piece& Domino::right() const { 
  return pieces_.back(); 
}

//! place the piece on the left side of the domino line
bool Domino::place_left(const Piece& p) {
  if (pieces_.empty() || p.can_be_left_to(pieces_.front())) {
    pieces_.push_front(p);
    return true;
  }
  return false;
}

//! place the piece on the right side of the domino line
bool Domino::place_right(const Piece& p) {
  if (pieces_.empty() || p.can_be_right_to(pieces_.back())) {
    pieces_.push_back(p);
    return true;
  }
  return false;
}

int main() {
  // public tests (1 point each) 
  {
    Piece p (1, 2);
    cout << boolalpha 
        << p.can_be_left_to({2, 3}) << ' ' 
        << p.can_be_left_to({3, 2}) << ' ' 
        << p.can_be_right_to({3, 2}) << ' ' 
        << p.can_be_right_to({0, 1}) << '\n'; 
  } // -> true false false true
  {
    Domino d( { {1,2}, {2,0}, {0,6}, {6,6} } );
    cout << d.left().to_string() << ' '
         << d.right().to_string() << ' '
         << d.to_string() << '\n';
  }  // -> 1:2 6:6 [ 1:2 2:0 0:6 6:6 ]
  {
    Domino d( { {1,2}, {2,0}, {0,6}, {6,6} } );
    cout << boolalpha
         << d.place_left({6,1})  << ' '
         << d.place_right({3,6}) << ' '
         << d.to_string() << '\n';
  }  // -> true false [ 6:1 1:2 2:0 0:6 6:6 ]
  {
    Domino d( { {1,2}, {2,3}, {3,3}, {3,4} } );
    cout << boolalpha
         << d.place_left({4,3})  << ' '
         << d.place_right({4,1}) << ' '
         << d.to_string() << '\n';
  }  // -> false true [ 1:2 2:3 3:3 3:4 4:1 ]
  {
    Domino d( { {1,2}, {2,3}, {3,3}, {3,6} } );
    cout << boolalpha
         << d.place_left({1,1})  << ' '
         << d.place_right({6,6}) << ' '
         << d.to_string() << '\n';
  }  // -> true true [ 1:1 1:2 2:3 3:3 3:6 6:6 ]
  
  cout << endl;
  // private tests (1000 points each) 
  {
    Piece p (0, 6);
    cout << boolalpha 
        << p.can_be_left_to({6, 3}) << ' ' 
        << p.can_be_left_to({3, 6}) << ' ' 
        << p.can_be_right_to({1, 0}) << ' ' 
        << p.can_be_right_to({0, 1}) << '\n'; 
  } // -> true false true false
  {
    Domino d( { {1,2}, {2,0}, {0,6}, {6,6}, {6,1}, {1,5} } );
    cout << d.left().to_string() << ' '
         << d.right().to_string() << ' '
         << d.to_string() << '\n';
  }  // -> 1:2 1:5 [ 1:2 2:0 0:6 6:6 6:1 1:5 ] 
  {
    Domino d( { {1,2}, {2,0}, {0,6}, {6,6}, {6,1}, {1,5} } );
    cout << boolalpha
         << d.place_left({5,1})  << ' '
         << d.place_right({1,6}) << ' '
         << d.to_string() << '\n';
  }  // -> true false [ 5:1 1:2 2:0 0:6 6:6 6:1 1:5 ]
  {
    Domino d( { {1,2}, {2,3}, {3,3}, {3,4}, {4,4}, {4,5} } );
    cout << boolalpha
         << d.place_left({4,3})  << ' '
         << d.place_right({5,1}) << ' '
         << d.to_string() << '\n';
  }  // -> false true [ 1:2 2:3 3:3 3:4 4:4 4:5 5:1 ]
  {
    Domino d( { {1,2}, {2,3}, {3,3}, {3,6}, {6,1}, {1,5} } );
    cout << boolalpha
         << d.place_left({1,1})  << ' '
         << d.place_right({5,5}) << ' '
         << d.to_string() << '\n';
  }  // -> true true [ 1:1 1:2 2:3 3:3 3:6 6:1 1:5 5:5 ]

  return 0;
} 
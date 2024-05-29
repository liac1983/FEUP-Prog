#include "Hanoi.h"

int Tower::top() const 
{
  return disks_.empty() ? 0 : disks_.back();
}
void Tower::add(int disk)
{
  disks_.push_back(disk);
}

void Tower::remove()
{
  if (disks_.empty())
    return;
  disks_.pop_back();
}

string Tower::str() const
{
  ostringstream oss;
  oss << "[";
  for (auto d : disks_) oss << " " << d;
  oss << " ]";
  return oss.str();
}

void Hanoi::move(const vector<disk_move>& dmoves)
{
  for (auto dm : dmoves) {
    int dfrom = towers_[dm.from].top();
    int dto = towers_[dm.to].top();
    // cout << dm.from << ' ' << dm.to << ' ' << str() << endl;
    if (dfrom == 0 || (dto != 0 && dfrom > dto)) {
      continue;
    }
    towers_[dm.from].remove();
    towers_[dm.to].add(dfrom);
  }
}

int main() 
{
  // public tests (1 point each)
  {
    Tower t0, t1,  t2;
    t0.add(4); t0.add(3); t0.add(2); t0.add(1); t0.remove();
    t1.add(3); t1.add(2); t1.remove(); t1.remove();    
    t2.remove();
    cout << t0.top() << ' ' << t0.str() << ' '
         << t1.top() << ' ' << t1.str() << ' '
         << t2.top() << ' ' << t2.str() << endl;
  } // -> 2 [ 4 3 2 ] 0 [ ] 0 [ ]
  {
    Hanoi h(5);
    cout << h.str() << endl;
  } // -> [ 5 4 3 2 1 ][ ][ ]
  {
    Hanoi h(3);
    h.move({ {0, 2}, {0, 1}, {2, 1}, {0, 2} }); 
    cout << h.str() << endl;
  } // -> [ ][ 2 1 ][ 3 ]
  {
    // contains invalid moves
    Hanoi h(3);
    h.move({ {2, 0}, {0, 2}, {1, 1}, {0, 1}, {2, 1}, {2, 0} }); 
    cout << h.str() << endl;
  } // -> [ 3 ][ 2 1 ][ ]
  {
    // complete solution for 2 disks
    Hanoi h(2);
    h.move({ {0, 1}, {0, 2}, {1, 2} }); 
    cout << h.str() << endl;
  } // -> [ ][ ][ 2 1 ]
  {
    // complete solution for 3 disks
    Hanoi h(3);
    h.move({ {0, 2}, {0, 1}, {2, 1}, {0, 2}, {1, 0}, {1, 2}, {0, 2} });
    cout << h.str() << endl;
  } // -> [ ][ ][ 3 2 1 ]
  {
    Hanoi h(5);
    h.move({ {2,0}, {2,1}, {0, 2}, {0, 0}, {0, 1}, {2, 1}, {0, 2}, {1, 0}, {1, 2}, {0, 2}, {1, 2}, {2,1} });
    cout << h.str() << endl;
  } // -> [ 5 4 ][ 1 ][ 3 2 ]
  {
    Hanoi h(10);
    h.move({ {2,0}, {2,1}, {0, 2}, {0, 0}, {0, 1}, {2, 1}, {0, 2}, {1, 0}, {1, 2}, {0, 2}, {1,2}, {2, 0} });
    cout << h.str() << endl;
  } // -> [ 10 9 8 7 6 5 4 1 ][ ][ 3 2 ]

  cout << endl;
  // private tests (1000 points each)
  {
    Tower t;
    t.add(3); t.add(2); t.add(1); t.remove(); t.remove(); t.remove();
    t.add(2); t.add(1);
    cout << t.top() << ' ' << t.str() << endl;
  } // -> 1 [ 2 1 ]
  {
    Hanoi h(5);
    h.move({ {0, 2}, {0, 1}, {2, 1}, {0, 2} }); 
    cout << h.str() << endl;
  } // -> [ 5 4 ][ 2 1 ][ 3 ]
  {
    Hanoi h(2);
    h.move({ {2, 0}, {0, 2}, {1, 1}, {0, 1}, {2, 1}, {2, 0} }); 
    cout << h.str() << endl;
  } // -> [ ][ 2 1 ][ ]
  {
    // complete solution for 4 disks
    Hanoi h(4);
    h.move({ {0, 1}, {0, 2}, {1, 2}, 
             {0, 1}, {2, 0}, {2, 1}, 
             {0, 1}, {0, 2}, {1, 2}, 
             {1, 0}, {2, 0}, {1, 2}, 
             {0, 1}, {0, 2}, {1, 2} });
    cout << h.str() << endl;
  } // -> [ ][ ][ 4 3 2 1 ]
  {
    Hanoi h(3);
    h.move({ {0, 1}, {0, 2}, {2, 0}, {0, 2}, {1, 2} }); 
    cout << h.str() << endl;
  } // -> [ 3 ][ ][ 2 1 ]
  {
    Hanoi h(8);
    h.move({ {0, 2}, {2, 0}, {0, 1}, {1, 1}, {2, 1}, {1, 2}, {2, 2}, {0, 2}, {1, 0}, {1, 2}, {0, 2}, {2,1}, {0,2}, {1, 2}, {0,1}, {0,2}, {1, 2}, {0,1}, {0, 0}  });
    cout << h.str() << endl;
  } // -> [ 8 7 6 5 4 ][ 3 ][ 2 1 ]
  {
    Hanoi h(4);
    h.move({ {0, 1}, {1, 2}, {2, 0}, 
             {0, 2}, {1, 0}, {2, 1},
             {0, 0}, {1, 1}, {2, 2}, 
             {1, 0}, {2, 1}, {0, 2}, 
             {2, 0}, {0, 1}, {1, 2}
    });
    cout << h.str() << endl;
  } // -> [ 4 3 2 ][ ][ 1 ]
  {
    Hanoi h(5);
    h.move({ {2,0}, {2,1}, {0, 2}, {0, 0}, {0, 1}, {2, 1}, {0, 2}, {1, 0}, {1, 2}, {0, 2}, {1,2}, {2, 0}, {0,1}, {0,2}, {1, 2}, {0,1}, {0, 0} });
    cout << h.str() << endl;
  } // -> [ 5 ][ 4 ][ 3 2 1 ]
  return 0;
}
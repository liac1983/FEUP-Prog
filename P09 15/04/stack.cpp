#include <iostream>
using namespace std;

template <typename T>
struct node { 
  T value;
  node<T>* next; 
};

template <typename T>
class Stack { 
public:
  Stack(); 
  ~Stack();
  size_t size() const;
  bool peek(T& elem) const;
  bool pop(T& elem);
  void push(const T& elem);
private:
  int size_;
  node<T>* top_;
};

template <typename T>
Stack<T>::Stack() : size_(0), top_(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
while (top_) {
node<T>* temp = top_;
top_ = top_->next;
delete temp;
}
}

template <typename T>
size_t Stack<T>::size() const {
return size_;
}

template <typename T>
bool Stack<T>::peek(T& elem) const {
if (!top_) return false;
elem = top_->value;
return true;
}

template <typename T>
bool Stack<T>::pop(T& elem) {
if (!top_) return false;
node<T>* temp = top_;
top_ = top_->next;
elem = temp->value;
delete temp;
size_--;
return true;
}

template <typename T>
void Stack<T>::push(const T& elem) {
node<T>* temp = new node<T>{elem, top_};
top_ = temp;
size_++;
}

int main() {
    { Stack<int> s;
  const Stack<int>& r = s;
  int v = -1;
  cout << r.size()  << ' ' << boolalpha
       << r.peek(v) << ' ' << v << ' '
       << s.pop(v)  << ' ' << v << ' '
       << s.size() << '\n'; }
    { Stack<int> s;
  int v = -1;
  s.push(123);
  cout << s.size()  << ' ' << boolalpha
       << s.peek(v) << ' ' << v << ' '
       << s.pop(v)  << ' ' << v << ' '
       << s.size() << '\n'; }
    { Stack<string> s; string v;
  s.push("a"); s.push("b"); s.push("c");
  cout << s.size();
  while(s.pop(v)) cout << ' ' << v;
  cout << ' ' << s.size() << '\n'; }
    { Stack<int> s; int v = -1;
  s.push(111); s.push(222); s.push(333);
  cout << s.size();
  while(s.peek(v)) {
    cout << ' ' << v;
    s.pop(v);
    cout << ' ' << v;
    if (v % 2 != 0) s.push(v + 1);
    cout << ' ' << s.size(); }
  cout << '\n'; }
    return 0;
}
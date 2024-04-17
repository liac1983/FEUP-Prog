/*#include <iostream>
#include "Color.h"

using namespace std;

int main() {

    { Color c (1, 2, 3);
  const Color& r = c;
  cout << (int) r.red() << ' '  
       << (int) r.green() << ' '  
       << (int) r.blue() << ' '
       << boolalpha << r.equal_to(r) << '\n'; }
    
    { cout << boolalpha 
       << Color::WHITE.equal_to(Color::WHITE) << ' '
       << Color::BLACK.equal_to(Color::RED) << ' '
       << Color::BLUE.equal_to(Color::GREEN) << '\n'; }

    { Color c(Color::WHITE); 
  cout << (int) c.red() << ' ' 
       << (int) c.green() << ' '  
       << (int) c.blue() << ' '
       << boolalpha << c.equal_to(Color::WHITE) << ' '
       << c.equal_to(Color::BLACK) << '\n'; }

    { Color c(Color::WHITE); 
  c.invert();
  cout << (int) c.red() << ' '  
       << (int) c.green() << ' '  
       << (int) c.blue() << ' ' 
       << boolalpha << c.equal_to(Color::WHITE) << ' '
       << c.equal_to(Color::BLACK) << '\n'; }

    { Color c(255, 128, 12); 
  c.invert();
  Color c2(c);
  c2.invert();
  cout << (int) c.red() << ' ' 
       << (int) c.green() << ' '  
       << (int) c.blue() << ' ' 
       << boolalpha << c.equal_to({ 0, 127, 243 }) << ' '
       << (int) c2.red() << ' ' 
       << (int) c2.green() << ' '  
       << (int) c2.blue() << ' ' 
       << boolalpha << c2.equal_to({ 255, 128, 12 }) << '\n'; }

    return 0;
}

#include <iostream>
#include "Polygon.h"
#include "Point.h"
#include <iomanip>

using namespace std;

int main() {
    { Point p1, p2(0, 1); 
  p1.show(); p2.show(); cout << '\n'; }

    { Polygon poly1;
  Point p1, p2(0, 1), p3(1, 0);
  Polygon poly2(vector<Point>{ p1, p2, p3 });
  poly1.show(); cout << " "; poly2.show(); cout << '\n'; }

    { Point p1, p2(0, 1), p3(1, 0);
  Polygon poly1(vector<Point>{ p1, p2, p3 });
  cout << fixed << setprecision(3) << poly1.perimeter() << setprecision(0) << '\n'; }

    { Point p1, p2(0, 1), p3(1, 0);
  Polygon poly1(vector<Point>{ p1, p2, p3 });
  Point p;
  if (poly1.get_vertex(2, p)) { p.show(); cout << ' '; }
  else cout << "vertex not found! ";
  if (poly1.get_vertex(0, p)) { p.show(); cout << ' '; }
  else cout << "vertex not found! ";
  cout << '\n'; }

    { Point p1, p2(0, 1), p3(1, 0), p4(1, 1);
  Polygon poly1 = vector<Point>{ p1, p2, p3 };
  poly1.add_vertex(3, p4); 
  poly1.show(); 
  cout << ' ' << fixed << setprecision(3) << poly1.perimeter() << setprecision(0) << '\n'; }
  
    return 0;
}


#include <iostream>
#include "pair.cpp"
#include <vector>

using namespace std;

int main() {

    { vector<Pair<string, int>> persons = { {"Maria",17},{"Ana",21},{"Pedro",19} };
  sort_by_first(persons);
  show(persons); cout << '\n'; }

    { vector<Pair<string, int>> persons = { {"Ana",19},{"Rui",16} };
  sort_by_second(persons);
  show(persons); cout << '\n'; }

    { vector<Pair<string, int>> teams = { {"Porto",91},{"Benfica",74},{"Sporting",85} };
  sort_by_first(teams);
  show(teams); cout << '\n'; }

    { vector<Pair<string, int>> teams = { {"Porto",91},{"Benfica",74},{"Sporting",85} };
  sort_by_second(teams);
  show(teams); cout << '\n'; }

    { vector<Pair<string, int>> calories = { {"orange",37},{"egg",146},{"apple",56},{"yogurt",51} };
  sort_by_second(calories);
  show(calories); cout << '\n'; }
    return 0;

}*/

#include <iostream>
#include "Stack.h"

using namespace std;

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
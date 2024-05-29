#include "show_file.h"
#include <iomanip>
using namespace std;

void xyz_sum(const string &input_fname, const string &output_fname)
{
  ifstream f_in(input_fname);
  ofstream f_out(output_fname);
  double x, y, z;
  double sum_x = 0, sum_y = 0, sum_z = 0;
  f_out << fixed << setprecision(1);
  while (f_in >> x >> y >> z)
  {
    sum_x += x; sum_y += y; sum_z += z;
    f_out << "(" << x << "," << y << "," << z << ")" << endl;
  }
  f_out << "(" << sum_x << "," << sum_y << "," << sum_z << ")" << endl;
}

int main()
{
  cout << endl;
  // -> public testes (1 point each)
  {
    xyz_sum("xyz-1.txt", "xyz-1_out.txt");
    show_file("xyz-1.txt"); show_file("xyz-1_out.txt");
  } /* ->
==> xyz-1.txt <==
1.0 2.1 3.2
1.0 2.1 3.2
1.0 2.1 3.2
==> xyz-1_out.txt <==
(1.0,2.1,3.2)
(1.0,2.1,3.2)
(1.0,2.1,3.2)
(3.0,6.3,9.6)
  */
  cout << endl;
  {
    xyz_sum("xyz-2.txt", "xyz-2_out.txt");
    show_file("xyz-2.txt"); show_file("xyz-2_out.txt");
  } /* ->
==> xyz-2.txt <==
 1 0.04 0.16
 0 1.03 0
 0 0.24 1
==> xyz-2_out.txt <==
(1.0,0.0,0.2)
(0.0,1.0,0.0)
(0.0,0.2,1.0)
(1.0,1.3,1.2)
  */
  cout << endl;
  {
    xyz_sum("xyz-3.txt", "xyz-3_out.txt");
    show_file("xyz-3.txt"); show_file("xyz-3_out.txt");
  } /* ->
==> xyz-3.txt <==
-4.00 -3.01    -2.02
      -1.03   0.04 1.05
2.06   -3.07      4.08
==> xyz-3_out.txt <==
(-4.0,-3.0,-2.0)
(-1.0,0.0,1.1)
(2.1,-3.1,4.1)
(-3.0,-6.0,3.1)
  */
  cout << endl;
  {
    xyz_sum("xyz-4.txt", "xyz-4_out.txt");
    show_file("xyz-4.txt"); show_file("xyz-4_out.txt");
  } /* ->
==> xyz-4.txt <==
3.0 2.3 3.289
 3 0.04 0.366
 0 3.03 0
 0 0.247 3
-4.04 -3.03    -2.02
      -3.09999   0.04 3.05
          2.06   -3.07      4.09
==> xyz-4_out.txt <==
(3.0,2.3,3.3)
(3.0,0.0,0.4)
(0.0,3.0,0.0)
(0.0,0.2,3.0)
(-4.0,-3.0,-2.0)
(-3.1,0.0,3.0)
(2.1,-3.1,4.1)
(0.9,-0.4,11.8)
  */

  cout << endl << endl;
  // -> private testes (1000 points each)
  {
    xyz_sum("xyz-5.txt", "xyz-5_out.txt");
    show_file("xyz-5.txt"); show_file("xyz-5_out.txt");
  } /* ->
==> xyz-5_out.txt <==
(0.1,0.2,0.3)
(0.1,0.2,0.3)
(0.1,0.2,0.3)
(0.3,0.6,0.9)
  */
  cout << endl ;
  {
    xyz_sum("xyz-6.txt", "xyz-6_out.txt");
    show_file("xyz-6.txt"); show_file("xyz-6_out.txt");
  } /* ->
==> xyz-6_out.txt <==
(9.8,7.4,6.5)
(-1.2,-1.3,0.0)
(-2.1,-5.4,-3.7)
(8.7,6.4,3.4)
(-1.2,-4.3,-0.9)
(14.0,2.8,5.3)
  */
  cout << endl ;
  {
    xyz_sum("xyz-7.txt", "xyz-7_out.txt");
    show_file("xyz-7.txt"); show_file("xyz-7_out.txt");
  } /* ->
==> xyz-7_out.txt <==
(0.0,0.0,0.0)
(0.0,-0.0,-0.0)
(-0.0,0.0,1.0)
(0.1,-0.2,-2.0)
(0.1,-0.2,-1.0)
  */
  cout << endl ;
  {
    xyz_sum("xyz-8.txt", "xyz-8_out.txt");
    show_file("xyz-8.txt"); show_file("xyz-8_out.txt");
  } /* ->
==> xyz-8_out.txt <==
(134321345.0,341234245.0,23432445.0)
(324324343.0,234324334.0,43454545.0)
(945654435.0,345435434.0,65785677.0)
(1404300123.0,920994013.0,132672667.0)
  */
  return 0;
}
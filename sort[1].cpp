#include <algorithm>

using namespace std;


//  Sort an array of n integers.
//
void sort (int a[], int n)
{
  int i = 1;
  while (i < n)
  {
    if (i > 0 && a[i] < a[i-1])
    { // a[i] is inverted
      swap(a[i], a[i-1]);
      --i;
    }
    else
    { // a[i] is not inverted
      ++i;
    }
  }
}

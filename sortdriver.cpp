#include <cstdlib>
#include <cmath>
#include <iostream>
#include <time.h>

using namespace std;

unsigned rnd(unsigned limit)
{
  return rand() % limit;
}


void sort (int[], int);
void generate (int[], int);


int main(int argc, char** argv)
{
  if (argc != 3)
    {
      cerr << "When you run this program, you must supply two parameters.\n" 
           << "The first is the size of the array you want to sort.\n"
           << "The second is the number of trials you want to perform.\n"
           << "\n"
           << "For example, if you called this program sortdriver, you\n"
           << "might invoke it as:\n"
           << "   sortdriver 100 10 \n"
           << "to generate and sort 10 random arrays of 100 elements each."
	     << endl;
      return 1;
    }

  int N = atoi(argv[1]);
  int trials = atoi(argv[2]);

  int *array = new int[N];

  srand(time(0));

  for (int t = 0; t < trials; t++)
    {
      generate (array, N);
      //for (int i = 0; i < N; ++i) cout << array[i] << ' '; cout << endl;
      sort (array, N);
      //for (int i = 0; i < N; ++i) cout << array[i] << ' '; cout << endl;
    }

  return 0;
}


void generate(int array[], int N)
{
  for (int i = 0; i < N; ++i)
  {
    array[i] = 64*(i+1);
  }

  // Inject out-of-order elements.
  int avgInverted = max(1, (int)sqrt(N));
  int nInverted = avgInverted/2 + rnd(avgInverted);
  for (int k = 0; k < nInverted; ++k)
  {
    int pos = rnd(N);
    int value = rnd(64*N);
    array[pos] = value;
  }
}

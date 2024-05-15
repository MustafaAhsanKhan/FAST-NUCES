#include <iostream>

using namespace std;

int main() 
{
  int lamps, rounds, round, switched_on;

  cout << "Enter the number of lamps: ";
  cin >> lamps;
  rounds = lamps;

  bool lampState = 1;
  switched_on = lamps;


  for(round = 1; round <= rounds; ++round) 
  {
    for(int i = 1; i <= lamps; ++i) 
    {
      if(i % round == 0) 
      {
        lampState = !lampState;
      }

      if(lampState == 1) 
      {
        switched_on = switched_on + 1;
      } 
      else 
      {
        switched_on = switched_on - 1;
      }
    }

  }
    cout << "Number of lamps switched on at the end are: "<< switched_on;

  return 0;
}
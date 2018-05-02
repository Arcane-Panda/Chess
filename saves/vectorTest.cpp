#include <vector>
#include <iostream>
using namespace std;


int main()
{
  vector<int> ThisIsATestVector;
  ThisIsATestVector.push_back(1);
  ThisIsATestVector.push_back(2);
  ThisIsATestVector.push_back(3);
  ThisIsATestVector.push_back(4);
  ThisIsATestVector.push_back(6);
  ThisIsATestVector.push_back(1283);


  for (int i = 0; i < ThisIsATestVector.size(); i++)
  {
    cout << ThisIsATestVector[i] << endl;
  }
}

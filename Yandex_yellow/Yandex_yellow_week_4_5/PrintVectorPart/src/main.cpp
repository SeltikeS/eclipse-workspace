/*
 * main.cpp
 *
 *  Created on: 27 дек. 2021 г.
 *      Author: SeltikeS
 */
#include "PrintVectorPart.h"



using namespace std;

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}


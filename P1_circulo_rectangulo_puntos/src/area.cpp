#include <iostream>
#include "circulo.h"

using namespace std;

int main(){

	Circulo c;
	
	c = LeerCirculo();
	cout << Area(c) << endl;
}

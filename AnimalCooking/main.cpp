#include <iostream>

#include "AnimalCooking.h"

using namespace std;

void start() {
	AnimalCooking g;
	g.start();
}

int main(int ac, char **av) {

	try {
		start();
	} catch (std::string &e) { // catch errors thrown as strings
		cerr << e << endl;
	} catch (const std::exception &e) { // catch other exceptions
		cerr << e.what();
	} catch (...) {
		cerr << "Caught and exception of unknown type ..";
	}

	return 0;
}

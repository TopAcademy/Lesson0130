
#include <iostream>
#include "Time.h"
using std::cout;
using namespace top;

int main()
{
	Time t(23, 59, 21);
	for (int i = 0; i < 5; i++) {
		t.add_time(12, 0, 0);
		t.show();
	}
}


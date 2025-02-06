
#include <iostream>
#include "Time.h"
using std::cout;
using namespace top;

int main()
{
	Time t1(01, 10, 21);
	Time t2(3, 00, 00);
	t2 = t1++;
	t1.show();
	t2.show();


	

	/*
	for (int i = 0; i < 5; i++) {
		t.add_time(12, 0, 0);
		t.show();
	}
	*/
}


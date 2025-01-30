#pragma once
#include <iostream>
using std::cout;

namespace top
{
	// Type aliases

	typedef unsigned short UShort;
	typedef unsigned int UInt;


	// Time class

	class Time
	{
	protected:
		// Class data
		UShort hour, min, sec;

	public:

		// Default constructor
		Time()
		{
			hour = 0;
			min = 0;
			sec = 0;
		}

		
		// Constructor with args
		// Setting time value given by arguments
		Time(UShort h, UShort m, UShort s) : Time()
		{
			set_time(h, m, s);
		}

		
		// Setting time value given by arguments
		bool set_time(UShort h, UShort m, UShort s)
		{
			// Check for invalid values
			if (h > 23 || m > 59 || s > 59) return false;
			hour = h;
			min = m;
			sec = s;
			return true;
		}

		
		// Display time value on console
		void show_time()
		{
			cout << hour << ':'
				 << ((min < 10) ? "0" : "") << min << ':'
				 << ((sec < 10) ? "0" : "") << sec << '\n';
		}

	}; // end of class `Time`


} // end of namespace `top`

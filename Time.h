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

	protected:
		// Inner class functionality

		// Convert time from  h,m,s  to seconds
		UInt convert_to_seconds()
		{
			UInt s = hour * 3600 + min * 60 + sec;
			return s;
		}

		// Set object time value given by seconds
		void set_time_from_seconds(UInt s)
		{
			// Check for exceed 
			const UInt max_time_seconds = 23 * 3600 + 59 * 60 + 59;
			if (s > max_time_seconds) {
				s = s % (max_time_seconds + 1);
			}
			// convert to h,m,s
			hour = s / 3600;
			s -= hour * 3600;
			min = s / 60;
			s -= min * 60;
			sec = s;
		}

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
		void show()
		{
			cout << hour << ':'
				 << ((min < 10) ? "0" : "") << min << ':'
				 << ((sec < 10) ? "0" : "") << sec << '\n';
		}

		
		// Increment the time by 1 second
		void inc()
		{
			sec++;
			if (sec == 60) {
				min++; 
				sec = 0;
			}
			if (min == 60) {
				hour++;
				min = 0;
			}
			if (hour == 24) {
				hour = 0;
			}
		}

		// Add given amount of seconds to the time
		void add_seconds(UInt s)
		{
			UInt conv_time = this->convert_to_seconds();
			conv_time += s;
			this->set_time_from_seconds(conv_time);
		}

		
		// Add given time in  h,m,s  to object's time
		bool add_time(UShort h, UShort m, UShort s)
		{
			// Check for invalid values
			if (h > 23 || m > 59 || s > 59) return false;
			UInt conv_time = Time(h, m, s).convert_to_seconds();
			this->add_seconds(conv_time);
			return true;
		}


	}; // end of class `Time`


} // end of namespace `top`

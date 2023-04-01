#include "ClassesForDates.h"

std::ostream& operator<<(std::ostream& out, Date& d)
{
	out << d.day << "." << d.month << "." << d.year;
	return out;
}

std::ostream& operator<<(std::ostream& out, Event& smth)
{
	return smth.print(out);
}

Date max(Date& a, Date& b)
{
	if (a.getYear() > b.getYear())
	{
		return a;
	}
	else if (a.getYear() < b.getYear())
	{
		return b;
	}
	else
	{
		if (a.getMonth() > b.getMonth())
		{
			return a;
		}
		else if (a.getMonth() < b.getMonth())
		{
			return b;
		}
		else
		{
			if (a.getDay() > b.getDay())
			{
				return a;
			}
			else if (a.getDay() < b.getDay())
			{
				return b;
			}
			else
			{
				return a;
			}
		}
	}
}

Date min(Date a, Date b)
{
	if (a.getYear() > b.getYear())
	{
		return b;
	}
	else if (a.getYear() < b.getYear())
	{
		return a;
	}
	else
	{
		if (a.getMonth() > b.getMonth())
		{
			return b;
		}
		else if (a.getMonth() < b.getMonth())
		{
			return a;
		}
		else
		{
			if (a.getDay() > b.getDay())
			{
				return b;
			}
			else if (a.getDay() < b.getDay())
			{
				return a;
			}
			else
			{
				return a;
			}
		}
	}
}

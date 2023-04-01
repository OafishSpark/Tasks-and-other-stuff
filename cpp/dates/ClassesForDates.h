#pragma once
#include <iostream>
#include <string>
#include <vector>

class Date
{
	unsigned short day;
	unsigned short month;
	unsigned int year;
public:
	Date(unsigned short d, unsigned short m, unsigned int y) : day{ d }, month{ m }, year{ y } {}
	friend std::ostream& operator<<(std::ostream& out, Date& d);
	unsigned short getDay()
	{
		return day;
	}
	unsigned short getMonth()
	{
		return day;
	}
	unsigned short getYear()
	{
		return day;
	}
};

class Event
{
public:
	friend std::ostream& operator<<(std::ostream& out, Event& smth);
	virtual std::ostream& print(std::ostream& out) = 0;
};

class Birthday : public Event
{
	Date date;
	std::string birthdayBoy;
public:
	Birthday(std::string bb, unsigned short d, unsigned short m, unsigned int y) : birthdayBoy{ bb }, date(d, m, y) {}
	virtual std::ostream& print(std::ostream& out)
	{
		out << date << " is " << birthdayBoy << "`s birthday!";
		return out;
	}
};

class Festival : public Event
{
	std::string name;
	Date begining;
	Date ending;
public:
	Festival(std::string n, unsigned short db, unsigned short mb, unsigned int yb, unsigned short de, unsigned short me, unsigned int ye) : name{ n }, begining(db, mb, yb), ending(de, me, ye) {}
	virtual std::ostream& print(std::ostream& out)
	{
		out << name << " begins on " << begining << " and ends on " << ending;
		return out;
	}
};

class ListOfEvents
{
	std::vector<Event*> list;
	std::string name;
public:
	ListOfEvents(std::string n, std::vector<Event*> l) : list{ l }, name{ n } {};
	void printEmAll()
	{
		std::cout << "\n" << name << " is:\n";
		unsigned int num{ 1 };
		for (auto obj : list)
		{
			std::cout << num++ << "# " << *obj << std::endl;
		}
		std::cout << std::endl;
	}
	void addEvent(Event* e)
	{
		list.push_back(e);
	}
};
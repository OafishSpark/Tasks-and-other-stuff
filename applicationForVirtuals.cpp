// applicationForVirtuals.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

//std::ostream& operator<<(std::ostream& out, const Event& event);
using strings = std::vector<std::string>; 

class Date
{
    int day;
    int month;
    int year;
public:
    Date() : day{ 0 }, month{ 0 }, year{ 0 } {}
    Date(int d, int m, int y) : day{ d }, month{ m }, year{ y } {}
    int getMonth() const
    {
        return month;
    } 
    int getDay() const
    {
        return day;
    }
    int getYear() const
    {
        return year;
    }
};

class Event
{
protected:
    Date date;
public:
    friend std::ostream& operator<<(std::ostream& out, const Event& event);
    virtual std::ostream& print(std::ostream& out) const = 0;
    //virtual void change() = 0;
};

std::ostream& operator<<(std::ostream& out, const Event& event)
{
    return event.print(out);
}

class Birthday : public Event
{
    std::string nameOfBirthdayBoy;
    int age;
public:
    Birthday(std::string nobb, int a, int d, int m, int y) : nameOfBirthdayBoy{ nobb }, age{ a }
    {
        date = Date(d, m, y);
    }
    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "\n Name of birthday boy: " << nameOfBirthdayBoy << "\n Age: " << age << " \n Date: ";
        out << date.getDay() << "." << date.getMonth() << "." << date.getYear() << "\n";
        return out;
    }
};

class Meeting : public Event
{
    strings participants;
    std::string reason;
public:
    Meeting(strings p, std::string r, int d, int m, int y) : participants{ p }, reason{ r }
    { 
        date = Date(d, m, y);
    }
    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "\n Names of participants:\n";
        for (auto name : participants)
        {
            out << name << "  ";
        }
        out << "\n Reason: " << reason;
        out << "\n Date: " << date.getDay() << "." << date.getMonth() << "." << date.getYear() << "\n";
        return out;
    }
};

int main()
{
    Birthday Leha("Leha", 19, 19, 11, 2021);
    strings chuvaki{ "Leha", "Max" };
    Meeting Dotka(chuvaki, "Dota 2", 8, 20, 2021);
    std::vector<Event*> events;
    events.push_back(&Leha);
    events.push_back(&Dotka);
    for (auto event : events)
    {
        std::cout << *event;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

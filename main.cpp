#include <iostream>
#include <string>
#include <map>
#include <list>

#include "Crime.h"

using std::cin;
using std::cout;
using std::endl;


void print(const std::map<std::string, std::list<Crime>>& base);

int main()
{
    std::map<std::string, std::list<Crime>> base =
            {
                    {"a777km", {Crime(1, "улица Ленина"), Crime(2, "улица Фрунзе")}},
                    {"a557ab", {Crime(5, "улица Космонавтов")}},
                    {"a001km", {Crime(4, "перекресток Ленина и Октябрьской"), Crime(3, "ул. Октябрьская")}},
            };
    print(base);


    std::string licence_plate;
    int id;
    std::string place;
    cout << "Введите номер автомобиля: "; cin >> licence_plate;
    cout << "Введите правонарушение: "; cin >> id;
    cin.clear();
    cin.ignore();
    cout << "Введите место происшествия: "; std::getline(cin, place);

    //base[licence_plate].push_back(Crime(id, place));
    std::map<std::string, std::list<Crime>>::iterator it = base.find(licence_plate);
    if(it != base.end())
    {
        it -> second.push_back(Crime(id, place));
    }
    else
    {
        base.insert(std::pair<std::string, std::list<Crime>>(licence_plate,{ Crime(id, place)}));
    }
    print(base);

    return 0;
}

void print(const std::map<std::string, std::list<Crime>>& base) {
    for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it) {
        //cout << std::left;
        cout << it->first + ":\n";
        for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt) {
            cout << " \t" << *jt << "; \n";
        }
        cout << "\n--------------------------------------\n";
    }

}

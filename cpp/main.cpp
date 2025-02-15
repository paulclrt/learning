#include <iostream>
#include <stdio.h>
#include <string>
#include <limits.h>
#include <vector>
using namespace std;



double myFunction(string name = "Firstname Lastname");



typedef struct Person {
    string fullname;
    int age;
} Person;



enum LEVEL {
    LOW,
    MEDIUM,
    HIGH,
};

int main() {
    int var = 20;
    string name = "Default";
    cout << "Oh sorry, i meant your full name: " << endl;
    getline(cin, name);
    cout << "How old are you ?: " << endl;
    cin >> var ;

    Person p;
    p.fullname = name;
    p.age = var;


    cout << p.fullname << " is " << p.age << " years old" << endl;
    if (var < 18) {
        cout << "Wait, You are not an adult ?" << endl << "Get out of here ! haha" << endl;
    } else if (var == 18) {
        cout << "Oufff, just old enough. Ok go on... " << endl;

    } else {
        cout << "Ok you are fine Mr. " << name << endl;
    }


    int i = 0;
    while ( i < var) {
        cout << "Hey, " << i << " for " << name << endl;
        i++;
    }

    i = 0;
    do {
        cout << "test " << i << endl;
        i++;
    } while (i < 5);


    for (int i = 0; i < 10; i++) {
        if (i == 2) { continue; }
        cout << "heeyeyeyyeyye " << i << endl;
        if (i == 3) {
            cout << "HEY STOP !" << endl;
            break;
        }
    }
    


    // foreach loop
    string names[] = {"paul", "jean", "luc"};
    for (string n : names) {
        cout << "here is a name for you: " << n << endl;
    }



    int num = 0;
    vector<string> cars;
    string buffer;
    cout << "How many cars do you want to put ?" << endl;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout << "cars n°" << i << ":";
        cin >> buffer;
        cars.push_back(buffer);
    }


    for (string car : cars) {cout << car << endl;}

    enum LEVEL level = HIGH;
    cout << "LEVEL IS " << level << endl;



    myFunction();
    myFunction("paul claret");

    return 0;
}


double myFunction(string name) {
    cout << "My Function execution" << endl;
    cout << name << endl; 
    return 12.0;
}

// #include <iostream>
// #include <stdio.h>

// using namespace std;

// void function(int arr[][10][5])
// {
//     cout << "Hello" << endl;
// }

// int main()
// {
//     int a = 10;
//     const int *p1 = &a;

//     int *const p2 = &a;

//     cout << "Value of pointer 1: " << *p1 << endl
//          << "Value of pointer 2: " << *p2 << endl;

//     *p2 = 20;
//     cout << "Value of pointer 1: " << *p1 << endl
//          << "Value of pointer 2: " << *p2 << endl;
//     return 0;
// }

#include <iostream>
#include <cstring>

class Person
{
public:
    Person(char *name, int age) : name(name), age(age) {}
    char *name;
    int age;
};

int main()
{
    char name[] = "John";
    Person john(name, 25);

    // Shallow copy
    // Person shallowCopy = john;
    // std::cout << "Original: " << john.name << ", " << john.age << std::endl;
    // std::cout << "Shallow copy: " << shallowCopy.name << ", " << shallowCopy.age << std::endl;

    // // Change the name of the shallow copy
    // shallowCopy.age = 'M';
    // std::cout << "Original after changing shallow copy: " << john.name << ", " << john.age << std::endl;
    // std::cout << "Shallow copy after changing shallow copy: " << shallowCopy.name << ", " << shallowCopy.age << std::endl;

    // // Deep copy
    // Person deepCopy(name, 25);
    // deepCopy.name = new char[strlen(john.name) + 1];
    // std::strcpy(deepCopy.name, john.name);
    // std::cout << "Original: " << john.name << ", " << john.age << std::endl;
    // std::cout << "Deep copy: " << deepCopy.name << ", " << deepCopy.age << std::endl;

    // // Change the name of the deep copy
    // deepCopy.name[0] = 'M';
    // std::cout << "Original after changing deep copy: " << john.name << ", " << john.age << std::endl;
    // std::cout << "Deep copy after changing deep copy: " << deepCopy.name << ", " << deepCopy.age << std::endl;

    // // Cleanup
    // delete[] deepCopy.name;
}

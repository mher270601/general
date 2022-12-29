#include <iostream>

#include "builder.hpp"

int main()
{
    IDeveloper* androidDev = new AndroidDeveloper();
    Director director(androidDev);

    Phone* samsung = director.MountFullPhone();
    cout << samsung->aboutPhone() << endl;

    IDeveloper* iphoneDev = new IPhoneDeveloper();
    director.setDeveloper(iphoneDev);

    Phone* iphone = director.MountOnlyPhone();
    cout << iphone->aboutPhone() << endl;

    return 0;
}

#include <DDateTime.hpp>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cout << DDateTime::currentDate().toSecond() << endl;

    cout << DDateTime::currentDate().toMS() << endl;

    cout << DDateTime::currentDate().toString("yyyy-MM-dd hh:mm:ss.ms") << endl;

    return 0;
}

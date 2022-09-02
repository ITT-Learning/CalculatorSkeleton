#include <iostream>
#include <string>

#include "CalcHistory.h"
#include "CalcHistoryTraverser.h"

using namespace std;

int main(int argc, char* argv[])
{
    CalcHistory history;
    CalcHistoryTraverser cht(&history);
    cout << "init: " << cht.current() << endl;
    cout << "previous: " << cht.previous() << endl;
    cout << "previous: " << cht.previous() << endl;
    cout << "previous: " << cht.previous() << endl;
    cout << "previous: " << cht.previous() << endl;
    cout << "previous: " << cht.previous() << endl;
    cout << "previous: " << cht.previous() << endl;
    cout << "next: " << cht.next() << endl;
    cout << "next: " << cht.next() << endl;
    cout << "next: " << cht.next() << endl;
    cout << "next: " << cht.next() << endl;
    cout << "previous: " << cht.previous() << endl;
    cout << "previous: " << cht.previous() << endl;
    cout << "previous: " << cht.previous() << endl;
    cout << "previous: " << cht.previous() << endl;
    cout << "current: " << cht.current() << endl;
    return 0;
};
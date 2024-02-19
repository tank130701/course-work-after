#include <iostream>
#include <Windows.h>
#include "List.h"
#include "ConsoleUi.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    List *myList = new List();
    Service* service = new Service(myList, 15);
    ConsoleUi ui = ConsoleUi(myList, service);
    ui.run();

    return 0;
}
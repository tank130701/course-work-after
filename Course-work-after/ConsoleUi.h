#pragma once
#include "List.h"
#include "Service.h"
#include <iostream>

class ConsoleUi
{
public:
    void run()
    {
        while (true) {
            int commandID = menu();
            bool exit = false;
            switch (commandID) {
            case 0:
                exit = true;
                break;
            case 1:
                addPoint();
                break;
            case 2:
                printList();
                break;
            case 3:
                insertPoint();
                break;
            case 4:
                addPoint();
                break;
            case 5:
                deletePoint();
                break;
            case 6:
                clear();
                break;
            case 7:
                calculateDistance();
                break;
            }
        }
    }
    ConsoleUi(Container *container, Service* service)
    {
        this->container = container;
        this->service = service;
    }
	~ConsoleUi()
	{

	}
private:
	Container *container;
    Service* service;
    int menu()
    {
        clearConsole();
        std::cout << "\n1. Создание списка\n"
            "2. Вывод списка на экран\n"
            "3. Вставка элемента\n"
            "4. Добавление в список\n"
            "5. Удаление точки\n"
            "6. Удаление списка\n"
            "7. Расчитать стоимость поездки\n"
            "0. Выход из программы " << std::endl;
        int cmd;
        std::cout << "~$ ";
        std::cin >> cmd;
        return cmd;
    }
    Point createPoint() {
        int x, y;
        std::string name;
        std::cout << "Введите x: ";
        while (!(std::cin >> x) || std::cin.get() != '\n') {
            std::cout << "Ошибка! Введите число для x: ";
            std::cin.clear();
            std::cin.ignore();
        }
        //std::cin.ignore(); // Add this line to clear the input buffer
        std::cout << "Введите y: ";
        while (!(std::cin >> y) || std::cin.get() != '\n') {
            std::cout << "Ошибка! Введите число для y: ";
            std::cin.clear();
            std::cin.ignore();
        }
        //std::cin.ignore(); // Add this line to clear the input buffer
        std::cout << "Введите название: ";
        std::cin >> name;

        return Point(x, y, name);
    }
    void addPoint() {
        Point newPoint = createPoint();
        container->add(newPoint);
        std::cout << "Точка успешно добавлена" << std::endl;
        waitToContinue();
    }
    void printList() {
        if (container->isEmpty()) {
            std::cout << "Список пуст" << std::endl;
            waitToContinue();
            return;
        }
            
        std::cout << container->getList() << std::endl;
        waitToContinue();
    }
    void insertPoint() {
        if (container->isEmpty()) {
            std::cout << "Список не должен быть пустым" << std::endl;
            return;
        }
            
        std::string current_name;
        std::cout << "Введите название точки после которой необходимо осуществить вствку" << std::endl;
        std::cin >> current_name;
        Point newPoint = createPoint();
        container->insertAfter(current_name, newPoint);
        std::cout << "Точка успешно добавлена" << std::endl;
        waitToContinue();
    }
    void deletePoint() {
        if (container->isEmpty()) {
            std::cout << "Список не должен быть пустым" << std::endl;
            return;
        }

        std::string name;
        std::cout << "Введите название точки после которой необходимо осуществить вствку" << std::endl;
        std::cin >> name;
        container->remove(name);
        std::cout << "Точка успешно удалена" << std::endl;
        waitToContinue();
    }
    void clear() {
        container->clear();
    }
    void calculateDistance() {
        std::cout << service->calculateDistanceAndCost();
        waitToContinue();
    }
    void clearConsole() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
    void waitToContinue() {
#ifdef _WIN32
        system("pause");
#else
        system("read -n 1 -s -p \"Press any key to continue...\"");
#endif
    }
};


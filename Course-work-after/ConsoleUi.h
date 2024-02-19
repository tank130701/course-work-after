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
        std::cout << "\n1. �������� ������\n"
            "2. ����� ������ �� �����\n"
            "3. ������� ��������\n"
            "4. ���������� � ������\n"
            "5. �������� �����\n"
            "6. �������� ������\n"
            "7. ��������� ��������� �������\n"
            "0. ����� �� ��������� " << std::endl;
        int cmd;
        std::cout << "~$ ";
        std::cin >> cmd;
        return cmd;
    }
    Point createPoint() {
        int x, y;
        std::string name;
        std::cout << "������� x: ";
        while (!(std::cin >> x) || std::cin.get() != '\n') {
            std::cout << "������! ������� ����� ��� x: ";
            std::cin.clear();
            std::cin.ignore();
        }
        //std::cin.ignore(); // Add this line to clear the input buffer
        std::cout << "������� y: ";
        while (!(std::cin >> y) || std::cin.get() != '\n') {
            std::cout << "������! ������� ����� ��� y: ";
            std::cin.clear();
            std::cin.ignore();
        }
        //std::cin.ignore(); // Add this line to clear the input buffer
        std::cout << "������� ��������: ";
        std::cin >> name;

        return Point(x, y, name);
    }
    void addPoint() {
        Point newPoint = createPoint();
        container->add(newPoint);
        std::cout << "����� ������� ���������" << std::endl;
        waitToContinue();
    }
    void printList() {
        if (container->isEmpty()) {
            std::cout << "������ ����" << std::endl;
            waitToContinue();
            return;
        }
            
        std::cout << container->getList() << std::endl;
        waitToContinue();
    }
    void insertPoint() {
        if (container->isEmpty()) {
            std::cout << "������ �� ������ ���� ������" << std::endl;
            return;
        }
            
        std::string current_name;
        std::cout << "������� �������� ����� ����� ������� ���������� ����������� ������" << std::endl;
        std::cin >> current_name;
        Point newPoint = createPoint();
        container->insertAfter(current_name, newPoint);
        std::cout << "����� ������� ���������" << std::endl;
        waitToContinue();
    }
    void deletePoint() {
        if (container->isEmpty()) {
            std::cout << "������ �� ������ ���� ������" << std::endl;
            return;
        }

        std::string name;
        std::cout << "������� �������� ����� ����� ������� ���������� ����������� ������" << std::endl;
        std::cin >> name;
        container->remove(name);
        std::cout << "����� ������� �������" << std::endl;
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


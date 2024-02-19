#pragma once
#include "Container.h"
#include "Point.h"
#include <string>

// Определение класса List
class List : public Container {
private:
    // Определение класса Node
    class Node {
    public:
        Point data;
        Node* next;

        Node(Point value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    List() : head(nullptr) {}
    ~List(){
        // Освобождаем память, выделенную для каждого узла списка
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        // Устанавливаем указатель на голову списка в nullptr
        head = nullptr;
    }
    bool isEmpty() override {
        return head == nullptr;
    }
    // Метод для добавления элемента в конец списка
    void add(Point value) override
    {
        Node* newNode = new Node(value);
        newNode->next = nullptr; // Set the next pointer of the new node to nullptr

        if (head == nullptr)
        {
            // If the list is empty, make the new node the head
            head = newNode;
        }
        else
        {
            // Otherwise, find the last node and append the new node to it
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    } 
    // Метод для вставки элемента после точки с заданным именем
    void insertAfter(std::string targetName, Point newValue) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.getName() == targetName) {
                Node* newNode = new Node(newValue);
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
            current = current->next;
        }
    }
    // Метод для вывода содержимого списка
    std::string getList() override
    {
        Node* current = head;
        std::string result;
        while (current != nullptr) {
            result += "Название: " + current->data.getName() + "\n" + "Координаты X и Y: (" +
                std::to_string(current->data.getX()) + ";" + std::to_string(current->data.getY()) + ")" + "\n";
            current = current->next;
        }
        return result;
    } 
    // Метод для удаления элемента по значению
    void remove(std::string value) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data.getName() != value) {
            prev = current;
            current = current->next; 
        }

        if (current != nullptr) {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            else {
                head = current->next;
            }
            delete current;
        }
    } 
    // Метод для поиска элемента по значению
    bool search(std::string value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.getName() == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void clear() override {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }
    Point getItem(int index) override {
        if (index < 0) {
            // Обработка случая, когда индекс отрицательный
            // Можно выбросить исключение, вернуть какое-то значение по умолчанию или выполнить другие действия в зависимости от требований
            // Здесь мы просто вернем пустую точку
            return Point();
        }

        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < index) {
            current = current->next;
            currentIndex++;
        }

        if (current != nullptr && currentIndex == index) {
            return current->data;
        }
        else {
            // Обработка случая, когда индекс выходит за пределы списка
            // Аналогично предыдущему случаю, можно выбросить исключение, вернуть какое-то значение по умолчанию или выполнить другие действия
            // Здесь мы просто вернем пустую точку
            return Point();
        }
    }
    int size() override{
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};


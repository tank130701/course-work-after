#pragma once
#include "Container.h"
#include "Point.h"
#include <string>

// ����������� ������ List
class List : public Container {
private:
    // ����������� ������ Node
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
        // ����������� ������, ���������� ��� ������� ���� ������
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        // ������������� ��������� �� ������ ������ � nullptr
        head = nullptr;
    }
    bool isEmpty() override {
        return head == nullptr;
    }
    // ����� ��� ���������� �������� � ����� ������
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
    // ����� ��� ������� �������� ����� ����� � �������� ������
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
    // ����� ��� ������ ����������� ������
    std::string getList() override
    {
        Node* current = head;
        std::string result;
        while (current != nullptr) {
            result += "��������: " + current->data.getName() + "\n" + "���������� X � Y: (" +
                std::to_string(current->data.getX()) + ";" + std::to_string(current->data.getY()) + ")" + "\n";
            current = current->next;
        }
        return result;
    } 
    // ����� ��� �������� �������� �� ��������
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
    // ����� ��� ������ �������� �� ��������
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
            // ��������� ������, ����� ������ �������������
            // ����� ��������� ����������, ������� �����-�� �������� �� ��������� ��� ��������� ������ �������� � ����������� �� ����������
            // ����� �� ������ ������ ������ �����
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
            // ��������� ������, ����� ������ ������� �� ������� ������
            // ���������� ����������� ������, ����� ��������� ����������, ������� �����-�� �������� �� ��������� ��� ��������� ������ ��������
            // ����� �� ������ ������ ������ �����
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


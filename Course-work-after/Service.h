#pragma once
#include "List.h"

class Service
{
private:
    Container* container;
    int tax;
public:
    Service(Container* container, int tax) {
        this->container = container;
        this->tax = tax;
    }
    ~Service() {}
    std::string calculateDistanceAndCost() {
        double distance = 0;

        if (container->size() == 1 || container->size() == 0) {
            return "В вашем маршруте должно быть больше одной точки\n";
        }
        int index = 0;
        while (true) {
            Point item1 = container->getItem(index);
            Point item2 = container->getItem(++index);
            if (item1.getName() == "undefinded") {
                // Если полученная точка пустая, значит, мы достигли конца списка
                break;
            }

            int x1 = item1.getX();
            int y1 = item1.getY();

            int x2 = item2.getX();
            int y2 = item2.getY();
            distance += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

            index++;
        }
     
        return "Расстояние = " + std::to_string(distance) + "\n" +
        "Стоимость поездки составит: " + std::to_string(tax * distance) + " рублей" + "\n";
    }
};


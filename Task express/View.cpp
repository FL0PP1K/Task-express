#include "View.h"
#include <iostream>
void View::showAmount(float amount)
{
    std::cout << "Поточна сума: "
        << amount << " грн" << std::endl;
}
void View::showStrategy(std::string name)
{
    std::cout << "Стратегія: "
        << name << std::endl;
}
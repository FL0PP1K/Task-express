#include "Observer.h"
#include <iostream>
void ConsoleLogger::update(float amount)
{
    std::cout << "Нова транзакція: "
        << amount << " грн" << std::endl;
}
void AnalyticsView::update(float amount)
{
    std::cout << "Аналітика отримала транзакцію: "
        << amount << " грн" << std::endl;
}
void TransactionService::addObserver(IObserver* observer)
{
    observers.push_back(observer);
}
void TransactionService::notifyObservers(float amount)
{
    for (IObserver* observer : observers)
    {
        observer->update(amount);
    }
}
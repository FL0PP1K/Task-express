#pragma once
#include <vector>
class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void update(float amount) = 0;
};
class ConsoleLogger : public IObserver
{
public:
    void update(float amount) override;
};
class AnalyticsView : public IObserver
{
public:
    void update(float amount) override;
};
class TransactionService
{
private:
    std::vector<IObserver*> observers;
public:
    void addObserver(IObserver* observer);

    void notifyObservers(float amount);
};
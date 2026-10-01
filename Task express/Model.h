#pragma once
#include "Observer.h"
class ITaxCalculationStrategy;
class Model
{
private:
    float amount;
    TransactionService service;
    ITaxCalculationStrategy* strategy;
public:
    Model();
    void addObserver(IObserver* observer);
    void setStrategy(ITaxCalculationStrategy* newStrategy);
    void processTransaction(float amount);
    float getAmount() const;
};
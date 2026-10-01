#include "Model.h"
#include "Strategy.h"
#include "Decorator.h"
Model::Model() : amount(0), strategy(nullptr){}
void Model::addObserver(IObserver* observer)
{
    service.addObserver(observer);
}
void Model::setStrategy(ITaxCalculationStrategy* newStrategy)
{
    strategy = newStrategy;
}
void Model::processTransaction(float amount)
{
    if (strategy == nullptr)
    {
        return;
    }
    // Strategy
    float calculatedAmount = strategy->calculateTax(amount);
    // Decorator
    BasicProcessor basic;
    FeeDecorator fee(&basic);
    LoggingDecorator logging(&fee);
    float processedAmount =
        logging.processTransaction(calculatedAmount);
    // результат
    this->amount = processedAmount;
    // Observer
    service.notifyObservers(this->amount);
}
float Model::getAmount() const
{
    return amount;
}
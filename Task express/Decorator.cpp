#include "Decorator.h"
#include <iostream>
float BasicProcessor::processTransaction(float amount)
{
    return amount;
}
TransactionDecorator::TransactionDecorator(ITransactionProcessor* processor)
{
    this->processor = processor;
}
FeeDecorator::FeeDecorator(ITransactionProcessor* processor): TransactionDecorator(processor){}
float FeeDecorator::processTransaction(float amount)
{
    float result = processor->processTransaction(amount);
    std::cout << "Декоратор комісії: додано 20 грн"
        << std::endl;
    return result + 20;
}
LoggingDecorator::LoggingDecorator(ITransactionProcessor* processor): TransactionDecorator(processor){}
float LoggingDecorator::processTransaction(float amount)
{
    float result = processor->processTransaction(amount);
    std::cout << "Декоратор логування: транзакцію оброблено. Сума: "
        << result << " грн" << std::endl;
    return result;
}
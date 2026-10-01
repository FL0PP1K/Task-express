#pragma once
class ITransactionProcessor
{
public:
    virtual ~ITransactionProcessor() = default;
    virtual float processTransaction(float amount) = 0;
};
class BasicProcessor : public ITransactionProcessor
{
public:
    float processTransaction(float amount) override;
};
class TransactionDecorator : public ITransactionProcessor
{
protected:
    ITransactionProcessor* processor;
public:
    TransactionDecorator(ITransactionProcessor* processor);
};
class FeeDecorator : public TransactionDecorator
{
public:
    FeeDecorator(ITransactionProcessor* processor);
    float processTransaction(float amount) override;
};
class LoggingDecorator : public TransactionDecorator
{
public:
    LoggingDecorator(ITransactionProcessor* processor);
    float processTransaction(float amount) override;
};
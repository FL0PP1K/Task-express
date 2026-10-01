#pragma once
#include <iostream>
class ITransactionProcessor
{
public:
	virtual ~ITransactionProcessor() = default;
	virtual void processTransaction(float amount) = 0;
};
class BasicProcessor : public ITransactionProcessor
{
public:
	void processTransaction(float amount) override {
	}
};
class TransactionDecorator : public ITransactionProcessor
{
protected:
	ITransactionProcessor* processor;	
public:
	TransactionDecorator(ITransactionProcessor* processor){
		this->processor=processor;
	}
};
class FeeDecorator : public TransactionDecorator
{
public:
	FeeDecorator(ITransactionProcessor* processor) : TransactionDecorator(processor) {}
	void processTransaction(float amount) override {
		processor->processTransaction(amount);
		std::cout << "FeeDecorator: Fee+20 UAH" << std::endl;
	}
};
class LoggingDecorator : public TransactionDecorator
{
public:
	LoggingDecorator(ITransactionProcessor* processor) :TransactionDecorator(processor) {}
		void processTransaction(float amount) override {
			processor->processTransaction(amount);
			std::cout << "LoggingDecorator: Transaction processed: " <<	amount << "UAH" << std::endl;
		}
};

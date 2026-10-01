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
	float process(float amount) override {
		return amount;
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
	float process(float amount) override {
		float result = processor->process(amount);
		std::cout << "FeeDecorator: Fee+20 UAH" << std::endl;
		return result + 20;
	}
};
class LoggingDecorator : public TransactionDecorator
{
public:
	LoggingDecorator(ITransactionProcessor* processor) :TransactionDecorator(processor) {
		float process(float amount) override {
			float result = processor->process(amount);
			std::cout << "LoggingDecorator: Transaction processed: " << result << "UAH" << std::endl;
			return result;
		}
	};
};
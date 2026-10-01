#pragma once
#include <iostream>
#include <vector>
class IObserver
{
public:
	virtual ~IObserver() = default;
	virtual void update(float amount) = 0;
};
class ConsoleLongger : public IObserver
{
public:
	void update(float amount) override {
		std::cout << "New transaction: " << amount << "UAH" << std::endl;
	}
};
class AnalyticView : public IObserver
{
public:
	void update(float amount) override {
		std::cout << "Transaction received: " << amount << "UAH" << std::endl;
	}
};
class TransactionService
{
private:
	std::vector<IObserver*> observers;
public:
	void addObserver(IObserver* observer) {
		observers.push_back(observer);
	}
	void notifyObservers(float amount) {
		for (auto observer : observers) {
			observer->update(amount);
		}
	}
};

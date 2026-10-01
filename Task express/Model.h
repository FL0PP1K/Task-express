#pragma once
#include "Observer.h"
class Model
{
private:
	float amount;
	TransactionService service;
public:
	Model() : amount(0) {}
	void addObserver(IObserver* observer) {
		service.addObserver(observer);
	}
	void setAmount(float newAmount) {
		amount = newAmount;
		service.notifyObservers(amount);
	}
	float getAmount() const {
		return amount;
	}
};


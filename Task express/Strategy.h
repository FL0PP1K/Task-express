#pragma once
class ITaxCalculationStrategy
{
public:
	virtual ~ITaxCalculationStrategy() = default;
	virtual float calculateTax(float amount) = 0;
};
class StandartTaxStrategy : public ITaxCalculationStrategy
{
public:
	float calculateTax(float amount) override {
		return amount * 1.18;
	};
};
class ITSectorTaxStrategy : public ITaxCalculationStrategy
{
public:
	float calculateTax(float amount) override {
		return amount * 1.05;
	};
};
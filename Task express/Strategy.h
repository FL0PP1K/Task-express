#pragma once
class ITaxCalculationStrategy
{
public:
    virtual ~ITaxCalculationStrategy() = default;
    virtual float calculateTax(float amount) = 0;
};
class StandardTaxStrategy : public ITaxCalculationStrategy
{
public:
    float calculateTax(float amount) override;
};
class ITSectorTaxStrategy : public ITaxCalculationStrategy
{
public:
    float calculateTax(float amount) override;
};
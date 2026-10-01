#include "Strategy.h"
float StandardTaxStrategy::calculateTax(float amount)
{
    return amount * 1.18f;
}
float ITSectorTaxStrategy::calculateTax(float amount)
{
    return amount * 1.05f;
}
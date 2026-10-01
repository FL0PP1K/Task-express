#pragma once
#include <string>
class Model;
class View;
class ITaxCalculationStrategy;
class Controller
{
private:
    Model* model;
    View* view;
public:
    Controller(Model* model, View* view);
    void setStrategy(
        ITaxCalculationStrategy* newStrategy,
        const std::string& strategyName
    );
    void processTransaction(float amount);
};
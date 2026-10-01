#pragma once
#include "Model.h"
#include "View.h"
#include "Strategy.h"
#include "Decorator.h"
class Controller
{
private:
    Model* model;
    View* view;
    ITaxCalculationStrategy* strategy;

public:
    Controller(Model* model, View* view)
    {
        this->model = model;
        this->view = view;
        this->strategy = nullptr;
    }
    void setStrategy(ITaxCalculationStrategy* newStrategy)
    {
        strategy = newStrategy;
    }
    void processTransaction(float amount)
    {
        if (strategy == nullptr)
        {
            return;
        }
        // Strategy
        float calculatedAmount = strategy->calculateTax(amount);
        std::cout << "After tax: "
            << calculatedAmount << " UAH" << std::endl;
        // Decorator
        BasicProcessor basic;
        FeeDecorator fee(&basic);
        LoggingDecorator logging(&fee);
        logging.processTransaction(calculatedAmount);
        // Model
        model->setAmount(calculatedAmount);
        // View
      
    }
};
#include "Controller.h"
#include "Model.h"
#include "View.h"
#include "Strategy.h"
Controller::Controller(Model* model, View* view)
{
    this->model = model;
    this->view = view;
}
void Controller::setStrategy(
    ITaxCalculationStrategy* newStrategy,
    const std::string& strategyName)
{
    model->setStrategy(newStrategy);
    view->showStrategy(strategyName);
}
void Controller::processTransaction(float amount)
{
    model->processTransaction(amount);
    view->showAmount(model->getAmount());
}
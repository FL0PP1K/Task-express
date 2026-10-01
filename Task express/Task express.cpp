#include <iostream>
#include "Strategy.h"
#include "Observer.h"
#include "Decorator.h"
#include "Model.h"
#include "View.h"
#include "Controller.h"
using namespace std;
int main() { 
	Model model;
	View view; 
	ConsoleLongger logger;
	View analytics;
	model.addObserver(&logger);
	Controller controller(&model, &view);
	StandartTaxStrategy standardTax;
	ITSectorTaxStrategy itTax;
	float amount;
	cout << "Enter transaction amount: ";
	cin >> amount;

	cout << "\n===== STANDARD TAX =====" << endl;
	controller.setStrategy(&standardTax);
	view.showStrategy("Standard Tax 18%");
	controller.processTransaction(amount);

	cout << "\n===== STRATEGY CHANGED =====" << endl;
	controller.setStrategy(&itTax);
	view.showStrategy("IT Sector Tax 5%");
	controller.processTransaction(amount);

	return 0;
}
#include <iostream>
#include "Strategy.h"
#include "Observer.h"
#include "Decorator.h"
#include "Model.h"
#include "View.h"
#include "Controller.h"
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
    Model model;
    View view;
    // Спостерігачі
    ConsoleLogger logger;
    AnalyticsView analytics;
    model.addObserver(&logger);
    model.addObserver(&analytics);
    Controller controller(&model, &view);
    // Стратегії
    StandardTaxStrategy standardTax;
    ITSectorTaxStrategy itTax;
    float amount = 0;
    int choice;
    cout << "Введіть суму транзакції: ";
    cin >> amount;
    do
    {
        cout << "\nМЕНЮ" << endl;
        cout << "1. Стандартний податок 18%" << endl;
        cout << "2. Податок IT-сектору 5%" << endl;
        cout << "3. Змінити суму транзакції" << endl;
        cout << "0. Вийти" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nСтандартна стратегія " << endl;
            controller.setStrategy(&standardTax, "Стандартний податок 18%");
            controller.processTransaction(amount);
            break;
        case 2:
            cout << "\nСтратегія IT-сектору " << endl;
            controller.setStrategy(&itTax, "Податок IT-сектору 5%");
            controller.processTransaction(amount);
            break;
        case 3:
            cout << "Введіть нову суму транзакції: ";
            cin >> amount;
            cout << "Суму змінено на: "
                << amount << " грн" << endl;
            break;
        case 0:
            cout << "\nЗавершення програми..." << endl;
            break;
        default:
            cout << "\nНеправильний вибір!" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}
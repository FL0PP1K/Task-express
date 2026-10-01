#pragma once
#include <iostream>
#include <string>
class View
{
public:
	void showAmount(float amount) {
		std::cout << "Current amount: " << amount << "UAH" << std::endl;
	}
	void showStrategy(std::string name) {
		std::cout << "Strategy: " << name << std::endl;
	}
};


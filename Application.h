#pragma once
#include "Root.h"

class Application {
private:
	Root* m_eq;
private:
	void PrintMenu();
	void TestAll();
	void InputLinear();
	void InputSquare();
	void Solve();
public:
	Application()
		:m_eq{nullptr}
	{};

	~Application()
	{
		delete m_eq;
	};

	void Run();
};

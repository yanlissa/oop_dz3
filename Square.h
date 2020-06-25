#pragma once

#include "Linear.h"

class Square : public Root
{
private:
	double m_a;
	double m_b;
	double m_c;
	double m_x1;
	double m_x2;
	bool m_solved;
	bool m_no_x;
	bool m_is_linear;
	bool m_zero_D;
	Linear* m_L;
public:
	Square(double a = 1, double b = 0, double c = 0)
		: m_a{a}, m_b{b}, m_c{c}, m_solved{false}, m_no_x{false}, m_zero_D{false}
	{
		m_is_linear = false;
		m_L = nullptr;

		if (a == 0.0) {
			m_is_linear = true;
			m_L = new Linear(b, c);
			return;
		}
	}

	~Square()
	{
		if (m_is_linear) {
			delete m_L;
		}
	}

	void solve() override;
	std::ostream& print(std::ostream& out) const override;
};

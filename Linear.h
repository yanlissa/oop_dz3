#pragma once

#include "Root.h"

class Linear : public Root
{
private:
	double m_a;
	double m_b;
	double m_x;
	bool m_solved;
	bool m_any_x;
	bool m_no_x;
public:
	Linear(double a = 1, double b = 0)
		:m_a{a}, m_b{b}, m_solved{false}, m_any_x{false}, m_no_x{false}
	{}

	virtual void solve();
	virtual std::ostream& print(std::ostream& out) const;
};

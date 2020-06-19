#include "Linear.h"

void Linear::solve()
{
	m_solved = true;

	if (m_a == 0.0) {
		if (m_b == 0.0) {
			m_any_x = true;
		} else {
			m_no_x = true;
		}
		return;
	}

	m_x = -m_b;
	m_x /= m_a;
}

std::ostream& Linear::print(std::ostream& out) const
{
	if (m_a != 1.0) {
		out << m_a;
	}
	out << "x ";
	if (m_b < 0) {
		out << "- " << -m_b << " ";
	} else if (m_b > 0) {
		out << "+ " << m_b << " ";
	}
	out << "= 0: x";
	if (!m_solved) {
		return out << " is still unsolved";
	}
	if (m_any_x) {
		return out << " ∊ ℝ ";
	}
	if (m_no_x) {
		return out << " ∊ ∅ ";
	}
	return out << " = " << m_x;
}

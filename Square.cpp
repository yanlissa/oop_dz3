#include <cmath>
#include "Square.h"

void Square::solve()
{
	m_solved = true;

	if (m_is_linear) {
		m_L->solve();
		return;
	}

	double D = m_b * m_b - 4 * m_a * m_c;
	if (D < 0.0) {
		m_no_x = true;
		return;
	} else if (D > 0.0) {
		D = sqrt(D);
		m_x1 = (-m_b + D) / (2 * m_a);
		m_x2 = (-m_b - D) / (2 * m_a);
		if (m_x1 == 0.0) {
			m_x1 = 0.0;
		}
		if (m_x2 == 0.0) {
			m_x2 = 0.0;
		}
	} else {
		m_zero_D = true;
		m_x1 = -m_b / (2 * m_a);
		if (m_x1 == 0.0) {
			m_x1 = 0.0;
		}
	}
}

std::ostream& Square::print(std::ostream& out) const
{
	if (m_is_linear) {
		return m_L->print(out);
	}

	if (m_a != 1.0) {
		out << m_a;
	}
	out << "x² ";
	if (m_b < 0) {
		out << "- " << -m_b << "x ";
	} else if (m_b > 0) {
		out << "+ " << m_b << "x ";
	}
	if (m_c < 0) {
		out << "- " << -m_c << " ";
	} else if (m_c > 0) {
		out << "+ " << m_c << " ";
	}
	out << "= 0: x";
	if (!m_solved) {
		return out << " is still unsolved";
	}
	if (m_no_x) {
		return out << " ∊ ∅ ";
	}
	if (m_zero_D) {
		return out << " = " << m_x1;
	}

	return out << "₁ = " << m_x1 << ", x₂ = " << m_x2;
}

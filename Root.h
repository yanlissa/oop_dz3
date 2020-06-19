#pragma once
#include <ostream>

class Root
{
public:
	virtual void solve() = 0;
	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator <<(std::ostream& out, const Root& r)
	{
		return r.print(out);
	}
};

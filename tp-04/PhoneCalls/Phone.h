#pragma once

#include "Person.h"

class Phone
{
public:
	Phone(const Person& owner)
		: _owner { owner }
	{}

	void ring() const { _owner.answer_phone(); }

private:
	const Person& _owner;
};

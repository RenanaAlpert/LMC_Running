#pragma once
#include <array>
#include "alu.h"
#include "Command.h"

namespace experis
{

class Lmc {
public:
	explicit Lmc();
	Lmc(const Lmc& a_other) = delete;
	Lmc& operator=(const Lmc& a_other) = delete;
	~Lmc();

	void Execute(Memory &a_memory);

private:
	Alu m_alu;
	
};

}
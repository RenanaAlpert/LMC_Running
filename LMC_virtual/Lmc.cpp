#include <iostream>
#include <cassert>
#include "Lmc.h"

namespace experis
{

static constexpr size_t COMMANDS_SIZE = 10;
static Command* ALL_COMMANDS[COMMANDS_SIZE] = 
{
	new Command,
	new Add,
	new Sub,
	new Sto,
	new Command,
	new Lda,
	new Bra,
	new Brz,
	new Brp,
	new IO
};
//std::array<Command, COMMANDS_SIZE> m_commands;

Lmc::Lmc()
	: m_alu{}
{
}

Lmc::~Lmc(){}

void Lmc::Execute(Memory &a_memory)
{
	std::cout << "Executing program...\n";
	for (const short bincmd : a_memory)
	{
		//assert(bincmd == 0); // I only support HLT for now
		if (bincmd == 0)
		{
			break; // program halted
		}
		else
		{
			ChangePC newPc = ALL_COMMANDS[bincmd / 100]->Execute(a_memory, bincmd % 100, this->m_alu.GetAccumulate());
			this->m_alu.SetPC(newPc.has_value() ? newPc.value() : this->m_alu.GetPC() + 1);
		}
	}

	std::cout << "HLT reached. Computer stopped" << "\n";
}

}
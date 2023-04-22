#include "Alu.h"

namespace experis
{

Alu::Alu()
	: m_pc{0}, m_accumulator{0}
{
}

Alu::~Alu()
{
}

size_t Alu::GetPC()
{
	return this->m_pc;
}

short& Alu::GetAccumulate()
{
	return this->m_accumulator;
}

void Alu::SetPC(size_t a_newPC)
{
	this->m_pc = a_newPC;
}

//void Alu::SetAccumulate(short a_newAccum)
//{
//	this->m_accumulator = a_newAccum;
//}

}
#include <execution>
#include <iostream>
#include <string>
#include "Command.h"

namespace experis
{

BadInputExeption::BadInputExeption(const char *a_msg)
	: m_msg(a_msg)
{
}

ChangePC Command::Execute(Memory &a_memory, short a_address, short& m_accumulator)
{
	throw BadInputExeption{"Illegal input"};
}

ChangePC Add::Execute(Memory &a_memory, short a_address, short& m_accumulator)
{
	m_accumulator = a_memory.at(a_address) + m_accumulator;
	return ChangePC{};
}

ChangePC Sub::Execute(Memory &a_memory, short a_address, short& m_accumulator)
{
	m_accumulator = a_memory.at(a_address) - m_accumulator;
	return ChangePC{};
}

ChangePC Sto::Execute(Memory &a_memory, short a_address, short& m_accumulator)
{
	a_memory.at(a_address) = m_accumulator;
	return ChangePC{};
}

ChangePC Lda::Execute(Memory &a_memory, short a_address, short& m_accumulator)
{
	m_accumulator = a_memory.at(a_address);
	return ChangePC{};
}

ChangePC Bra::Execute(Memory &a_memory, short a_address, short& m_accumulator)
{
	return (size_t)a_address;
}

ChangePC Brz::Execute(Memory &a_memory, short a_address, short& m_accumulator)
{
	return m_accumulator == 0 ? (size_t)a_address : ChangePC{};
}

ChangePC Brp::Execute(Memory &a_memory, short a_address, short& m_accumulator)
{
	return m_accumulator >= 0 ? (size_t)a_address : ChangePC{};
}

bool IsNumber(const std::string& a_num)
{
	for(char c : a_num)
	{
		if(!isdigit(c))
		{
			return false;
		}
	}
	return true;
}

short Input()
{
	std::cout << "Enter input\n";
	std::string untrust_input{};
	std::getline(std::cin, untrust_input);
	if (!IsNumber(untrust_input))
	{
		throw BadInputExeption{"Illegal input"};
	}
	return std::stoi(untrust_input);
}

ChangePC IO::Execute(Memory &a_memory, short a_address, short& m_accumulator)
{
	if (a_address == 1)
	{
		m_accumulator = Input();
	}
	else if (a_address == 2)
	{
		std::cout << m_accumulator << "\n";
	}
	else if (a_address == 22)
	{
		std::cout << (char)m_accumulator << "\n";
	}
	else
	{
		throw BadInputExeption{"Illegal input"};
	}
	return ChangePC{};
}

} // experis
#pragma once
#include <optional>
#include <array>

namespace experis
{
static constexpr size_t LMC_MEM_SIZE = 100;
using Memory = std::array<short, LMC_MEM_SIZE>;
using ChangePC = std::optional<size_t>;

struct BadInputExeption : public std::exception
{
	BadInputExeption(const char *a_msg);
    const char *m_msg;
};

struct Command
{
	virtual ChangePC Execute(Memory &a_memory, short a_address, short& m_accumulator);
};

struct Add : public Command
{
	virtual ChangePC Execute(Memory &a_memory, short a_address, short& m_accumulator) override;
};

struct Sub : public Command
{
	virtual ChangePC Execute(Memory &a_memory, short a_address, short& m_accumulator) override;
};

struct Sto : public Command
{
	virtual ChangePC Execute(Memory &a_memory, short a_address, short& m_accumulator) override;
};

struct Lda : public Command
{
	virtual ChangePC Execute(Memory &a_memory, short a_address, short& m_accumulator) override;
};

struct Bra : public Command
{
	virtual ChangePC Execute(Memory &a_memory, short a_address, short& m_accumulator) override;
};

struct Brz : public Command
{
	virtual ChangePC Execute(Memory &a_memory, short a_address, short& m_accumulator) override;
};

struct Brp : public Command
{
	virtual ChangePC Execute(Memory &a_memory, short a_address, short& m_accumulator) override;
};

struct IO : public Command
{
	virtual ChangePC Execute(Memory &a_memory, short a_address, short& m_accumulator) override;
};

} // experis
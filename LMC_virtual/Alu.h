#pragma once

namespace experis
{
class Alu {
public:
	explicit Alu();
	Alu(const Alu& a_other) = delete;
	Alu& operator=(const Alu& a_other) = delete;
	~Alu();

	size_t GetPC();
	short& GetAccumulate();
	void SetPC(size_t a_newPC);
	//void SetAccumulate(short a_newAccum);

private:
	size_t m_pc = 0;
	short m_accumulator = 0;
};

}
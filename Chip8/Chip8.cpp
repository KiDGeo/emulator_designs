#include <cstdint>
#include <random>
#include <iostream>
#include <vector>

class Chip8
{
	public:

		Chip8()
			: randGen(std::chrono::system_clock::now().time_since_epoch().count())
		{
			randByte = std::uniform_int_distribution<uint8_t>(0, 255U);
			pc = 0x200;
		}

		void LoadROM(const char* filename);

	private:
		std::default_random_engine randGen;
		std::uniform_int_distribution<uint8_t> randByte;	

	public:
		uint8_t registers[16]{};
		uint8_t memory[4096]{};
	        uint8_t	index{};
		uint16_t pc{};
		uint16_t stack[16]{};
		uint8_t sp{};
		uint8_t delayTimer{};
		uint8_t soundTimer{};
		uint8_t keypad[16]{};
		uint32_t video[64 * 32]{};
		uint16_t opcode;
};

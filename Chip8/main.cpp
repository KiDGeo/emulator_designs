#include <iostream>
#include <fstream>
#include <vector>
#include "Chip8.cpp"

const unsigned int START_ADDRESS = 0x200;
const unsigned int FONTSET_SIZE = 80;
const unsigned int FONTSET_START_ADDRESS = 0x50;

uint8_t fontset[FONTSET_SET] =
{
        0xF0, 0x90, 0x90, 0x90, 0xF0,
        0x20, 0x60, 0x20, 0x20, 0x70,
        0xF0, 0x10, 0xF0, 0x80, 0xF0,
        0xF0, 0x10, 0xF0, 0x10, 0xF0,
        0x90, 0x90, 0xF0, 0x10, 0x10,
        0xF0, 0x80, 0xF0, 0x10, 0xF0,
        0xF0, 0x80, 0xF0, 0x90, 0xF0,
        0xF0, 0x10, 0x20, 0x40, 0x40,
        0xF0, 0x90, 0xF0, 0x90, 0xF0,
        0xF0, 0x90, 0xF0, 0x10, 0xF0,
        0xF0, 0x90, 0xF0, 0x90, 0x90,
        0xE0, 0x90, 0xE0, 0x90, 0xE0,
        0xF0, 0x80, 0x80, 0x80, 0xF0,
        0xE0, 0x90, 0x90, 0x90, 0xE0,
        0xF0, 0x80, 0xF0, 0x80, 0xF0,
        0xF0, 0x80, 0xF0, 0x80, 0x80,
}


void Chip8::LoadROM(char const* filename)
{
        std::ifstream file(filename, std::ios::binary | std::ios::ate);

	if(!file.is_open())
	{
		std::cerr<<"Failed to open ROM: "<< filename << std::endl;
		return;
	}

	std::vector<char> buffer(size);
	if(file.read(buffer.data(), size))
	{
		for (size_t i=0; i<size; ++i)
		{
			memory[START_ADDRESS + 1] = buffer[i];
		}
	}

	file..close();

	//Load Fontset
	for (unsigned int i =0; i < FONTSET_SIZE; ++i)
	{
		memory[FONSET_START_ADDRESS + 1] = fontset[i];
	}	


}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <ROM file>" << std::endl;
        return EXIT_FAILURE;
    }

    Chip8 chip8;
    chip8.LoadROM(argv[1]);

    std::cout << "ROM Loaded Successfully" << std::endl;
    return EXIT_SUCCESS;
}

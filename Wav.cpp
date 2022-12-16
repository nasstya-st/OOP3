#define I_dont_want_to_do_this 1
#include "Wav.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ostream>


Wav::Wav(std::string filename)
{
	std::ifstream f(filename, std::ios_base::binary);
	try {
		f.read(chunkId, 4);
		f.read(reinterpret_cast<char*>(&chunkSize), 4);
		f.read(format, 4);
		f.read(subchunk1Id, 4);
		f.read(reinterpret_cast<char*>(&subchunk1Size), 4);
		f.read(reinterpret_cast<char*>(&audioFormat), 2);
		f.read(reinterpret_cast<char*>(&numChannels), 2);
		f.read(reinterpret_cast<char*>(&sampleRate), 4);
		f.read(reinterpret_cast<char*>(&byteRate), 4);
		f.read(reinterpret_cast<char*>(&blockAlign), 2);
		f.read(reinterpret_cast<char*>(&bitsPerSample), 2);
		f.read(listword, 4);

		char tmp[4];
		while (I_dont_want_to_do_this) {
			f.read(tmp, 4);
			if (tmp[0] == 'd' && tmp[1] == 'a' && tmp[2] == 't' && tmp[3] == 'a') break;
		}

		f.read(reinterpret_cast<char*>(&subchunk2Size), 4);
		wav = new short[subchunk2Size / 2];
		f.read(reinterpret_cast<char*>(wav), subchunk2Size);
	}
	catch (...) {
		printf("Uncorrect wav file format");
	}
	f.close();
}


//- 2 - 2 - 4 - 4 - 2 - 2 - 4
void Wav::savetowav(std::string filename)
{
	long a = 20;//2 + 2 + 4 + 4 + 2 + 2 + 4 + subchunk2Size + 4 + 4;
	long b = 40 + subchunk2Size;
	std::ofstream f(filename, std::ios::binary);
	f.write(chunkId, 4);
	f.write(reinterpret_cast<char*>(&b), 4);
	f.write(format, 4);
	f.write(subchunk1Id, 4);
	
	f.write(reinterpret_cast<char*>(&a), 4);
	f.write(reinterpret_cast<char*>(&audioFormat), 2);
	f.write(reinterpret_cast<char*>(&numChannels), 2);
	f.write(reinterpret_cast<char*>(&sampleRate), 4);
	f.write(reinterpret_cast<char*>(&byteRate), 4);
	f.write(reinterpret_cast<char*>(&blockAlign), 2);
	f.write(reinterpret_cast<char*>(&bitsPerSample), 2);
	f.write(listword, 4);
	f.write("d", 1);
	f.write("a", 1);
	f.write("t", 1);
	f.write("a", 1);
	f.write(reinterpret_cast<char*>(&subchunk2Size), 4);
	f.write(reinterpret_cast<char*>(wav), subchunk2Size);

	f.close();
}
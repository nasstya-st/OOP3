#pragma once
#include <string>

class Wav
{
public:
    Wav() = default;
	Wav(std::string);
	~Wav() = default;
    void savetowav(std::string);


    char chunkId[4];      // Содержит символы "RIFF" в ASCII кодировкe
    long chunkSize;     // 36 + subchunk2Size, или более точно: 4 + (8 + subchunk1Size) + (8 + subchunk2Size)  // Это оставшийся размер цепочки, начиная с этой позиции. Иначе говоря, это размер файла - 8, то есть, исключены поля chunkId и chunkSize.
    char format[4]; // Содержит символы "WAVE"
    char subchunk1Id[4]; // Содержит символы "fmt "
    long subchunk1Size; // Это оставшийся размер подцепочки, начиная с этой позиции.  
    short audioFormat;
    short numChannels; // Количество каналов. Моно = 1
    long sampleRate; // Частота дискретизации.  44100 Гц
    long byteRate;  //byte per second  //88200 byte  // sampleRate * numChannels * bitsPerSample/8
    short blockAlign;  // numChannels * bitsPerSample/8  // Количество байт для одного сэмпла, включая все каналы.
    short bitsPerSample; // Так называемая "глубиная" или точность звучания. 16 бит и т.д.
    char listword[4];
    long subchunk2Size; //размер даты

    short* wav;  //дата

private:

};


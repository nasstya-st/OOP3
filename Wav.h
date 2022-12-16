#pragma once
#include <string>

class Wav
{
public:
    Wav() = default;
	Wav(std::string);
	~Wav() = default;
    void savetowav(std::string);


    char chunkId[4];      // �������� ������� "RIFF" � ASCII ��������e
    long chunkSize;     // 36 + subchunk2Size, ��� ����� �����: 4 + (8 + subchunk1Size) + (8 + subchunk2Size)  // ��� ���������� ������ �������, ������� � ���� �������. ����� ������, ��� ������ ����� - 8, �� ����, ��������� ���� chunkId � chunkSize.
    char format[4]; // �������� ������� "WAVE"
    char subchunk1Id[4]; // �������� ������� "fmt "
    long subchunk1Size; // ��� ���������� ������ ����������, ������� � ���� �������.  
    short audioFormat;
    short numChannels; // ���������� �������. ���� = 1
    long sampleRate; // ������� �������������.  44100 ��
    long byteRate;  //byte per second  //88200 byte  // sampleRate * numChannels * bitsPerSample/8
    short blockAlign;  // numChannels * bitsPerSample/8  // ���������� ���� ��� ������ ������, ������� ��� ������.
    short bitsPerSample; // ��� ���������� "��������" ��� �������� ��������. 16 ��� � �.�.
    char listword[4];
    long subchunk2Size; //������ ����

    short* wav;  //����

private:

};


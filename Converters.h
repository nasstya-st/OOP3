#pragma once
#include "Wav.h";
#include <vector>

class Convert;

typedef struct ParsedLine {
    std::string conftxt;
    Convert* conv;
    std::string output;
    int currinput;
    std::vector<Wav> inputs;
    int sndinp;
    int start;
    int end;
}Parsed;

class Converters
{
public:
	Converters() = default;
	~Converters() = default;
    virtual Wav* func(Parsed*) = 0;
private:

};
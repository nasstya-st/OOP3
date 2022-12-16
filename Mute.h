#pragma once
#include "Converters.h"
#include "Wav.h"


class Mute : public Converters
{
public:
    Mute() = default;
    ~Mute() = default;
    Wav* func(Parsed* p) {
        Wav* res = new Wav;
        *res = p->inputs[p->currinput];
        
        int startidx = p->start * res->byteRate / 2;
        if (startidx > p->inputs[p->currinput].subchunk2Size / 2) printf("Mix start index is out of range");
        int endidx = p->end * res->byteRate / 2;
        if (endidx > p->inputs[p->currinput].subchunk2Size / 2 || p->end == -1) endidx = p->inputs[p->currinput].subchunk2Size / 2;
        for (int i = startidx; i < endidx; ++i) {
            res->wav[i] = 0;
        }
        return res;
    }
};


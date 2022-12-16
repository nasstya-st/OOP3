#pragma once

#include "Converters.h"
#include "Wav.h"


class Mix : public Converters
{
public:
    Mix() = default;
    ~Mix() = default;
    Wav* func(Parsed* p) {
        Wav* res = new Wav;
        *res = p->inputs[p->currinput];

        int startidx = p->start * res->byteRate / 2;
        if (startidx > p->inputs[p->currinput].subchunk2Size / 2) printf("Start index is out of range");
        int endidx = p->end * res->byteRate / 2;
        if (endidx > p->inputs[p->currinput].subchunk2Size / 2 || p->end == -1) endidx = std::min(p->inputs[p->currinput].subchunk2Size, p->inputs[p->sndinp].subchunk2Size) / 2;
        for (int i = startidx; i < endidx; ++i) {
            res->wav[i] = (p->inputs[p->currinput].wav[i] + p->inputs[p->sndinp].wav[i])/2;
        }
        return res;
    }
};

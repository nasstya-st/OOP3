#define _CRT_SECURE_NO_WARNINGS
#define I_dont_want_to_do_this 1
#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ostream>

#include "Converters.h"
#include "ConvertMute.h"
#include "ConvertMix.h"
#include "ConvertLow.h"
#include "Wav.h"

void help() {
    printf("Existing commands:\nmute <start(second)> [<end(second)>]\n");
    printf("mix <&n>(number of input file to mix with) <start> [<end>]\n");
    printf("low <start> [<end>]");
}

void help2() {
    printf("Existing parameters:\n-h help\n");
    printf("-c <config.txt> <input1.wav> [input2.wav...]  txt file with commands and wav files to use");
}

void parse(Parsed& res, std::string s) {
	if (s.substr(0, 4) == "mute") {
        res.conv = new ConvertMute();
        std::string tmp = "";
        int i = 5;
        while (s[i] != ' ' && i < s.size()) {
            tmp.push_back(s[i]);
            ++i;
        }
        res.start = stoi(tmp);
        tmp = "";
        ++i;
        while (i < s.size()) {
            tmp.push_back(s[i]);
            ++i;
        }
        res.end = tmp == "" ? -1 : stoi(tmp);
	}
    else if (s.substr(0, 3) == "mix") {
        res.conv = new ConvertMix();
        res.sndinp = stoi(s.substr(5, 6))-1;
        std::string tmp = "";
        int i = 7;
        while (s[i] != ' ' && i < s.size()) {
            tmp.push_back(s[i]);
            ++i;
        }
        res.start = stoi(tmp);
        tmp = "";
        ++i;
        while (i < s.size()) {
            tmp.push_back(s[i]);
            ++i;
        }
        res.end = tmp == "" ? -1 : stoi(tmp);
    }
    else if (s.substr(0, 3) == "low") {
        res.conv = new ConvertLow();
        std::string tmp = "";
        int i = 4;
        while (s[i] != ' ' && i < s.size()) {
            tmp.push_back(s[i]);
            ++i;
        }
        res.start = stoi(tmp);
        tmp = "";
        ++i;
        while (i < s.size()) {
            tmp.push_back(s[i]);
            ++i;
        }
        res.end = tmp == "" ? -1 : stoi(tmp);
    }
    else {  
        printf("unrecognized command\n");
        help();
    }
}



int main(int argc, char** argv) {
    Parsed configs;
    if (strcmp(argv[1], "-h") == 0) {
        help();
    }
    else if (strcmp(argv[1], "-c") == 0) {
        configs.conftxt = argv[2];
        configs.output = argv[3];
        for (int i = 4; i < argc; ++i) {
            Wav tmp(argv[i]);
            configs.inputs.push_back(tmp);
        }
    }
    else {
        printf("unrecognized command\n");
        help2();
    }

    std::ifstream f(configs.conftxt);
    std::string line;
    
    configs.currinput = 0;
    while (getline(f, line)) {
        parse(configs, line);  
        configs.inputs[configs.currinput] = *(configs.conv->Apply_construct(&configs));
    }
    configs.inputs[configs.currinput].savetowav(configs.output);
    return 0;
}


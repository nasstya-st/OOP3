#pragma once
#include "Convert.h"
#include "Mute.h"
class Converters;

class ConvertMute : public Convert {
public:
	Converters* factory_method() {
		return new Mute();
	};
};
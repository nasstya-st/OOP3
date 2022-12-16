#pragma once
#include "Convert.h"
#include "Low.h"
class Converters;


class ConvertLow : public Convert {
public:
	Converters* factory_method() {
		return new Low();
	};
};
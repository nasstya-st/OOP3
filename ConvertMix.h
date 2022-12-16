#include "Convert.h"
#include "Mix.h"
class Converters;


class ConvertMix : public Convert {
public:
	Converters* factory_method() {
		return new Mix();
	};
};
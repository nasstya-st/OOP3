#pragma once
#include "Converters.h"

class Convert
{
public:
	Convert() = default;
	~Convert() = default;
	virtual Converters* factory_method() = 0;   
	Wav* Apply_construct(Parsed* configs) {  //������� ��������� � �������� ��� �������
		return factory_method()->func(configs);
	}
};


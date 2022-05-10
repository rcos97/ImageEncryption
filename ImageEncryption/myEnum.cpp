#include "myEnum.h"
namespace myEnum {
	int getColorNum(Color c) {
		int color = -1;
		switch (c)
		{
		case myEnum::Color::RED:
			color = 0;
			break;
		case myEnum::Color::GREEN:
			color = 1;
			break;
		case myEnum::Color::BLUE:
			color = 2;
			break;
		default:
			break;
		}
		return color;
	}
}
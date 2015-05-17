#pragma once


#include "Line.h"

class Score {
private:
	Line line_;
public:
	Score(Line line);
	~Score();

	int Total();

};


#pragma once

class Player
{
public:
	virtual int makeMove();
	virtual int getMove() const;

protected:
	int move{ -1 };
};
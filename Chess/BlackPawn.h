#pragma once
#include "Pawn.h"

class BlackPawn : public Pawn
{
private:
	bool isPlace{ false };

public:
	BlackPawn();

	bool GetIsPlace() { return isPlace; }

	void SetIsPlace() { isPlace = true; }
};
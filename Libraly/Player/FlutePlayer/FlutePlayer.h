#pragma once

#include"../PlayerBase.h"

class FlutePlayer :public PlayerBase
{
public:
	FlutePlayer() {};
	~FlutePlayer() {};

	void Init()override;
	void Load()override {};
	void SetRectangle()override;

};
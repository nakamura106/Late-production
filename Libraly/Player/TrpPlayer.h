#pragma once


#include"PlayerBase.h"



class TrpPlayer :public PlayerBase
{
public:
	TrpPlayer();
	~TrpPlayer();
	 //!< 初期化関数
	 void Init()override;
	
	 void SetRectangle()override;

	 void Load()override;
private:
	


};


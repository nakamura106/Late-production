#pragma once



#include"../Object/Definition.h"
#include"../Object/ObjectBase.h"
#include"../Engine/Texture.h"

class PlayerBase :public ObjectBase
{
public:
	PlayerBase();
	~PlayerBase();
	virtual void Init() = 0;
	virtual void Load() = 0;
	virtual void Create() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void P_Controll() = 0;
	virtual void InitAnimation()=0;
	virtual void DrawAnimation() = 0;
	virtual void UpdateAnimation() = 0;
	virtual void Jump() = 0;
	virtual void ReleaseNote() = 0;
	virtual void GetMotion(int Llist, int Rlist)=0;
	virtual Position GetPos() = 0;


protected:
	int		m_hp;							//体力
	bool	m_do_jump;						//ジャンプ判定
	bool	m_is_active;					//動いているかの判定
	bool	m_play_note[6];					//音符生成
	int		m_List;							//テクスチャーリスト保存用
	int		m_Key;							//長調か短調か

	UVANIMATION Animation[MaxAnimationNum];	//アニメーションのスプリット保存用

	UVANIMATION clear_animation_Right[12];	//アニメーションの枚数が違うので放置
	UVANIMATION clear_animation_Left[12];	//同文
};
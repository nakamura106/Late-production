#include "PlayerBaseUi.h"


PlayerBaseUi::PlayerBaseUi()
{
	Init();
}

PlayerBaseUi::~PlayerBaseUi()
{
}

void PlayerBaseUi::Init()
{
	m_pos.x = 20.0f;
	m_pos.y = 20.0f;
	LoadTexture("Res/Tex/Performance Symbol.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayerUi);
	m_param.category_id = TEXTURE_CATEGORY_GAME;
	m_param.texture_id = GameCategoryTextureList::GamePlayerUi;
}

void PlayerBaseUi::Update()
{

}

void PlayerBaseUi::Draw()
{
	// DrawTexture(0.0f, 0.0f, GetTexture(m_param.category_id, m_param.texture_id));
	DrawUVTexture(m_pos.x, m_pos.y, 524.0f, 222.0f, GetTexture(m_param.category_id, m_param.texture_id), 0.12792969f * 4, 0);

}
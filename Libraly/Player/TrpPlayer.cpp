#include"TrpPlayer.h"
#include"../Engine/Graphics.h"
#include"../Texture/Texture.h"
#include"../Object/Definition.h"
#include"../Engine/Vec.h"
#include"../Engine/Input.h"





TrpPlayer::TrpPlayer()
{
	
}

TrpPlayer::~TrpPlayer()
{

}

void TrpPlayer::Init()
{
	m_is_delete = false;
	m_is_invincible = false;
	m_is_jump = false;
	m_is_active = false;
	m_hp = 5;
	m_direction = RIGHT;
	m_state = (int)P_State::Wait;
	m_pos.x = P_posX;
	m_pos.y = P_posY;
	m_centerX = m_pos.x + 128.0f;
	m_centerY = m_pos.y + 128.0f;
	m_sprite_width = 256.0f;
	m_sprite_height = 256.0f;
	m_range = P_trp_range;
	m_List = GamePlayer_Taiki_Tp_RightTex;
	Load();
	InitAnimation();
}

void TrpPlayer::Load()
{
	LoadTexture("Res/Tex/Player_Taiki_Tp_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_Taiki_Tp_RightTex);
	LoadTexture("Res/Tex/Player_Taiki_Tp_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_Taiki_Tp_LeftTex);
	LoadTexture("Res/Tex/Player_Attack_Tp_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_Attack_Tp_LeftTex);
	LoadTexture("Res/Tex/Player_Attack_Tp_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_Attack_Tp_RightTex);
	LoadTexture("Res/Tex/Player_Damage_Tp_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_Damage_Tp_LeftTex);
	LoadTexture("Res/Tex/Player_Damage_Tp_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_Damage_Tp_RightTex);
	LoadTexture("Res/Tex/Player_Jump_Tp_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_Jump_Tp_LeftTex);
	LoadTexture("Res/Tex/Player_Jump_Tp_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_Jump_Tp_RightTex);
	LoadTexture("Res/Tex/Player_JumpAttack_Tp_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_JumpAttack_Tp_LeftTex);
	LoadTexture("Res/Tex/Player_JumpAttack_Tp_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_JumpAttack_Tp_RightTex);
	LoadTexture("Res/Tex/Player_JumpDamage_Tp_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_JumpDamage_Tp_LeftTex);
	LoadTexture("Res/Tex/Player_JumpDamage_Tp_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_JumpDamage_Tp_RightTex);
	LoadTexture("Res/Tex/Player_Walk_Tp_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_Walk_Tp_LeftTex);
	LoadTexture("Res/Tex/Player_Walk_Tp_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GamePlayer_Walk_Tp_RightTex);

}

void TrpPlayer::Create()
{
	
	
}

void TrpPlayer::Update()
{
	P_Controll();
}

void TrpPlayer::Draw()
{
	if (m_is_delete==false)
	{
		switch (m_state)
		{
		case (int)P_State::Wait:
			GetMotion(GamePlayer_Taiki_Tp_LeftTex,GamePlayer_Taiki_Tp_RightTex);
			DrawAnimation();
			break;
		case(int)P_State::Move:
			GetMotion(GamePlayer_Walk_Tp_LeftTex, GamePlayer_Walk_Tp_RightTex);
			DrawAnimation();
			break;
		case(int)P_State::Jump:
			GetMotion(GamePlayer_Jump_Tp_LeftTex, GamePlayer_Jump_Tp_RightTex);
			DrawAnimation();
			break;
		case(int)P_State::Jump_Attack:
			GetMotion(GamePlayer_JumpAttack_Tp_LeftTex, GamePlayer_JumpAttack_Tp_RightTex);
			DrawAnimation();
			break;
		case(int)P_State::Jump_Damage:
			GetMotion(GamePlayer_JumpDamage_Tp_LeftTex, GamePlayer_JumpDamage_Tp_RightTex);
			DrawAnimation();
			break;
		case(int)P_State::Damage:
			GetMotion(GamePlayer_Damage_Tp_LeftTex, GamePlayer_Damage_Tp_RightTex);
			DrawAnimation();
			break;
		case(int)P_State::Attack:
			GetMotion(GamePlayer_Attack_Tp_LeftTex, GamePlayer_Attack_Tp_RightTex);
			DrawAnimation();
			break;
		default:
			break;
		}
	}
}

Position TrpPlayer::GetPos()
{
	return m_pos;
}

void TrpPlayer::P_Controll()
{
	if (m_is_active == true) {
		m_is_active = false;
	}
	
	if (GetKey(RIGHT_KEY) == true)
	{
		m_state = (int)P_State::Move;
		m_direction = RIGHT;
		m_pos.x += P_speed;
		m_is_active = true;
	}

	if (GetKey(LEFT_KEY) == true)
	{
		m_state = (int)P_State::Move;
		m_direction = LEFT;
		m_pos.x -= P_speed;
		m_is_active = true;
	}

	if (GetKey(SPACE_KEY) == true)
	{
		m_is_jump = true;
		m_is_active = true;
	}

	if (GetKey(ONE_KEY) == true)
	{

	}

	if (m_is_active == false)
	{
		m_state = (int)P_State::Wait;
	}

	if (m_is_jump == true)
	{
		Jump();
	}
	
	if (m_pos.x <= 0)
	{
		m_pos.x += P_speed;
	}

	if (m_pos.x >= 704.0f)
	{
		m_pos.x -= P_speed;
	}

	
}

void TrpPlayer::InitAnimation()
{


	static float R_X, R_Y;

	
		R_X = 0, R_Y = 0;
		for (int i = 0; i < 12; i++)
		{
			
				Animation[i].m_RectX = R_X;
				Animation[i].m_RectY = R_Y;
				Animation[i].m_Rect_Height = Rect_Height;
				Animation[i].m_Rect_Width = Rect_Width;
				Animation[i].m_Display_Flame = Dispflame;

				R_X += RectX;

				if (R_X >= 1.0f)
				{
					if (R_Y <= 0.75f)
					{
						R_Y += RectY;
					}
					else
					{
						R_Y = 0;
					}
					R_X = 0;
				}
		}
	



}

void TrpPlayer::GetMotion(int Llist_, int Rlist_)
{
	if (m_direction == RIGHT)
	{
		m_List = Rlist_;
	}
	if (m_direction == LEFT)
	{
		m_List = Llist_;
	}
}

void TrpPlayer::DrawAnimation()
{
	static int i = 0;



	if (m_direction == RIGHT)
	{
		DrawUVTexture(m_pos.x, m_pos.y, Animation[i].m_Rect_Width, Animation[i].m_Rect_Height, GetTexture(TEXTURE_CATEGORY_GAME,m_List), Animation[i].m_RectX, Animation[i].m_RectY);
		Animation[i].m_Display_Flame--;
		if (Animation[i].m_Display_Flame <= 0)
		{
			Animation[i].m_Display_Flame = Dispflame;
			i++;
			if (i >= 11)
			{
				i = 0;
			}
		}
	}
	if (m_direction == LEFT)
	{
		DrawUVTexture(m_pos.x-128.f, m_pos.y, Animation[i].m_Rect_Width, Animation[i].m_Rect_Height, GetTexture(TEXTURE_CATEGORY_GAME, m_List), Animation[i].m_RectX, Animation[i].m_RectY);
		Animation[i].m_Display_Flame--;
		if (Animation[i].m_Display_Flame <= 0)
		{
			Animation[i].m_Display_Flame = Dispflame;
			i++;
			if (i >= 11)
			{
				i = 0;
			}
		}
	}

}


void TrpPlayer::Jump()
{
	static float jump_power = P_jump_power;
	if (m_state != (int)P_State::Damage && m_state != (int)P_State::Attack)	
	{
		m_state = (int)P_State::Jump;
	}

	m_pos.y -= jump_power;
	jump_power -= Gravity;

	if (m_pos.y >= P_posY)
	{
		jump_power = P_jump_power;	
		m_is_jump = false;
		m_is_active = false;
	}
}
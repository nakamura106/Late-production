﻿#include"Bird.h"
#include"../Bullet/ShitBullet.h"

Bird::Bird()
	:EnemyBase(0.f, EnemyID::Seagull)
{

	LoadAIData(M_AIDataFileName);

	m_savetime_shit_cycle = FlameTimer::GetNowFlame();
	m_shot_adjust.x = m_draw_param.tex_size_x / 2.f;
	m_shot_adjust.y = m_draw_param.tex_size_y - 200.f;
	
}

Bird::~Bird()
{
}

void Bird::Init()
{

	LoadTexture("Res/Tex/Enemy/Bird/Boss2_Habataki_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_WalkLeft);
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_Habataki_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_WalkRight);
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_Tukare_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_FatigueLeft);
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_Tukare_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_FatigueRight);
	
	//注！鳥は待機に二種類ある！
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_Taiki_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_SkyWaitLeft);
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_Taiki_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_SkyWaitRight);
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_TaikiGround_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_WaitLeft);
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_TaikiGround_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_WaitRight);

	//注！この画像に限り、分割数が横4*縦4(使用枚数12)→8*4(24)に変更
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_DashAttack_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_Attack1Left);
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_DashAttack_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_Attack1Right);
	
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_Sleep_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_SleepLeft);
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_Sleep_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_SleepRight);
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_Down_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_DownLeft);
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_Down_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_DownRight);
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_HaneAttack_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_Attack2Left);
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_HaneAttack_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_Attack2Right);
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_Boss2_HaneGreen.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_Bullet_Normal);
	
	//3つ目の攻撃フン落下で使用するモーションはただの羽ばたき
	//LoadTexture("Res/Tex/Enemy/Bird/Boss2_HeadAttack_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_Attack3Left);
	//LoadTexture("Res/Tex/Enemy/Bird/Boss2_HeadAttack_Right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_Attack3Right);

	//弾画像
	LoadTexture("Res/Tex/Enemy/Bird/Boss2_Hun.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameEnemy_Bullet_Shit);

}

void Bird::SetRectangle()
{
	m_rect_param.shift_x	= 250.f;//105.0f;
	m_rect_param.shift_y	= 440.0f;
	m_rect_param.width		= 829.0f;
	m_rect_param.height		= 561.0f;
}

EnemyAIType Bird::ChangeAIType()
{
	return EnemyAIType::AI1;
}

void Bird::EnemyAttack1()
{

}

void Bird::EnemyAttack2()
{

}

void Bird::EnemyAttack3()
{
	if (FlameTimer::GetNowFlame(m_savetime_shit_cycle) >= M_SHIT_CYCLE) {
		//発射
		CreateShitBullet();

		m_savetime_shit_cycle = FlameTimer::GetNowFlame();

	}
}

void Bird::InitAttack3State()
{
	InitWalkState();
}

void Bird::CreateShitBullet()
{
	Position b_pos = GetShotPos();

	bullet_list.push_back(
		new ShitBullet(
			b_pos.x,
			b_pos.y,
			m_speed,
			0.02f,		//加速度
			(Direction)m_direction
		)
	);

}

void Bird::InitAllState()
{

	EnemyBase::InitAllState();

	//現在のフレームを取得
	m_savetime_shit_cycle = FlameTimer::GetNowFlame();

}
﻿#include"Bird.h"
#include"../Bullet/ShitBullet.h"

Bird::Bird()
	:EnemyBase(0.f, EnemyID::Seagull)
{

	LoadAIData(M_AIDataFileName);
	CompleteChangeState();

	m_savetime_shit_cycle = FlameTimer::GetNowFlame();
	m_is_init_motion_end = false;
	m_shot_adjust.x = m_draw_param.tex_size_x / 2.f;
	m_shot_adjust.y = m_draw_param.tex_size_y - 300.f;
	
}

Bird::~Bird()
{

}

void Bird::Init()
{
	
}

void Bird::SetRectangle()
{//140,397,
	m_rect_param.shift_x	= 250.f;//105.0f;
	m_rect_param.shift_y	= 440.0f;
	m_rect_param.width		= 829.0f;
	m_rect_param.height		= 561.0f;
}

EnemyAIType Bird::ChangeAIType()
{
	return EnemyAIType::AI1;
}

void Bird::InitFlyState()
{
	if (m_is_flying == true) {
		InitAttack1State();
	}
	else {
		InitFlappingState();
	}
}

void Bird::InitAttack1State()
{
	EnemyBase::InitAttack1State();

	//この画像のみ分割数が異なる
	m_anim_param.split_all		= 24;
	m_anim_param.split_height	= 4;
	m_anim_param.split_width	= 8;
}

void Bird::InitFlappingState()
{
	if (m_direction == Direction::LEFT) {
		m_draw_param.texture_id = GameCategoryTextureList::GameEnemy_FlappingLeft;
	}
	else {
		m_draw_param.texture_id = GameCategoryTextureList::GameEnemy_FlappingRight;
	}
}

void Bird::EnemyAttack1()
{

}

void Bird::EnemyAttack2()
{
	//ハネ攻撃
	if (GetAnimationTexNum() > M_ATTACK2_ANIM_TEX_NUM && !m_do_bullet) {

		m_do_bullet = true;

		for (int i = 0;i < 3;++i) {
			//弾発射
			CreateBullet(m_speed, m_speed + (float)i, true, 45);
		}

	}

}

void Bird::EnemyAttack3()
{
	if (FlameTimer::GetNowFlame(m_savetime_shit_cycle) >= M_SHIT_CYCLE) {
		//発射
		CreateShitBullet();

		m_savetime_shit_cycle = FlameTimer::GetNowFlame();

	}
}

void Bird::EnemyFly()
{
	//飛行状態
	if (m_is_flying == true) {
		FlyStateFall();
	}
	else {
		FlyStateRise();
	}
}

void Bird::FlyStateRise()
{
	//モーション切り替え処理
	if (m_is_init_motion_end != true) {

		if (m_is_animation_end == true) {
			//最初のモーションのアニメーションが終わり次第、
			//待機モーションへ
			EnemyBase::InitFlyState();

			//移動開始
			m_is_init_motion_end = true;
		}
		else {
			return;
		}

	}

	//上空に飛んでいく
	m_pos.y -= m_speed;

	//上空まで飛んだ
	if (m_pos.y <= M_SKY_HEIGHT) {

		m_pos.y = M_SKY_HEIGHT;

		m_is_flying = true;

		ChangeState(EnemyStateType::Wait);

	}
}

void Bird::FlyStateFall()
{

	//最後のモーションに行き次第、状態遷移
	if (m_is_animation_end == true) {

		m_is_flying = false;

		ChangeState(EnemyStateType::Wait);

	}

	//指定されたモーションの場合は動作しない
	if (GetAnimationTexNum() < M_FLYFALL_STOP_ANIMATION) {
		//停止
		return;
	}

	//移動処理等
	if (m_pos.y >= M_INIT_POS_Y) {

		m_pos.y = M_INIT_POS_Y;

		m_animation_stop = false;

	}
	else {
		//地上に斜め方向で降りてくる
		m_pos.y += m_speed;

		EnemyBase::EnemyMove();

		//落下中はアニメーションストップ
		m_animation_stop = true;
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
			0.f,
			m_speed,
			0.05f,		//加速度
			(Direction)m_direction
		)
	);

}

void Bird::InitAllState()
{

	EnemyBase::InitAllState();

	//現在のフレームを取得
	m_savetime_shit_cycle = FlameTimer::GetNowFlame();

	m_is_init_motion_end = false;

	//基本この分割数
	m_anim_param.split_all = 12;
	m_anim_param.split_height =
	m_anim_param.split_width = 4;

}

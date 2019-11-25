#pragma once


#include"../Object/ObjectBase.h"

class EnemyBase :public ObjectBase
{
public:

	virtual void Init() = 0;
	virtual void Create() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual int GetEnemyPosX();
	virtual int GetEnemyPosY();
	virtual EnemyStateType GetEnemyState();

	virtual void UpdateState();
	virtual void ChangeState();

	virtual void EnemyMove();
	virtual void EnemyRefuge();
	virtual void EnemyAttack();
	virtual void EnemyIdle();
	virtual void EnemyBreak();

	virtual int GetSleepGauge();
	virtual int GetFatigueGauge();

	virtual void CureSleepiness();
	virtual void CureFatigue();

	virtual void DamageSleepness(int damage_sleep_);
	virtual void DamageFatigue(int damage_fatigue_);

protected:

	float m_sleep_gauge;	//眠りゲージ
	float m_fatigue_gauge;	//疲労ゲージ
	int m_time_of_break;	//休憩時間
	bool m_is_break;		//休憩しているか
	bool m_is_hit_judge;	//当たり判定が存在するか
	float m_speed;			//スピード
	
	Position m_enemy_pos;
	Enemy m_Enemy_Id;
	EnemyStateType m_State;
	EnemyAttackRepertory m_attack_repertory;
	EnemytoPlayerState m_enemy_to_player_state;

public:
	EnemyBase();
	~EnemyBase();

};

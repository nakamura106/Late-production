#ifndef DEFINITION_H_
#define DEFINITION_H_

// 構造体、enumまとめ用

enum class Player
{
	PlayerTypeTrumpet,
	PlayerTypeFlute,
	PlayerTypeTuba,

	PlayerTypeMax,
};

enum class PlayerState
{
	Wait,
	Move,
	Jump,
	ThinkA,
	Think
};

enum class Enemy
{
	BossType01,
	BossType02,
	BossType03,

	BossTypeMax,
};

enum class EnemyStateType 
{
	Idle,
	Warn,
	Attack,
	Refuge,
	Break,
	EnemyStateTypeMax,
};

struct Position
{
	float x;
	float y;
};

#endif

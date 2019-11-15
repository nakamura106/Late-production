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
	ThinkB
};

enum class Enemy
{
	BossType01,
	BossType02,
	BossType03,

	BossTypeMax,
};

struct Position
{
	float x;
	float y;
};

#endif

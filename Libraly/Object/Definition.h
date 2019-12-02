#ifndef DEFINITION_H_
#define DEFINITION_H_

// 構造体、enumまとめ用

#define P_posX			100.0f  //初期座標
#define P_posY			600.0f	//初期座標
#define P_trp_range		1000.0f	//攻撃範囲
#define P_speed			5.0f	//移動速度
#define P_jump_power	17.0f	//ジャンプ力
#define P_MaxHP			5		//プレイヤーの体力
#define Gravity			0.5f	//落下用重力
#define Dispflame		6		//描画時間
#define Rect_Height     256.0f	//矩形の高さ
#define Rect_Width		256.0f	//矩形の幅
#define RectX			0.25f	//矩形の左上座標X
#define RectY			0.25f	//矩形の左上座標Y
#define MaxRectX		1.0f	//統合画像の端X
#define MaxRectY		0.75f	//統合画像の下端Y
#define MaxAnimationNum	12		//アニメーションの枚数
#define InitRectX		0.0f	//矩形座標初期化用X
#define InitRectY		0.0f	//矩形座標初期化用Y
#define Centerofscreen	704.0f	//プレイヤー停止用画面中央
#define lrAdjustment	128.0f	//左右描画ずれ調整用


enum class Player
{
	PlayerTypeTrumpet,
	PlayerTypeFlute,
	PlayerTypeTuba,

	PlayerTypeMax,
};

enum class P_State
{
	Wait,
	Move,
	Jump,
	Jump_Attack,
	Jump_Damage,
	Damage,
	Attack,
	ThinkA,
	ThinkB,
	Death,
	Clear,

};

enum class Key
{
	Major,
	Minor,
};

//敵から見るプレイヤーの動作
enum class EnemytoPlayerState
{
	Separated,	//離れた
	Close,		//近い
	Escape,		//逃げる
	Pursue,		//追う
	EtoPStateTypeMax,
};

enum class EnemyAttackRepertory
{
	VariableEnumrate_Type,	//各エネミークラスでtypedefして使うクラス
};

enum class EnemyID
{
	Hedgehog,
	Seagull,
	Gorilla,

	BossTypeMax,
};

enum class EnemyStateType 
{
	Wait,	//待機
	Warn,	//警戒
	Attack,	//攻撃
	Refuge,	//ピンチ状態のエネミー逃走
	Rest,	//待機(疲労時)
	Chase,	//追跡
	Sleep,	//睡眠中
	EnemyStateTypeMax,
};

enum Direction 
{
	LEFT,
	RIGHT,
};

struct Position
{
	Position() {
		x = 0.0f;
		y = 0.0f;
	}

	float x;
	float y;
};

// 描画用変数の構造体
struct DrawParam
{
	DrawParam() {
		tu = 0.0f;
		tv = 0.0f;
		tex_size_x = 0.0f;
		tex_size_y = 0.0f;
		category_id = 0;
		texture_id = 0;
	}
	float tu;
	float tv; 
	float tex_size_x;//テクスチャの横サイズ
	float tex_size_y;//テクスチャの縦サイズ

	// GetTexture()の中身で使う
	int category_id;	
	int texture_id;		
};

//UVアニメーション用構造体(ObjectBaseで使用)
struct AnimationParam 
{
	AnimationParam() {
		split_width = 1;
		split_height = 1;
		split_all = 1;
		change_flame = 1;
	}

	int split_width;	//横分割数
	int split_height;	//縦分割数
	int split_all;		//合計分割数(縦×横-不要部分)
	int change_flame;	//画像変更のタイミング(フレーム数)

	/*Note:「split」は割れ目・分裂の意味*/
	
};

struct UVANIMATION
{
				
	float m_RectX;			// 矩形の左上座標X
	float m_RectY;			// 矩形の左上座標Y
	float m_Rect_Width;		// 矩形の横幅
	float m_Rect_Height;	// 矩形の高さ
	int m_Display_Flame;	// 表示フレーム数
		
};

struct EffectInfo
{
	float m_x;			//エフェクトのx座標
	float m_y;			//エフェクトのy座標
	int m_timer;		//描画時間タイマー
	int m_tex_id;		//テクスチャーid保存用
	bool m_is_active;	//描画判断用
	float m_width;		//横幅
	float m_height;		//高さ
	float m_tu;
	float m_tv;
};

#endif

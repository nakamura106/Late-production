#include "EffectBase.h"

EffectBase::EffectBase(ObjectBase* parent_)
{
	m_parent = parent_;
	Init();
}

EffectBase::~EffectBase()
{
}

void EffectBase::Init()
{
	m_param.m_X = m_parent->GetPos().x;
	m_param.m_Y = m_parent->GetPos().y;
}

void EffectBase::WakeUp()
{
	m_IsActive = true;
}

void EffectBase::Sleep()
{
	m_IsActive = false;
}


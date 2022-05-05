#include "MiniginPCH.h"
#include "HealthComponent.h"

dae::HealthComponent::HealthComponent(std::shared_ptr<GameObject> gameObject, int maxLives)
	:BaseComponent{ gameObject }
	, Subject{}
	, m_MaxLives{ maxLives }
	, m_CurrentLives{ maxLives }
{
}

void dae::HealthComponent::Update(float){}

void dae::HealthComponent::DecreaseLife()
{
	m_CurrentLives -= 1;
	if (m_CurrentLives <= 0)
		m_IsDead = true;

	Notify(m_pLinkedGameObject.lock(), Event::LivesChanged);
}

void dae::HealthComponent::IncreaseLife()
{
	if (m_CurrentLives < m_MaxLives)
	{
		m_CurrentLives += 1;
		Notify(m_pLinkedGameObject.lock(), Event::LivesChanged);
	}
}

int dae::HealthComponent::GetLives() const
{
	return m_CurrentLives;
}

bool dae::HealthComponent::GetIsDead() const
{
	return m_IsDead;
}

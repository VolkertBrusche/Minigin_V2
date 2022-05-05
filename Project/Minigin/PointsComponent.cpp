#include "MiniginPCH.h"
#include "PointsComponent.h"

dae::PointsComponent::PointsComponent(std::shared_ptr<GameObject> gameObject)
	:BaseComponent{ gameObject }
	, Subject{}
{
}

void dae::PointsComponent::Update(float){}

void dae::PointsComponent::AddPoints(int amount)
{
	m_Points += amount;
	Notify(m_pLinkedGameObject.lock(), Event::PointsChanged);
}

void dae::PointsComponent::DecreasePoints(int amount)
{
	if (m_Points == 0)
		return;
	
	m_Points -= amount;
	Notify(m_pLinkedGameObject.lock(), Event::PointsChanged);
}

int dae::PointsComponent::GetPoints() const
{
	return m_Points;
}
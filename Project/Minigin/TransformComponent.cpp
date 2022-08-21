#include "MiniginPCH.h"
#include "TransformComponent.h"
#include "GameObject.h"

dae::TransformComponent::TransformComponent(std::shared_ptr<GameObject> gameObject)
	:BaseComponent{gameObject}
{
	//gameObject->AddComponent(shared_from_this()); //shared_from_this() doesn't work in constructor because
													//the shared_ptr of this hasn't been created yet

	if (gameObject)
	{
		if (gameObject->GetParent() != nullptr)
		{
			m_pParentTransformComponent = gameObject->GetParent()->GetComponent<TransformComponent>();
		}
	}
}

void dae::TransformComponent::SetPosition(const float x, const float y, const float z)
{
	m_pNewPos.x = x;
	m_pNewPos.y = y;
	m_pNewPos.z = z;
	m_IsDirty = true;

	for (size_t idx{}; idx < m_pLinkedGameObject.lock()->GetChildCount(); ++idx)
	{
		auto childTransformComp = m_pLinkedGameObject.lock()->GetChildAt(idx)->GetComponent<TransformComponent>();
		childTransformComp->SetPosition(x, y, z);
	}
}

void dae::TransformComponent::Update(float deltaTime)
{
	m_DeltaTime = deltaTime;

	if (m_IsDirty)
	{
		m_pPreviousPos = m_pNewPos;
		m_IsDirty = false;
	}
}

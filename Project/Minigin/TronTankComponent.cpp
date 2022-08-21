#include "MiniginPCH.h"
#include "TronTankComponent.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "TransformComponent.h"

dae::TronTankComponent::TronTankComponent(std::shared_ptr<GameObject> gameObject, const std::string& hullAssetFile, const std::string& commanderAssetFile, float maxSpeed)
	:BaseComponent{gameObject},
	m_MaxSpeed{maxSpeed}
{
	if (gameObject)
	{
		m_pHull = std::make_shared<GameObject>();
		m_pHull->SetParent(gameObject);
		m_pHull->AddComponent(std::make_shared<TextureComponent>(m_pHull));
		m_pHull->GetComponent<TextureComponent>()->SetTexture(hullAssetFile);

		m_pCommander = std::make_shared<GameObject>();
		m_pCommander->SetParent(gameObject);
		m_pCommander->AddComponent(std::make_shared<TextureComponent>(m_pCommander));
		m_pCommander->GetComponent<TextureComponent>()->SetTexture(commanderAssetFile);

		m_pTransformComp = gameObject->GetComponent<TransformComponent>();
		if (m_pTransformComp == nullptr)
		{
			gameObject->AddComponent(std::make_shared<TransformComponent>(gameObject));
			m_pTransformComp = gameObject->GetComponent<TransformComponent>();
		}
	}
}

void dae::TronTankComponent::Update(float)
{
}

void dae::TronTankComponent::Render() const
{
}

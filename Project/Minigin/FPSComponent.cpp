#include "MiniginPCH.h"
#include "FPSComponent.h"
#include "GameObject.h"
#include "TextComponent.h"
#include "Font.h"

dae::FPSComponent::FPSComponent(const std::string& text, const std::shared_ptr<Font>& font, std::shared_ptr<GameObject> gameObject)
	:BaseComponent{gameObject}
{
	if (gameObject)
	{
		m_TextComponent = gameObject->GetComponent<TextComponent>();

		if (m_TextComponent == nullptr)
		{
			m_TextComponent = std::make_shared<TextComponent>(text, font, gameObject);
			gameObject->AddComponent(m_TextComponent);
		}
	}
}

dae::FPSComponent::~FPSComponent()
{
}

void dae::FPSComponent::Update(float deltaTime)
{
	m_FPS = static_cast<int>(1.f / deltaTime);
	m_TextComponent->SetText(std::to_string(m_FPS) + " FPS");
}

void dae::FPSComponent::Render() const
{
}

int dae::FPSComponent::GetFPS() const
{
	return m_FPS;
}

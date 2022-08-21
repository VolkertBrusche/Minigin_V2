#pragma once
#include "BaseComponent.h"

namespace dae
{
	class GameObject;
	class TransformComponent final : public BaseComponent, public std::enable_shared_from_this<TransformComponent>
	{
	public:
		TransformComponent(std::shared_ptr<GameObject> gameObject);
		virtual ~TransformComponent() = default;

		const glm::vec3& GetPosition() const { return m_pPreviousPos; }
		void SetPosition(float x, float y, float z = 0.0f);
		virtual void Update(float) override;

		float GetElapsedSec() const { return m_DeltaTime; }
	private:
		glm::vec3 m_pPreviousPos{};
		glm::vec3 m_pNewPos{};

		bool m_IsDirty{ false };
		float m_DeltaTime{};
		std::shared_ptr<TransformComponent> m_pParentTransformComponent{};
	};
}


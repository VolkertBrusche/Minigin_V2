#pragma once
#include "BaseComponent.h"

namespace dae
{
    class GameObject;
    class TransformComponent;
    class TronTankComponent final: public BaseComponent
    {
    public:
        TronTankComponent(std::shared_ptr<GameObject> gameObject, const std::string& hullAssetFile, const std::string& commanderAssetFile, float m_MaxSpeed);
        virtual ~TronTankComponent() = default;

        TronTankComponent(const TronTankComponent& other) = delete;
        TronTankComponent(TronTankComponent&& other) = delete;
        TronTankComponent& operator=(const TronTankComponent& other) = delete;
        TronTankComponent& operator=(TronTankComponent&& other) = delete;

        void Update(float deltaTime) override;
        void Render() const override;

        float GetTankSpeed() const { return m_MaxSpeed; }
    private:
        std::shared_ptr<GameObject> m_pHull{};
        std::shared_ptr<GameObject> m_pCommander{};

        std::shared_ptr<TransformComponent> m_pTransformComp{};

        float m_MaxSpeed{ 200.f };
    };
}


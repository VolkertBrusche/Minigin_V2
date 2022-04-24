#pragma once
#include "BaseComponent.h"

namespace dae
{
    class Texture2D;
    class TransformComponent;
    class TextureComponent final : public BaseComponent, public std::enable_shared_from_this<TextureComponent>
    {
    public:
        TextureComponent(std::shared_ptr<GameObject> gameObject);
        virtual ~TextureComponent();

        TextureComponent(const TextureComponent& other) = delete;
        TextureComponent(TextureComponent&& other) = delete;
        TextureComponent& operator=(const TextureComponent& other) = delete;
        TextureComponent& operator=(TextureComponent&& other) = delete;

        virtual void Update(float) override {};
        virtual void Render() const override;

        void SetTexture(const std::string& filename);

    private:
        std::shared_ptr<Texture2D> m_pTexture{};
        std::shared_ptr<TransformComponent> m_TransformComponent{};
    };
}


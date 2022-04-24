#pragma once
#include "Singleton.h"

namespace dae
{
	class Scene;
	class GameObject;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		std::shared_ptr<Scene> CreateScene(const std::string& name);

		void Update(float deltaTime);
		void FixedUpdate(float fixedTime);
		void Render();

		void AddGameObjectToSceneName(const std::string& sceneName, std::shared_ptr<GameObject> gameObject);
		void RemoveGameObjectFromSceneName(const std::string& sceneName, std::shared_ptr<GameObject> gameObject);
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		std::vector<std::shared_ptr<Scene>> m_Scenes;
	};
}

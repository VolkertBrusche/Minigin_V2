#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"
#include "GameObject.h"

void dae::SceneManager::Update(float deltaTime)
{
	for(auto& scene : m_Scenes)
	{
		scene->Update(deltaTime);
	}
}

void dae::SceneManager::FixedUpdate(float fixedTime)
{
	for (auto& scene : m_Scenes)
	{
		scene->FixedUpdate(fixedTime);
	}
}

void dae::SceneManager::Render()
{
	for (const auto& scene : m_Scenes)
	{
		scene->Render();
	}
}

void dae::SceneManager::AddGameObjectToSceneName(const std::string& sceneName, std::shared_ptr<GameObject> gameObject)
{
	for (std::shared_ptr<Scene> scene : m_Scenes)
	{
		if (scene->GetSceneName() == sceneName)
		{
			scene->Add(gameObject);
		}
	}
}

void dae::SceneManager::RemoveGameObjectFromSceneName(const std::string& sceneName, std::shared_ptr<GameObject> gameObject)
{
	for (std::shared_ptr<Scene> scene : m_Scenes)
	{
		if (scene->GetSceneName() == sceneName)
		{
			scene->Remove(gameObject);
		}
	}
}

std::shared_ptr<dae::Scene> dae::SceneManager::CreateScene(const std::string& name)
{
	const auto& newScene = std::shared_ptr<Scene>(new Scene(name));
	for (std::shared_ptr<Scene> scene : m_Scenes)
	{
		if (scene->GetSceneName() == name)
			return nullptr;
	}

	m_Scenes.push_back(newScene);
	return newScene;
}

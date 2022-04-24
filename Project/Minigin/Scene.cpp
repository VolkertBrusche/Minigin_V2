#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"

using namespace dae;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) : m_Name(name) {}

Scene::~Scene() = default;

void Scene::Add(const std::shared_ptr<GameObject>& object)
{
	m_Objects.push_back(object);
}

void dae::Scene::Remove(const std::shared_ptr<GameObject>& object)
{
	m_Objects.erase(std::find(m_Objects.begin(), m_Objects.end(), object));
}

void Scene::Update(float deltaTime)
{
	for(auto& object : m_Objects)
	{
		object->Update(deltaTime);
	}
}

void dae::Scene::FixedUpdate(float fixedTime)
{
	for (auto& object : m_Objects)
	{
		object->FixedUpdate(fixedTime);
	}
}

void Scene::Render() const
{
	for (const auto& object : m_Objects)
	{
		object->Render();
	}
}


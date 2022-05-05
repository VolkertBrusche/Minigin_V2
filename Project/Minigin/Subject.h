#pragma once
#include "GameObject.h"
#include "Observer.h"
#include <vector>

namespace dae
{
	class Observer;
	class Subject
	{
	public:
		void AddObserver(std::shared_ptr<Observer> observer);
		void RemoveObserver(std::shared_ptr<Observer> observer);

	protected:
		void Notify(const std::shared_ptr<GameObject> pGameObject, Event event);

	private:
		std::vector<std::shared_ptr<Observer>> m_pObservers;
	};
}


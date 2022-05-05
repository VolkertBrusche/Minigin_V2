#pragma once
#include "GameObject.h"

namespace dae
{
	enum class Event
	{
		ActorDied,
		LivesChanged,
		PointsChanged
	};

	class Observer
	{
	public:
		virtual ~Observer() = default;
		virtual void Notify(const std::shared_ptr<GameObject> pGameObject, Event event) = 0;
	};
}


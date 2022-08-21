#pragma once
#include <iostream>
#include "Scene.h"
#include "GameObject.h"
#include "Sound_Systems.h"

//Compontents
#include "HealthComponent.h"
#include "PointsComponent.h"
#include "TransformComponent.h"
#include "TronTankComponent.h"

namespace dae
{
	class Command
	{
	public:
		virtual ~Command() = default;
		virtual void Execute() = 0;
		virtual void Undo() = 0;
	};

	class JumpCommand final : public Command
	{
	public:
		void Execute() override { std::cout << "Player Jumped!\n"; }
		void Undo() override { std::cout << "Undo Player Jump!\n"; }
	};

	class FireCommand final : public Command
	{
	public:
		void Execute() override { std::cout << "Player Fired!\n"; }
		void Undo() override { std::cout << "Undo Player Fire!\n"; }
	};

	class CrouchCommand final : public Command
	{
	public:
		void Execute() override { std::cout << "Player Crouched!\n"; }
		void Undo() override { std::cout << "Undo Player Crouch!\n"; }
	};

	class SwapGunCommand final : public Command
	{
	public:
		void Execute() override { std::cout << "Player Swapped Gun!\n"; }
		void Undo() override { std::cout << "Undo Player Swap Gun!\n"; }
	};

	class DecreaseHealthCommand final : public Command
	{
	public:
		DecreaseHealthCommand(std::shared_ptr<GameObject> pGameObject) : Command{}, linkedGameObject{ pGameObject } {}

		void Execute() override 
		{ 
			auto healthComp = linkedGameObject->GetComponent<HealthComponent>();
			if (healthComp)
				healthComp->DecreaseLife();
		}
		void Undo() override 
		{ 
			auto healthComp = linkedGameObject->GetComponent<HealthComponent>();
			if (healthComp)
				healthComp->IncreaseLife();
		}

	private:
		std::shared_ptr<GameObject> linkedGameObject{ nullptr };
	};

	class IncreasePointsCommand final : public Command
	{
	public:
		IncreasePointsCommand(std::shared_ptr<GameObject> pGameObject) : Command{}, linkedGameObject{ pGameObject } {}

		void Execute() override 
		{ 
			auto pointsComp = linkedGameObject->GetComponent<PointsComponent>();
			if (pointsComp)
				pointsComp->AddPoints(10);
		}
		void Undo() override 
		{ 
			auto pointsComp = linkedGameObject->GetComponent<PointsComponent>();
			if (pointsComp)
				pointsComp->DecreasePoints(10);
		}

	private:
		std::shared_ptr<GameObject> linkedGameObject{ nullptr };
	};

	class PlaySound final : public Command
	{
	public:
		void Execute() override
		{
			ServiceLocator::GetSoundSystem().PlaySound(0, 1);
		}
		void Undo() override {}
	};

	class MoveForward final : public Command
	{
	public:
		MoveForward(std::shared_ptr<GameObject> gameObject) : Command{}, linkedGameObject{gameObject}
		{
			transformComp = gameObject->GetComponent<TransformComponent>();
		}

		void Execute() override
		{
			if (transformComp == nullptr)
				transformComp = linkedGameObject->GetComponent<TransformComponent>();
			else
			{
				prevPos = transformComp->GetPosition();
				glm::vec3 newPos = prevPos;
				newPos.y -= linkedGameObject->GetComponent<TronTankComponent>()->GetTankSpeed() * transformComp->GetElapsedSec();
				transformComp->SetPosition(newPos.x, newPos.y, newPos.z);
			}
		}
		void Undo() override {}

	private:
		std::shared_ptr<GameObject> linkedGameObject{ nullptr };
		std::shared_ptr<TransformComponent> transformComp{ nullptr };
		glm::vec3 prevPos{};
	};

	class MoveBackward final : public Command
	{
	public:
		MoveBackward(std::shared_ptr<GameObject> gameObject) : Command{}, linkedGameObject{ gameObject }
		{
			transformComp = gameObject->GetComponent<TransformComponent>();
		}

		void Execute() override
		{
			if (transformComp == nullptr)
				transformComp = linkedGameObject->GetComponent<TransformComponent>();
			else
			{
				prevPos = transformComp->GetPosition();
				glm::vec3 newPos = prevPos;
				newPos.y += linkedGameObject->GetComponent<TronTankComponent>()->GetTankSpeed() * transformComp->GetElapsedSec();
				transformComp->SetPosition(newPos.x, newPos.y, newPos.z);
			}
		}
		void Undo() override {}

	private:
		std::shared_ptr<GameObject> linkedGameObject{ nullptr };
		std::shared_ptr<TransformComponent> transformComp{ nullptr };
		glm::vec3 prevPos{};
	};

	class MoveLeft final : public Command
	{
	public:
		MoveLeft(std::shared_ptr<GameObject> gameObject) : Command{}, linkedGameObject{ gameObject }
		{
			transformComp = gameObject->GetComponent<TransformComponent>();
		}

		void Execute() override
		{
			if (transformComp == nullptr)
				transformComp = linkedGameObject->GetComponent<TransformComponent>();
			else
			{
				prevPos = transformComp->GetPosition();
				glm::vec3 newPos = prevPos;
				newPos.x -= linkedGameObject->GetComponent<TronTankComponent>()->GetTankSpeed() * transformComp->GetElapsedSec();
				transformComp->SetPosition(newPos.x, newPos.y, newPos.z);
			}
		}
		void Undo() override {}

	private:
		std::shared_ptr<GameObject> linkedGameObject{ nullptr };
		std::shared_ptr<TransformComponent> transformComp{ nullptr };
		glm::vec3 prevPos{};
	};

	class MoveRight final : public Command
	{
	public:
		MoveRight(std::shared_ptr<GameObject> gameObject) : Command{}, linkedGameObject{ gameObject }
		{
			transformComp = gameObject->GetComponent<TransformComponent>();
		}

		void Execute() override
		{
			if (transformComp == nullptr)
				transformComp = linkedGameObject->GetComponent<TransformComponent>();
			else
			{
				prevPos = transformComp->GetPosition();
				glm::vec3 newPos = prevPos;
				newPos.x += linkedGameObject->GetComponent<TronTankComponent>()->GetTankSpeed() * transformComp->GetElapsedSec();
				transformComp->SetPosition(newPos.x, newPos.y, newPos.z);
			}
		}
		void Undo() override {}

	private:
		std::shared_ptr<GameObject> linkedGameObject{ nullptr };
		std::shared_ptr<TransformComponent> transformComp{ nullptr };
		glm::vec3 prevPos{};
	};
}


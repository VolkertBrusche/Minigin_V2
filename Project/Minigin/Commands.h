#pragma once
#include <iostream>
#include "Scene.h"
#include "GameObject.h"

//Compontents
#include "HealthComponent.h"
#include "PointsComponent.h"

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
}


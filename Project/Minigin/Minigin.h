#pragma once
#include <memory>

struct SDL_Window;
struct SDL_Color;
namespace dae
{
	class Scene;
	class Font;
	class GameObject;
	class Minigin
	{
	public:
		void Initialize();
		void LoadGame() const;
		void Cleanup();
		void Run();
	private:
		void CreateBackground() const;
		void CreateFPSCounter() const;
		void TestParenting() const;
		void TestInput() const;
		void TestObserverAndSubject() const;
		std::shared_ptr<GameObject> CreateHealthWithText(std::shared_ptr<Scene> scene, int maxLives, std::shared_ptr<Font> textFont, SDL_Color textColor, float xPosText, float yPosText) const;
		std::shared_ptr<GameObject> CreatePointsWithText(std::shared_ptr<Scene> scene, std::shared_ptr<Font> textFont, SDL_Color textColor, float xPosText, float yPosText) const;

		static const int MsPerFrame = 16; //16 for 60 fps, 33 for 30 fps
		float m_TimeStamp = 0.02f; //Fixed timestamp for FixedUpdate() (default from UnityEngine)
		SDL_Window* m_Window{};
	};
}
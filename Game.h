#pragma once
# include <iostream>
# include <vector>
# include <ctime>

# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>

using namespace std;
using namespace sf;

// Class that acts as the game engine
//CTRL . to create functions in game.cpp file



class Game
{	
	private:
		// Variables

		
		//Window
		RenderWindow* window;
		VideoMode videoMode;
		Event ev;

		//Mouse positions
		Vector2i mousePosWindow;
		Vector2f mousePosView;

		// Game Logic
		float gravityConst;
		float gravity;
		float speed;
		float dy;
		int spawnX;
		float enemySize = 20;
		int enWidth = 0;
		int points;
		float enemySpawnTimer;
		float enemySpawnTimerMax;
		int maxEnemies;




		// Game objects
		vector<RectangleShape> enemies;
		RectangleShape enemy;

		void initVariables();
		void initWindow();
		void initEnemies();


	public:
		// Constructors / Destructors
		Game();
		virtual ~Game();

		//Accessors
		const bool running() const;

		//Functions
		void spawnEnemy();

		void pollEvents();
		void updateMousePositions();
		void updateEnemies();
		void update();

		void renderEnemies();
		void render();

};


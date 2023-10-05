#include "Game.h"

const int SCREENHEIGHT = 800;
const int SCREENWIDTH = 1200;


// Private Functions

void Game::initVariables()
{
	this->window = nullptr;

	// Game logic
	this->gravityConst = 9.8f;
	this->speed = 0.05f;
	this->gravity = gravityConst * speed;
	//this->dy = 0;
	this->spawnX = 0;
	this->enWidth = 0;
	this->points = 0;
	this->enemySpawnTimerMax = 75.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 250;
	
}

void Game::initWindow()
{
	this->videoMode.height = SCREENHEIGHT;
	this->videoMode.width = SCREENWIDTH;
	//this->videoMode.getDesktopMode; // sets to resolution of user
	//this->videoMode.getFullscreenModes; // full screen
	this->window = new RenderWindow(this->videoMode, "Falling Blocks", Style::Titlebar | Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
	
	//this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(Vector2f(enemySize, enemySize));
	this->enemy.setScale(Vector2f(1.f, 1.f));
	this->enemy.setFillColor(Color(0,255,255,255));
	this->enemy.setOutlineColor(Color::Green);
	this->enemy.setOutlineThickness(0.f);

}

//Constructors / Destructors

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();

}

Game:: ~Game()
{
	//avoid memory leak
	delete this->window;
}


//Accessors

const bool Game::running() const
{
	return this->window->isOpen();
}

//Functions

void Game::spawnEnemy()
{


	enWidth = this->enemy.getSize().x;
	spawnX = rand()%(SCREENWIDTH - enWidth);
	enemySize = (rand() % 150),
	this->dy = (rand()%35)*-1;
	this->enemy.setSize(Vector2f(enemySize, enemySize));


	this->enemy.setPosition(

		spawnX,
		//static_cast<float>(rand()&(static_cast<int>(rand()%SCREENWIDTH - this->enemy.getSize().x))),
		//static_cast<float>(rand()&(static_cast<int>(SCREENWIDTH - this->enemy.getSize().x))),
		 //static_cast<float>(rand() & static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
		SCREENHEIGHT - 200

	);

	this->enemy.setFillColor(Color(rand()%256, rand()%256, rand()%256, 255));
	this->enemies.push_back(this-> enemy);
		 
	

}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev)) {

		switch (this->ev.type) {

		case Event::Closed:
			this->window->close();
			break;

		case Event::KeyPressed:

			if (this->ev.key.code == Keyboard::Escape);
			this->window->close();
			break;

		}


	}
}

void Game::updateMousePositions()
{
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies()
{

	//updating the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies) {

		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//spawn the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
		{
			this->enemySpawnTimer += 1.f;
		}

	}	

	// update enemy speed
	this->dy = this->dy + gravity;

	//this->dy = this->dy + gravity;

	for (int i = 0; i < this->enemies.size(); i++)


	{
		
		if (this->enemies[i].getPosition().y < SCREENHEIGHT - 100 - (this->enemies[i].getSize().y)) {
		
			this->enemies[i].move(0.f, this->dy);
			
		}


		else {
			this->enemies[i].setPosition(this->enemies[i].getPosition().x, SCREENHEIGHT - 100 - (this->enemies[i].getSize().y));
		}


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {


				this->enemies.erase(this->enemies.begin() + i);

			}
		}





	}


}

void Game::update()
{


	this->pollEvents();

	
	this->updateMousePositions();

	this->updateEnemies();



    //relative to screen
	//cout << "mousepos: " << Mouse::getPosition().x << " " << Mouse::getPosition().y << endl;
	//relative to the window
	//cout << "mousepos: " << Mouse::getPosition(*this->window).x << " " << Mouse::getPosition(*this->window).y << endl;

}

void Game::renderEnemies()
{
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}

}

void Game::render()
{
	this->window->clear(Color(0, 0, 0, 255));

	//draw game objects

	this->renderEnemies();


	//render
	this->window->display();

}


# include <iostream>
# include <vector>
# include <ctime>


# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>

# include "animation.h"
# include "widgets.h"

int main()
{
	
	//Animation animation(&playerTexture, sf::Vector2u(3, 9), 0.3f);
	bool mouseClicked = false;

	//sf::RenderWindow window(sf::VideoMode(512, 512), "Name of Window", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::RenderWindow window(sf::VideoMode(1800, 900), "Name of Window", sf::Style::Default);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	//player.setFillColor(sf::Color::Green);
	player.setOrigin(50.0f, 50.0f);
	player.setPosition(250, 250);
	sf::Texture playerTexture;
	sf::Texture buttonTexture;
	sf::Texture buttonHighlightTexture;

	sf::Vector2f buttonPos(40,40);
	sf::Vector2f button2Pos(40, 100);

	playerTexture.loadFromFile("Assets/player sprite sheet.png");
	buttonTexture.loadFromFile("Assets/button.png");
	buttonHighlightTexture.loadFromFile("Assets/button_highlighted.png");

	player.setTexture(&playerTexture);
	

	sf::Vector2u textureSize = playerTexture.getSize();
	textureSize.x /= 13;
	textureSize.y /= 21;

	
	Button button1(&buttonTexture, buttonPos);
	Button button2(&buttonTexture, button2Pos);

	Animation animation(&playerTexture, sf::Vector2u(13, 21), 0.3f);

	float deltaTime = 0.0f;
	sf::Clock clock;



	sf::Vector2i mousePos = sf::Mouse::getPosition(window);


	while (window.isOpen())
	{

		mouseClicked = false;

		deltaTime = clock.restart().asSeconds();



		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break; 
			case sf::Event::Resized:
				window.setView(sf::View(sf::FloatRect(0, 0, evnt.size.width, evnt.size.height)));
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128)
				{
					printf("%c", evnt.text.unicode);
				}
			}

		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			mouseClicked = true;
			//std::cout << "Hellz Bellz";
		}
		else {
			mouseClicked = false;
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V))
		{
			button1.Highlight(&buttonHighlightTexture);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C))
		{
			button1.Highlight(&buttonTexture);
		}

		mousePos = sf::Mouse::getPosition(window);

		//animation.Update(0, deltaTime);
		
		button1.CheckForHighlighting(&buttonTexture, &buttonHighlightTexture, mousePos);
		button2.CheckForHighlighting(&buttonTexture, &buttonHighlightTexture, mousePos);

		//player.setTextureRect(animation.uvRect);

		window.clear();
		window.draw(button1.rect);
		window.draw(button2.rect);
		//window.draw(player);
		window.display();

		if (mouseClicked == true)
		{
			std::cout << "Hellz Bellz" << '\n';
		}


	}



	return 0;
}

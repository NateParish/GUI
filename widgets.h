#pragma once
# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>

class Button
{
public:

	sf::RectangleShape rect;

	Button(sf::Texture* buttonTexture, sf::Vector2f buttonPos);
	~Button();

	void Highlight(sf::Texture* buttonTexture);
	void CheckForHighlighting(sf::Texture* buttonTexture, sf::Texture* buttonHighlightTexture, sf::Vector2i buttonPos);

private:


};


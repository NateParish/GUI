#include "widgets.h"
#include <iostream>


Button::Button(sf::Texture* buttonTexture, sf::Vector2f buttonPos) 
{	

	this->rect.setTexture(buttonTexture);
	rect.setPosition(buttonPos.x, buttonPos.y);
	rect.setSize(sf::Vector2f(252, 53));

}

Button::~Button() {

}

void Button::Highlight(sf::Texture* buttonTexture)
{

	this->rect.setTexture(buttonTexture);

}

void Button::CheckForHighlighting(sf::Texture* buttonTexture, sf::Texture* buttonHighlightTexture, sf::Vector2i buttonPos)
{

	sf::Vector2f size = rect.getSize();
	sf::Vector2f origin = rect.getPosition();

	this->rect.setTexture(buttonTexture);

	if (buttonPos.x > rect.getPosition().x)
	{
		if (buttonPos.x < rect.getPosition().x + size.x)
		{
			if (buttonPos.y > rect.getPosition().y)
			{
				if (buttonPos.y < rect.getPosition().y + size.y)
				{
					this->rect.setTexture(buttonHighlightTexture);
					//highlight = true;
				}
			}
		}
	}

	
}
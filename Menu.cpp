// GROUP C
// Chase Huante, Shaochen Ren, Gregory Pytak, Keerthi Thummati, Ankur Prajapati
#include "Menu.h"
#include<iostream>
using namespace std;

// =================================== DESIGNING THE MENU ================================================================
// Menu function to open arial file and create the menu options 
Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "Cannot find arial.ttf file, please try again";
	}
	
	// Option 1 for Tetris, below is font, color, name, and the math behind the option
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("TETRIS");
	menu[0].setPosition(sf::Vector2f(width / 2.65, height / (OPTIONS + 2) * 1));

	// Option 2 for Sudoku, below is font, color, name, and the math behind the option
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("SUDOKU");
	menu[1].setPosition(sf::Vector2f(width / 2.8, height / (OPTIONS + 2) * 2));

	// Option 3 to exit, below is font, color, name, and the math behind the option
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("EXIT");
	menu[2].setPosition(sf::Vector2f(width / 2.3, height / (OPTIONS + 2) * 3));
	selectedItemIndex = 0;
}

// Deconstructor
Menu::~Menu() {

}

// =================================  MOVING THE KEYS UP AND DOWN  ======================================================
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < OPTIONS; i++)
	{
		window.draw(menu[i]);
	}
}
// function to move up
void Menu::moveUp() {
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
// function to move down
void Menu::moveDown() {
	if (selectedItemIndex + 1 < OPTIONS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

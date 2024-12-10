#include <SFML/Graphics.hpp>
#include <iostream>
#include "Car.h"
#include "Traffic.h"
#include "main.h"
using namespace std;

float getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<float>(rand() * fraction * (max - min + 1) + min);
}

int main() {
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(60);

    sf::CircleShape shape(10.f);

	Car my_car(1, 0, 0, 0, 0, 0, 0);
    
    // Run the program as long as the window is open
    while (window.isOpen())
    {
        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window with black colour
        window.clear(sf::Color::Black);

		float x = getRandomNumber(0, 800);
		float y = getRandomNumber(0, 600);

		cout << "x: " << x << " y: " << y << endl;
        
		shape.setPosition(x, y);

        window.draw(shape);

        // End the current frame
        window.display();
    }

    return 0;
}

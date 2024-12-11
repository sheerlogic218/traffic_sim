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

struct Tile {
    sf::RectangleShape shape;
    int x = 0;
    int y = 0;
	bool isRoad = false;
};

sf::Vector2u WINDOW_SIZE{ 1000, 800 };
constexpr unsigned TPS = 60;
const sf::Time timePerUpdate = sf::seconds(1.0f / float(TPS));
sf::Vector2f TILE_SIZE{ 16.f, 16.f };

const sf::Color GRASS_COLOR{ 124, 252, 0, 45 };
const sf::Color ROAD_COLOR{ 105, 105, 105, 45 };

constexpr int FRAMERATE = 240;

int main() {
    sf::RenderWindow window{ sf::VideoMode{WINDOW_SIZE.x,WINDOW_SIZE.y},"" };
    window.setFramerateLimit(FRAMERATE);
    window.setPosition(sf::Vector2i{ window.getPosition().x, 0 });
    window.setTitle("Traffic Simulator");

    sf::View view = window.getDefaultView();

    vector<vector<Tile>> doubleTileMap;
    for (int y = 0; y < WINDOW_SIZE.y / TILE_SIZE.y; y++) {
        for (int x = 0; x < WINDOW_SIZE.x / TILE_SIZE.x; x++) {
            doubleTileMap.emplace_back();
            Tile* tile = new Tile();

			tile->x = x;
			tile->y = y;

            tile->shape.setSize({ TILE_SIZE.x, TILE_SIZE.y });
            tile->shape.setFillColor(GRASS_COLOR);
            /*tile->shape.setOutlineThickness(0.5f);
            tile->shape.setOutlineColor({ sf::Color::White });*/
            tile->shape.setPosition(x * TILE_SIZE.x, y * TILE_SIZE.y);
            doubleTileMap[y].push_back(*tile);
        }
    }

    sf::CircleShape car(10.f);

    Car my_car(1, 500, 400, 0, 0, 0, 0);
    my_car.set_throttle(0.1);
	my_car.set_steering_angle(0.1);

    while (window.isOpen()) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePos, view);

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Enter: cout << "Enter Pressed\n"; break;
                    case sf::Keyboard::Space: cout << "Space Pressed\n"; break;
                    default: break;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (mouseWorldPos.x >= 0 && mouseWorldPos.y >= 0 && mouseWorldPos.x < WINDOW_SIZE.x && mouseWorldPos.y < WINDOW_SIZE.y) {
                    sf::Vector2i position = mousePos;

                    position.x /= static_cast<int>(TILE_SIZE.x);
                    position.y /= static_cast<int>(TILE_SIZE.y);

                    Tile tile = doubleTileMap[position.y][position.x];
                    switch (event.mouseButton.button) {
                    case sf::Mouse::Left: {
                        tile.shape.setFillColor(ROAD_COLOR);
                        tile.isRoad = true;
                        break;
                    }
                    case sf::Mouse::Right: {
                        tile.shape.setFillColor(GRASS_COLOR);
                        tile.isRoad = false;
                        break;
                    default: break;
                    }
                    }
                }
            }
        }

        my_car.update_pos();
        

        float x = my_car.get_x();
        float y = my_car.get_y();

        float vx = my_car.get_vx();
        float vy = my_car.get_vy();

        car.setPosition(x, y);

		// Log acceleration
		cout << "Acceleration: " << my_car.get_ax() << ", " << my_car.get_ay() << endl;
        // Log direction
		cout << "Direction: " << my_car.get_direction() << endl;

        window.clear();

        for (vector<Tile>& index : doubleTileMap) {
            for (Tile& tile : index) {
                window.draw(tile.shape);
            }
        }

        window.draw(car);

        window.setView(window.getDefaultView());

        window.display();
    }
    return EXIT_SUCCESS;
}

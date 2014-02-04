#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include  <SFML/Window.hpp>

sf::ConvexShape drawShip();

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    //window.setFramerateLimit(80);
    ////////////////////////////////////////////////////////////////////
    sf::ConvexShape ship = drawShip();
    float rotation = 0;
    int x = 0, y = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            ship.setRotation(rotation -= 2);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            ship.setRotation(rotation += 2);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            ship.setPosition(x++, y++);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            ship.setPosition(x--, y--);
        if (x < 0 && y < 0)
        {
            x = 500, y = 500;
            ship.setPosition(x, y);
        }
        if (x > 500 && y > 500)
        {
            x = 0, y = 0;
            ship.setPosition(x, y);
        }

        window.clear();
        window.draw(ship);
        window.display();
    }

    return 0;
}

sf::ConvexShape drawShip()
{
    sf::ConvexShape ship;

    ship.setPointCount(3);
    ship.setPoint(0, sf::Vector2f(4, 0));
    ship.setPoint(1, sf::Vector2f(0, 10));
    ship.setPoint(2, sf::Vector2f(8, 10));

    sf::Vector2f midpoint(5, 10);
    ship.setOrigin(midpoint);

    ship.setRotation(45);
    ship.setPosition(4, 10);

    ship.setFillColor(sf::Color(0, 0, 0));
    ship.setOutlineThickness(1);
    ship.setOutlineColor(sf::Color(255, 255, 255));

    return ship;
}

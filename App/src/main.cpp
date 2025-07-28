#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>

// Function prototypes
void centerTheWindow(sf::RenderWindow& window);

/**
 * @brief OCIRA main program.
 *
 * @return Returns 0 when execution completes succesfully.
 */
int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "OCIRA 0.1.0 - 20250728");
    window.setFramerateLimit(30);
    centerTheWindow(window);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        window.display();
    }
}

/**
 * @brief Takes sf::RenderWindow as input and centers it on the screen.
 */
void centerTheWindow(sf::RenderWindow& window)
{
    // Get desktop video mode (screen resolution)
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Calculate the center position of the screen
    sf::Vector2i screenCenter(desktopMode.size.x / 2, desktopMode.size.y / 2);

    // Calculate the top-left corner position of the window to center it
    sf::Vector2i windowPosition(screenCenter.x - window.getSize().x / 2,
                                screenCenter.y - window.getSize().y / 2);

    // Set the window's position
    window.setPosition(windowPosition);
}
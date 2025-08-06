#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>

// Function prototypes
void centerTheWindow(sf::RenderWindow &window);

/**
 * @brief OCIRA main program.
 *
 * @return Returns 0 when execution completes succesfully.
 */
int main() {
  sf::RenderWindow window(sf::VideoMode({1920, 1080}), "OCIRA 0.1.0 - 20250806");
  window.setFramerateLimit(30);
  centerTheWindow(window);

  sf::Vector2u minSize(1280, 720); // min window size

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      // Window close event.
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    // clear the window with black color
    window.clear(sf::Color::Black);

    // Define two points
    sf::Vertex line[] = {sf::Vertex({sf::Vector2f(100.f, 100.f), sf::Color::Yellow}),
                         sf::Vertex({sf::Vector2f(1000.f, 100.f), sf::Color::Yellow}),
                         sf::Vertex({sf::Vector2f(1000.f, 700.f), sf::Color::Yellow}),
                         sf::Vertex({sf::Vector2f(100.f, 700.f), sf::Color::Yellow})};

    window.draw(line, 4, sf::PrimitiveType::Lines);

    window.display();
  }
}

/**
 * @brief Takes sf::RenderWindow as input and centers it on the screen.
 */
void centerTheWindow(sf::RenderWindow &window) {
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
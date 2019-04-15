#include "Game.h"

using namespace sf;
using namespace std;

const int Fx = 11, Fy = 11;

int Field[Fx][Fy] = {

	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

};

Game::Game()
{
	RenderWindow window(VideoMode(1280, 1280), "Gra", Style::Fullscreen);
	View view = window.getView();


	// <- Kratka ->
	krat.loadFromFile("Image\\kratka.png");
	krat.setRepeated(true);
	kratka.setTexture(krat);
	//kratka.setOrigin(Kratka / 2, Kratka / 2);
	kratka.setTextureRect({ 0, 0, Mx, My });

	// <- Kursor ->
	t.loadFromFile("Image\\Kursor.png");
	t.setSmooth(true);
	kursor.setTexture(t);
	kursor.setOrigin(Kratka / 2, Kratka / 2);
	kursor.setPosition(Mx / 2, My / 2);

	// <- Mapa ->
	texture.loadFromFile("Background\\map1.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);

	// <- Menu ->
	m.loadFromFile("Image\\menu.png");
	menu.setTexture(m);
	menu.setPosition(0, 100);

	// <- T³o ->
	back1.loadFromFile("Background\\Background.png");
	back1.setSmooth(true);
	back1.setRepeated(true);

	back2.loadFromFile("Background\\Background2.png");
	back2.setSmooth(true);
	back2.setRepeated(true);

	background.setOrigin(Mx / 2, My / 2);
	background.setPosition(-1.5*Mx, -1.5*My);
	background.setTextureRect({ 0, 0, 5 * Mx, 5 * My });

	background.setTexture(back1);

	// <- Ramka ->
	border1.loadFromFile("Background\\Border.png");
	border1.setRepeated(true);
	border2 = border1;
	border2.loadFromFile("Background\\Border2.png");
	Border.setPosition(-16, -16);
	Border.setTextureRect({ 0, 0, Mx + 32, My + 32 });
	Border.setTexture(border1);


	Clock clock;
	Time time;

	//cout << time.asSeconds() << endl;


	bool isVisible = false;
	bool backgroundSwitch = true;

	/*unsigned int size = 200; // The 'minimap' view will show a smaller picture of the map
	sf::View minimap(sf::FloatRect(view.getCenter().x, view.getCenter().y, static_cast<float>(size), static_cast<float>(window.getSize().y*size / window.getSize().x)));
	minimap.setViewport(sf::FloatRect(1.f - static_cast<float>(minimap.getSize().x) / window.getSize().x - 0.02f, 1.f - static_cast<float>(minimap.getSize().y) / window.getSize().y - 0.02f, static_cast<float>(minimap.getSize().x) / window.getSize().x, static_cast<float>(minimap.getSize().y) / window.getSize().y));
	minimap.zoom(4.f);

	sf::RectangleShape miniback; // We want to draw a rectangle behind the minimap
	miniback.setPosition(minimap.getViewport().left*window.getSize().x - 5, minimap.getViewport().top*window.getSize().y - 5);
	miniback.setSize(sf::Vector2f(minimap.getViewport().width*window.getSize().x + 10, minimap.getViewport().height*window.getSize().y + 10));
	miniback.setFillColor(sf::Color(160, 8, 8));*/




	while (window.isOpen())
	{
		//clock.restart();
		time = clock.getElapsedTime();
		float timer = time.asSeconds();
		int timer2 = time.asSeconds();
		int timer3;
		//cout << timer << endl;

		window.setMouseCursorVisible(false);
		//window.setFramerateLimit(60);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();

			if (event.type == Event::KeyPressed)
			{

				if (kursor.getPosition().x > Kratka && (event.key.code == Keyboard::Left))
				{
					kursor.move(-Kratka, 0); //background.move(-Kratka, 0); 
					cout << kursor.getPosition().x / Kratka + 0.5 << ", " << kursor.getPosition().y / Kratka + 0.5 << endl;
				}
				else if (kursor.getPosition().x < Mx - Kratka && (event.key.code == Keyboard::Right))
				{
					kursor.move(Kratka, 0); //background.move(Kratka, 0);
					cout << kursor.getPosition().x / Kratka + 0.5 << ", " << kursor.getPosition().y / Kratka + 0.5 << endl;
				}
				else if (kursor.getPosition().y > Kratka && (event.key.code == Keyboard::Up))
				{
					//if (kursor.getPosition().y / Kratka + 0.5 < 4 && view.getCenter().y > 512-128) dCy -= 128;
					kursor.move(0, -Kratka); //background.move(0, -Kratka);
					cout << kursor.getPosition().x / Kratka + 0.5 << ", " << kursor.getPosition().y / Kratka + 0.5 << endl;
				}
				else if (kursor.getPosition().y < My - Kratka && (event.key.code == Keyboard::Down))
				{
					//if (kursor.getPosition().y / Kratka + 0.5 > 8 && view.getCenter().y < My - 512+128) dCy += 128;
					kursor.move(0, Kratka); //background.move(0, Kratka); 
					cout << kursor.getPosition().x / Kratka + 0.5 << ", " << kursor.getPosition().y / Kratka + 0.5 << endl;
				}

				if (Keyboard::isKeyPressed(Keyboard::A) && view.getCenter().x > 512) dCx -= 64;
				else if (Keyboard::isKeyPressed(Keyboard::D) && view.getCenter().x < Mx - 512) dCx += 64;
				else if (Keyboard::isKeyPressed(Keyboard::W) && view.getCenter().y > 512) dCy -= 64;
				else if (Keyboard::isKeyPressed(Keyboard::S) && view.getCenter().y < My - 320) dCy += 64;



			}
			//cout << 10 * pow(sin(timer), 2) << endl;

					
			if (event.type == sf::Event::KeyReleased)
			{
				// <- W³¹czanie/wy³¹czanie siatki ->
				if (event.key.code == sf::Keyboard::R) isVisible = !isVisible;

				// <- Zmiana t³a ->
				if (event.key.code == sf::Keyboard::M) backgroundSwitch = !backgroundSwitch;

			}
		}






		
		
		/*if (Keyboard::isKeyPressed(Keyboard::LShift)) speed = 2;
		else speed = 1;
		if (Keyboard::isKeyPressed(Keyboard::A) && kursor.getPosition().x > 0)
		{
			kursor.move(-1 * speed, 0);
			menu.move(-1 * speed, 0);
			if (int(kursor.getPosition().x) % 64 == 0) cout << kursor.getPosition().x << ", " << kursor.getPosition().y << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::D) && kursor.getPosition().x < 1152)
		{
			kursor.move(1 * speed, 0);
			menu.move(1 * speed, 0);
			if (int(kursor.getPosition().x) % 64 == 0) cout << kursor.getPosition().x << ", " << kursor.getPosition().y << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::S) && kursor.getPosition().y < 1152)
		{
			kursor.move(0, 1 * speed);
			menu.move(0, 1 * speed);
			if (int(kursor.getPosition().y) % 64 == 0) cout << kursor.getPosition().x << ", " << kursor.getPosition().y << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::W) && kursor.getPosition().y > 0)
		{
			kursor.move(0, -1 * speed);
			menu.move(0, -1 * speed);
			if (int(kursor.getPosition().y) % 64 == 0) cout << kursor.getPosition().x << ", " << kursor.getPosition().y << endl;
		}
		//Sleep(1);*/

		// <- Przyblizanie/oddalanie ->
		if (Keyboard::isKeyPressed(Keyboard::Q) && (Q > 1))
		{
			Q -= 0.001;
			view.zoom(0.9985f);
			menu.scale(0.9985f, 0.9985f);
			//view.setCenter(Mx - Q * Q, My);
			cout << Q << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::E) && (Q <= 1.3))
		{
			Q += 0.001;
			view.zoom(1.0015f);
			menu.scale(1.0015f, 1.0015f);
			//view.setCenter(Mx / Q, My);

			cout << Q << endl;
		}




		if (backgroundSwitch) { background.setTexture(back1); Border.setTexture(border1); }
		else { background.setTexture(back2); Border.setTexture(border2); }

		view.setCenter(Mx/2 + dCx, My/2 + dCy);
		window.setView(view);
		window.clear(sf::Color(0, 0, 0));
		window.draw(background);
		window.draw(Border);
		window.draw(sprite);
		if (!isVisible)
		{
			window.draw(kratka);
		}
		window.draw(kursor);
		//window.draw(menu);
	

		window.display();
	}

}

Game::~Game()
{
}

/*
void Game::Move(int x, int y)
{
	int X, Y;

	for (int i = 0; i < x; i++)
	{
		X = kursor.getPosition().x;
		Y = kursor.getPosition().y;
		for (int j = 0; j < x; j++)
		{
			Field[X][Y];
			kursor.setPosition(X + x * Field[i][j], Y + y * j);
		}
	}
}
*/
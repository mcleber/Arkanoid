#include <SFML/Graphics.hpp>
#include <time.h>
//#include <tchar.h>
#include <string>

int main()
{
//	_tsetlocale(LC_ALL, _T("portuguese"));

	srand(time(0));

	int score{ 0 }, balls{ 3 }; // pontuação e quantidade de bolas

	/* Definindo o tamanho da janela */
	sf::RenderWindow app(sf::VideoMode(520, 500), "Arkanoid");
	app.setFramerateLimit(60); // 60 fps

	/* Ícone na janela */
	sf::Image icon;
	icon.loadFromFile("arkanoid/arkanoid-logo.png");
	app.setIcon(520, 517, icon.getPixelsPtr());

	/* Textos - Fonte e formatação */
	sf::Font font1;
	font1.loadFromFile("arkanoid/Arka_solid.ttf"); 

	sf::Font font2;
	font2.loadFromFile("arkanoid/alienleagueexpand.ttf");

	sf::Text text1("", font2); // score
	text1.setString("SCORE:");
	text1.setCharacterSize(24);
	text1.setPosition(270, 05);
	text1.setFillColor(sf::Color::White);

	sf::Text text2("", font2); // resultado
	text2.setString(std::to_string(score));
	text2.setCharacterSize(24);
	text2.setPosition(340, 05);
	text2.setFillColor(sf::Color::White); // Branco é o padrão se não declarar

	sf::Text text3("", font2); // balls
	text3.setString("BALLS:");
	text3.setCharacterSize(24);
	text3.setPosition(410, 05);
	text3.setFillColor(sf::Color::Red);

	sf::Text text4("", font2); // quantidade de bolas
	text4.setString(std::to_string(balls));
	text4.setCharacterSize(24);
	text4.setPosition(485, 05);
	text4.setFillColor(sf::Color::Red);
	
	sf::Text text5("", font1); // game over
	text5.setString("GAME OVER");
	text5.setCharacterSize(60);
	text5.setPosition(-260, -250); // valor negativo para esconder fora da área do jogo a frase GAME OVER
	text5.setFillColor(sf::Color::Red);

	sf::Text text6("", font1); // venceu
	text6.setString("YOU WIN");
	text6.setCharacterSize(60);
	text6.setPosition(-260, -250);
	text6.setFillColor(sf::Color::Red);

	sf::Text text7("", font1); // Arkanoid
	text7.setString("ARKANOID");
	text7.setCharacterSize(24);
	text7.setPosition(10, 07);
	text7.setFillColor(sf::Color::White);

	sf::Text text8("", font2); // Press Enter
	text8.setString("Press Enter");
	text8.setCharacterSize(24);
	text8.setPosition(20, 400);
	text8.setFillColor(sf::Color::White);

	sf::Text text9("", font2); // Press Space
	text9.setString("Press Space");
	text9.setCharacterSize(20);
	text9.setPosition(200, 300);
	text9.setFillColor(sf::Color::White);

	/* Area para mostrar o score */
	sf::RectangleShape retangule;
	retangule.setFillColor(sf::Color::Blue);
	retangule.setSize(sf::Vector2f(520, 40));
	retangule.setPosition(0, 0);

	/* Bola */
	sf::CircleShape ball;
	ball.setFillColor(sf::Color::Blue);
	ball.setRadius(7);
	ball.setOutlineColor(sf::Color::Cyan);
	ball.setOutlineThickness(2); // espessura da borda
	
	float dx{ 0 };
	float dy{ 0 };
	float x{ 320 }; // posição de inicialização da bola no eixo x
	float y{ 390 }; // posição de inicialização da bola no eixo y
	

	/* Carrega textura do paddle e blocos e intro */
	sf::Texture texture1, texture2, texture3;
	texture1.loadFromFile("arkanoid/paddle.png");
	texture2.loadFromFile("arkanoid/block01.png");
	texture3.loadFromFile("arkanoid/arkanoid-logo.png");

	sf::Sprite Paddle(texture1);
	Paddle.setPosition(250, 480); // posição do paddle

	/* Blocos */
	sf::Sprite blocks[1000];

	int num = 0;
	for (int i = 1; i <= 10; i++ ) // Ajusta posição dos blocos em x
		for (int j = 3; j <= 12; j++) // Ajusta a posição dos blocos em y
		{
			blocks[num].setTexture(texture2);
			blocks[num].setPosition(i * 43, j * 22);
			num++;
		}

	/* Tela de logo */
//	sf::Texture texture3;
	sf::Sprite ArkanoirLogo(texture3);

	sf::Clock clock;

	/* Abre janela */
	while (app.isOpen())
	{
		sf::Event event;
		while (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				app.close();
		}

		/* Start - Faz o Texto Press Start Brilhar */
		if (clock.getElapsedTime().asSeconds() > 0.10f)
		{
			text8.setFillColor(sf::Color::White);
		}
		
		if (clock.getElapsedTime().asSeconds() > 0.5f)
		{
			text8.setFillColor(sf::Color::Transparent);
		}

		if (clock.getElapsedTime().asSeconds() > 1.1f)
		{
			text8.setFillColor(sf::Color::White);
			clock.restart();
		}

		/* Instrucao inicial */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			ArkanoirLogo.setPosition(-800, -800); // retira/desloca para fora da area do jogo
			text8.setPosition(-800, -800); // desloca o Press Enter
		}

		/* Movimento da bola */
		ball.setPosition(x, y);
		x += dx;

		for (int i = 0; i < num; i++)
		{
			if (sf::FloatRect(x + 3, y + 3, 6, 6).intersects(blocks[i].getGlobalBounds())) // x e y 3 é um retângulo dentro da bola. O retângulo que colide com os blocos
			{
				score += 10; // Cada colisão com o bloco adiciona 10
				text2.setString(std::to_string(score)); // atualiza constantemente sempre que estiver no loop
				blocks[i].setPosition(-100, 0); // posiciona o block fora da área de jogo
				dx = -dx;
			}
		}

		y += dy;
		for (int i = 0; i < num; i++)
		{
			if (sf::FloatRect(x + 3, y + 3, 6, 6).intersects(blocks[i].getGlobalBounds()))
			{
				score += 10; // Cada colisão com o bloco adiciona 10
				text2.setString(std::to_string(score)); // atualiza constantemente sempre que estiver no loop
				blocks[i].setPosition(-100, 0);
				dy = -dy;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) // inicializa a bola com a tecla space
		{
			text9.setPosition(-800, -800); // desloca o Press Space
			dx = 3;
			dy = 3;
		}

		if (x < 1 || x > 500) // bordas para a bola não sair da tela
		{
			dx = -dx;
		}
		
		if (y < 45 || y > 485) // 45 para limitar colisão da bola abaixo do Score(y=40)
		{
			dy = -dy;
		}
	
		if (sf::FloatRect(x, y, 12, 12).intersects(Paddle.getGlobalBounds())) // colisão com o paddle
		{
			dy = -(rand() % 5 + 2);
		}


		//		ball.setPosition(x, y); // foi adicionado na linha 158


		/* Perdendo bolas */
		if (y > 483) // 483 limite inferior da janela para o toque
		{
			balls -= 1;
			text4.setString(std::to_string(balls)); // atualiza constantemente sempre que estiver no loop
		}

		
		/* Perdeu - Game Over */
		if (balls < 1) balls = 0; // não deixa negativo
		
		if (balls < 1) // <= 0
		{
			dx = 0, dy = 0; // pára a bolinha
			x = 320, y = 390; // posição final 
			
			text5.setPosition(60, 200); // posição do texto GAME OVER
		}

		/* Venceu - You Win */
		if (score == 1000)
		{
			dx = 0, dy = 0;
			text6.setPosition(116, 200);
		}

		/* Movimento do paddle */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) Paddle.move(6, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) Paddle.move(-6, 0);

		/* Cria os elementos */
		app.clear(sf::Color::Black); // Background
		app.draw(retangule); // Desenha o retangulo do score
		
		app.draw(ball);
		app.draw(Paddle);
		for (int i = 0; i < num; i++)
			app.draw(blocks[i]);
		
		app.draw(ArkanoirLogo);

		app.draw(text1);
		app.draw(text2);
		app.draw(text3);
		app.draw(text4);
		app.draw(text5);
		app.draw(text6);
		app.draw(text7);
		app.draw(text9);
		app.draw(ArkanoirLogo); // A posição dos Draws interfere nos itens que aparecem na tela, ou seja, cria uma camada superior
		app.draw(text8);
		
		app.display();
	}

	return 0;
}

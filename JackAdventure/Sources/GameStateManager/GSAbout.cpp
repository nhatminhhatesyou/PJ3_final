#include "GSAbout.h"

GSAbout::GSAbout()
{
}

GSAbout::~GSAbout()
{
}

void GSAbout::Exit()
{
}

void GSAbout::Pause()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Init()
{
	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("close");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->PopState(); });
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("Background layers/Background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//Tile Game
	m_Title.setString("ABOUT");
	m_Title.setFont(*DATA->getFont("ARCADE"));
	m_Title.setPosition(screenWidth / 2, screenHeight / 5);
	sf::FloatRect rc = m_Title.getLocalBounds();
	m_Title.setOrigin(rc.width / 2, rc.height / 2);
	
	//Content
	m_Content.setString("Project III - Pham Nhat Minh");
	m_Content.setFont(*DATA->getFont("ARCADE"));
	m_Content.setPosition(screenWidth / 2, screenHeight / 5 + 50);
	rc = m_Content.getLocalBounds();
	m_Content.setOrigin(rc.width / 2, rc.height / 2);

	//HOW TO PLAY - text
	m_Introduction.setString("HOW TO PLAY");
	m_Introduction.setFont(*DATA->getFont("ARCADE"));
	m_Introduction.setPosition(screenWidth / 2, screenHeight / 5 + 150);
	rc = m_Introduction.getLocalBounds();
	m_Introduction.setOrigin(rc.width / 2, rc.height / 2);

	//HOW TO PLAY - img
	texture = DATA->getTexture("Background layers/introduction");
	m_HowToPlay.setTexture(*texture);
	m_HowToPlay.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_HowToPlay.scale(0.5f, 0.5f);
	m_HowToPlay.setPosition(screenWidth / 2, screenHeight / 5 + 300);
}

void GSAbout::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}	
}

void GSAbout::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(m_HowToPlay);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
	window->draw(m_Content);
	window->draw(m_Introduction);
}

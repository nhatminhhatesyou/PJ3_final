#include "ParallelBackground.h"

void ParallexBackground::Init()
{
	Layer* layer;
	std::string path = "Background layers/";
	//Layer 1
	layer = new Layer();
	layer->Init(path+"bg_flat",50);
	m_Background.push_back(layer);
	//Layer 2
	layer = new Layer();
	layer->Init(path + "bg_grey", 60);
	m_Background.push_back(layer);
	//Layer 3
	layer = new Layer();
	layer->Init(path + "bg_purp", 110);
	m_Background.push_back(layer);
	//Layer 4
	layer = new Layer();
	layer->Init(path + "Layer_0004_Lights", 140);
	m_Background.push_back(layer);
	//Layer 5
	layer = new Layer();
	layer->Init(path + "ground_2", 200);
	m_Background.push_back(layer);
	//Layer 6
	layer = new Layer();
	layer->Init(path + "ground_1", 200);
	m_Background.push_back(layer);
}

void ParallexBackground::Update(float deltaTime)
{
	for (auto layer : m_Background) {
		layer->Update(deltaTime);
	}
}

void ParallexBackground::Render(sf::RenderWindow* window)
{
	for (auto layer : m_Background) {
		layer->Render(window);
	}
}

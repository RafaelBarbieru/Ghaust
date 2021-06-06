#pragma once
class Bedlamite
{
private:
	// Private variables
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2i m_size;
	const std::string m_pathToTextures = "src/entities/enemies/";
	bool m_trueSize;
	std::vector<std::string> m_textures;

	// Private functions
	void loadTextures();
public:
	// Variables
	float damage = 1.f;

	// Functions
	void doDamage();
	sf::Sprite spawn(const int xPos, const int yPos);
	
	// Constructors and destructors
	Bedlamite(const unsigned int xSize, const unsigned int ySize, bool trueSize);
	virtual ~Bedlamite();
};


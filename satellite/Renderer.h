#pragma once
#pragma once
#include <unordered_map>
#include <vector>
#include "SDL.h"
#include "Math.h"

class Renderer
{
public:
	Renderer(class Game* game);
	~Renderer();
	//レンダラーの初期化処理と終了処理
	bool Initialize(float screenWidth, float screenHeight);
	void Shutdown();
	//全てのテクスチャ・メッシュを解放
	void UnloadData();
	//フレームの描画
	void Draw();

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	class Texture* GetTexture(const std::string& fileName);
private:
	bool LoadShaders();
	void CreateSpriteVerts();
	class Game* mGame;

	std::unordered_map<std::string, Texture*> mTextures;
	std::vector<class SpriteComponent*> mSprites;

	class Shader* mSpriteShader;
	class VertexArray* mSpriteVerts;

	float mScreenWidth;
	float mScreenHeight;

	SDL_Window* mWindow;
	SDL_GLContext mContext;
};


#pragma once

class BitBmp;

class Scene abstract
{
	std::map<std::string, BitBmp*>		map_bmp;
public:
	Scene();
	virtual ~Scene();

	virtual void Initialize();
	virtual int	 Progress();
	virtual void Render(HDC _hdc);
	virtual void Release();
};


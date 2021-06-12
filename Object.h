#pragma once

class BitBmp;

class Object
{
protected:
	static std::map<std::string, BitBmp*>* map_bmp; // �ּ�
	std::string name;
	CRECT rect;
public:
	Object();
	virtual ~Object();

	void Initialize();
	void Progress();
	void Render();
	void Release();

	void SetRect(CRECT rc);	
	CRECT GetRect();		

	static void SetBmp(std::map<std::string, BitBmp*>* _map_bmp)
	{
		map_bmp = _map_bmp;
	}
};

// �̸�
//  -pos
//  -rect
// �׸��� �뵵 - bitbmp
// H��Ʈ��
//  -��Ʈ��
//  -dc
// 
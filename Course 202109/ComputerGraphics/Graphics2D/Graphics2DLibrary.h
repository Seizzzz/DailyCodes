#pragma once
#include "framework.h"
#include <cmath>
#include <vector>
using std::vector;

struct Pixel
{
public:
	int x, y;
	Pixel() = delete;
	Pixel(int _x, int _y) : x(_x), y(_y) {}
};

class Graphics2DLibrary
{
private:
	const HDC* m_pHDC;
	COLORREF m_sColor;

public: // ���Ƶ�
	inline void DrawPoint(const Pixel& pos);

public: // ����ֱ�߶�
	void DrawLine(const Pixel& st, const Pixel& ed);

public: // ����Բ��
	void DrawCircle_Bresenham(const Pixel& center, const int& radius);
	void DrawCircle_Polygon(const Pixel& center, const int& radius, const double& theta1, const double& theta2, const double& alpha);

public: // ������Բ
	void DrawEllipse(const Pixel& center, const double& a, const double& b, const double& theta1, const double& theta2, const double& alpha);

public: // ��Ӱ�����
	void LineFill(double alpha, double h, vector<vector<Pixel>> arr);

public: // ��ɫ���
	void ColorFill_Flood4(const Pixel& st, COLORREF color);

public:
	inline void SetHDC(const HDC& hdc) { m_pHDC = &hdc; }
	inline const HDC& GetHDC() { return *m_pHDC; }
	inline void SetColor(const COLORREF& color) { m_sColor = color; }
	inline COLORREF& GetColor() { return m_sColor; }
};

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

public: // 绘制点
	inline void DrawPoint(const Pixel& pos);

public: // 绘制直线段
	void DrawLine(const Pixel& st, const Pixel& ed);

public: // 绘制圆弧
	void DrawCircle_Bresenham(const Pixel& center, const int& radius);
	void DrawCircle_Polygon(const Pixel& center, const int& radius, const double& theta1, const double& theta2, const double& alpha);

public: // 绘制椭圆
	void DrawEllipse(const Pixel& center, const double& a, const double& b, const double& theta1, const double& theta2, const double& alpha);

public: // 阴影线填充
	void LineFill(double alpha, double h, vector<vector<Pixel>> arr);

public: // 颜色填充
	void ColorFill_Flood4(const Pixel& st, COLORREF color);

public:
	inline void SetHDC(const HDC& hdc) { m_pHDC = &hdc; }
	inline const HDC& GetHDC() { return *m_pHDC; }
	inline void SetColor(const COLORREF& color) { m_sColor = color; }
	inline COLORREF& GetColor() { return m_sColor; }
};

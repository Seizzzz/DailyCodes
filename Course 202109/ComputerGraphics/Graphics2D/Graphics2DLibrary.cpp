#include "Graphics2DLibrary.h"
#include <queue>
#include <climits>
#include <algorithm>

inline void Graphics2DLibrary::DrawPoint(const Pixel& pos)
{ // ���Ƶ㣨������չ���ƾ����øú������㣩
	SetPixel(GetHDC(), pos.x, pos.y, GetColor());
}

void Graphics2DLibrary::DrawLine(const Pixel& st, const Pixel& ed)
{ // ����ֱ�߶Σ���ʼ����Ļ���ꡢ��ֹ����Ļ���꣩
	auto x = st.x, y = st.y;
	auto _dx = ed.x - st.x, _dy = ed.y - st.y;
	auto _stepx = 1, _stepy = 1;
	if (_dx < 0)
	{
		_stepx = -1;
		_dx = -_dx;
	}
	if (_dy < 0)
	{
		_stepy = -1;
		_dy = -_dy;
	}
	auto _2dx = (_dx << 1);
	auto _2dy = (_dy << 1);

	if (_dx > _dy)
	{
		auto e = _2dy - _dx;
		for (int i = 0; i < _dx; ++i)
		{
			DrawPoint({ x,y });
			if (e >= 0)
			{
				y += _stepy;
				e -= _2dx;
			}
			x += _stepx;
			e += _2dy;
		}
	}
	else
	{
		auto e = _2dx - _dy;
		for (int i = 0; i < _dy; ++i)
		{
			DrawPoint({ x,y });
			if (e >= 0)
			{
				x += _stepx;
				e -= _2dy;
			}
			y += _stepy;
			e += _2dx;
		}
	}
}

void Graphics2DLibrary::DrawCircle_Bresenham(const Pixel& center, const int& radius)
{ // ��������Բ����Բ�ġ��뾶�� 
	auto& hdc = GetHDC();
	auto color = GetColor();

	int x = 0, y = radius;
	int d = 3 - (radius << 1);
	while (x < y)
	{
		DrawPoint({ center.x + x, center.y + y });
		DrawPoint({ center.x + x, center.y - y });
		DrawPoint({ center.x - x, center.y + y });
		DrawPoint({ center.x - x, center.y - y });
		DrawPoint({ center.x + y, center.y + x });
		DrawPoint({ center.x + y, center.y - x });
		DrawPoint({ center.x - y, center.y + x });
		DrawPoint({ center.x - y, center.y - x });

		if (d < 0)
		{
			d = d + (x << 2) + 6;
		}
		else
		{
			d = d + 4 * (x - y) + 10;
			--y;
		}
		++x;
	}
	if (x == y) DrawPoint({ x, y });
}

void Graphics2DLibrary::DrawCircle_Polygon(const Pixel& center, const int& radius, const double& theta1, const double& theta2, const double& alpha)
{ // ��������Բ����Բ�ġ��뾶����ʼ���ȡ���ֹ���ȡ����ڲ���������Ӧ��Բ�Ľǣ� 
	auto _cos = cos(alpha);
	auto _sin = sin(alpha);

	double xc = center.x;
	double yc = center.y;
	double xi = xc + radius * cos(theta1);
	double yi = yc + radius * sin(theta1);
	int times = abs((theta2 - theta1) / alpha);

	while (--times)
	{
		DrawPoint({ (int)round(xi), (int)round(yi) });
		double xi1 = xc + (xi - xc) * _cos - (yi - yc) * _sin;
		double yi1 = yc + (xi - xc) * _sin + (yi - yc) * _cos;
		xi = xi1;
		yi = yi1;
	}
}

void Graphics2DLibrary::DrawEllipse(const Pixel& center, const double& a, const double& b, const double& theta1, const double& theta2, const double& dt)
{ // ������Բ����Բ���ġ��볤�ᡢ����ᡢ��ʼ���ȡ���ֹ���ȡ������ܶȣ� 
	if (dt <= 0) return;

	double t = theta1;
	const double _2PI = 2 * acos(-1);
	while (t < theta2)
	{
		int x = center.x + a * cos(t);
		int y = center.y + b * sin(t);

		DrawPoint({ x,y });

		t += dt;
	}
}

void Graphics2DLibrary::LineFill(double alpha, double h, vector<vector<Pixel>> arr)
{ // ��Ӱ����䣨��Ӱ�߽Ƕȡ���Ӱ�߾��롢�����Ϣ���飩
	if (arr.empty()) return;
	double tga = tan(alpha);
	double deltaB = h / abs(cos(alpha));

	// ��������ֱ�߶εĽؾ�
	vector<vector<double>> info;
	for (auto edge : arr)
	{
		double itcept1 = edge[0].y - tga * edge[0].x;
		double itcept2 = edge[1].y - tga * edge[1].x;
		info.push_back({ itcept1, itcept2 });
	}

	// ����ؾ෶Χ
	double Bmin = info[0][0];
	double Bmax = info[0][1];
	for (auto itcept : info)
	{
		Bmin = min(Bmin, itcept[0]);
		Bmax = max(Bmax, itcept[1]);
	}

	// �����ؾ�
	double B = Bmin;
	while (B < Bmax)
	{
		vector<Pixel> cross;
		for (int i = 0; i < arr.size(); ++i)
		{
			if ((info[i][0] < B && B < info[i][1]) || (info[i][0] > B && B > info[i][1])) // �ؾ�֮�� �ཻ
			{
				// ���Բ�ֵ�õ���������
				double ratio = (B - info[i][0]) / (info[i][1] - info[i][0]);
				double crossX = arr[i][0].x + (arr[i][1].x - arr[i][0].x) * ratio;
				double crossY = arr[i][0].y + (arr[i][1].y - arr[i][0].y) * ratio;
				cross.push_back({ (int)crossX, (int)crossY });
			}
		}

		// ��������
		using std::sort;
		sort(cross.begin(), cross.end(), [](const Pixel& a, const Pixel& b) {
			return a.x < b.x;
		});

		// ����һ����ֱ�߶�
		for (int i = 1; i < cross.size(); i += 2) {
			DrawLine(cross[i - 1], cross[i]);
		}

		B += deltaB;
	}
}

void Graphics2DLibrary::ColorFill_Flood4(const Pixel& st, COLORREF color)
{ // ��ɫ���-4��ͨ������ʼ�㡢��ɫ�� 
	auto& hdc = GetHDC();
	auto sv_color = GetColor();
	SetColor(color);

	auto color2fill = GetPixel(hdc, st.x, st.y);

	using std::queue;
	queue<Pixel> q;
	q.push(st);
	while (!q.empty())
	{
		auto& px = q.front();
		if (GetPixel(hdc, px.x, px.y) == color2fill)
		{
			DrawPoint({ px.x, px.y });
			q.push({ px.x, px.y + 1 });
			q.push({ px.x, px.y - 1 });
			q.push({ px.x + 1, px.y });
			q.push({ px.x - 1, px.y });
		}
		q.pop();
	}

	SetColor(sv_color);
}

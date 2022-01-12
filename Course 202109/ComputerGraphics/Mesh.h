#pragma once
#include <gl/glut.h>
#include "Vec3.h"
#include <vector>

struct Line
{
	int st;
	int ed;
	Line(int a, int b) : st(a), ed(b) {}
};

class Mesh
{
protected:
	Vec3 m_vTrans;
	Vec3 m_vRots;
	Vec3 m_vScale;
	std::vector<Vec3> vtx;

protected:
	void AddVertex(Vec3 v) {
		vtx.push_back(v.Rotate(m_vRots).Scale(m_vScale).Translate(m_vTrans));
	}

public:
	Mesh(Vec3 trans, Vec3 rots, Vec3 scale) : m_vTrans(trans), m_vRots(rots), m_vScale(scale) {}

	virtual void Draw() = 0;
};

class MeshCube : public Mesh
{
public:
	MeshCube(Vec3 trans, Vec3 rots, Vec3 scale) : Mesh(trans, rots, scale) {
		AddVertex(Vec3(-0.5f, -0.5f, -0.5f));
		AddVertex(Vec3(0.5f, -0.5f, -0.5f));
		AddVertex(Vec3(-0.5f, 0.5f, -0.5f));
		AddVertex(Vec3(0.5f, 0.5f, -0.5f));
		AddVertex(Vec3(-0.5f, -0.5f, 0.5f));
		AddVertex(Vec3(0.5f, -0.5f, 0.5f));
		AddVertex(Vec3(-0.5f, 0.5f, 0.5f));
		AddVertex(Vec3(0.5f, 0.5f, 0.5f));

		idx.emplace_back(Line(0, 1));
		idx.emplace_back(Line(2, 3));
		idx.emplace_back(Line(4, 5));
		idx.emplace_back(Line(6, 7));
		idx.emplace_back(Line(0, 2));
		idx.emplace_back(Line(1, 3));
		idx.emplace_back(Line(4, 6));
		idx.emplace_back(Line(5, 7));
		idx.emplace_back(Line(0, 4));
		idx.emplace_back(Line(1, 5));
		idx.emplace_back(Line(7, 3));
		idx.emplace_back(Line(2, 6));
	};

	virtual void Draw() override {
		glBegin(GL_LINES);
		for (auto& l : idx)
		{
			glVertex3f(vtx[l.st].GetX(), vtx[l.st].GetY(), vtx[l.st].GetZ());
			glVertex3f(vtx[l.ed].GetX(), vtx[l.ed].GetY(), vtx[l.ed].GetZ());
		}
		glEnd();
	}

private:
	
	std::vector<Line> idx;

};

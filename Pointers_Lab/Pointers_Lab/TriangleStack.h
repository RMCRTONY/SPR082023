#pragma once
class TriangleStack
{
private:
	float mBase;
	float mHeight;
public:
	void SetBase(float b) { mBase = b; }
	void SetHeight(float h) { mHeight = h; }

	float GetArea();
};


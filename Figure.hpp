#pragma once

class CFigure
{
public:
	CFigure() 
	{}

	virtual ~CFigure()
	{}

	virtual void Draw() = 0;

	void SetGraphics(Gdiplus::Graphics* temp)
	{
		this->temp = temp;
	}

protected:
	Gdiplus::Graphics* temp;
};


class CCircle : public CFigure
{
public:
	CCircle() 
	{}
	~CCircle()
	{
		if (pen_frame_level)
		{
			delete pen_frame_level;
			pen_frame_level = nullptr;
		}
	}
	
	void Draw() override
	{
		if (temp)
		{
			if (pen_frame_level == nullptr)
				pen_frame_level = new Gdiplus::Pen(Gdiplus::Color(255, 255, 0, 0), 3);

			if (temp)
			{
				Gdiplus::Rect rect;
				rect.X = 5;
				rect.Y = 10;
				rect.Height = 100;
				rect.Width = 100;
				temp->DrawEllipse(pen_frame_level, rect);
			}
		}
	}
private:
	Gdiplus::Pen* pen_frame_level = nullptr;
};

class CSquare : public CFigure
{
public:
	CSquare()
	{}
	~CSquare()
	{
		if (pen_frame_level)
		{
			delete pen_frame_level;
			pen_frame_level = nullptr;
		}
	}

	void Draw() override
	{
		if (temp)
		{
			if (pen_frame_level == nullptr)
				pen_frame_level = new Gdiplus::Pen(Gdiplus::Color(255, 0, 255, 0), 3);

			if (temp)
			{
				Gdiplus::Rect rect;
				rect.X = 145;
				rect.Y = 10;
				rect.Height = 100;
				rect.Width = 100;
				temp->DrawRectangle(pen_frame_level, rect);
			}
		}
	}
private:
	Gdiplus::Pen* pen_frame_level = nullptr;
};

class CRectangle : public CFigure
{
public:
	CRectangle()
	{}
	~CRectangle()
	{
		if (pen_frame_level)
		{
			delete pen_frame_level;
			pen_frame_level = nullptr;
		}
	}

	void Draw() override
	{
		if (pen_frame_level == nullptr)
			pen_frame_level = new Gdiplus::Pen(Gdiplus::Color(255, 0, 0, 0), 3);

		if (temp)
		{
			Gdiplus::Rect rect;
			rect.X = 275;
			rect.Y = 10;
			rect.Height = 120;
			rect.Width = 80;
			temp->DrawRectangle(pen_frame_level, rect);
		}
	}
private:
	Gdiplus::Pen* pen_frame_level = nullptr;
};

class CTringle : public CFigure
{
public:
	CTringle()
	{}
	~CTringle()
	{
		if (pen_frame_level)
		{
			delete pen_frame_level;
			pen_frame_level = nullptr;
		}
	}

	void Draw() override
	{
		if (temp)
		{
			if (pen_frame_level == nullptr)
				pen_frame_level = new Gdiplus::Pen(Gdiplus::Color(255, 0, 0, 255), 3);

			if (temp)
			{
				Gdiplus::PointF rect1;
				rect1.X = 450;
				rect1.Y = 10;

				Gdiplus::PointF rect2;
				rect2.X = 425;
				rect2.Y = 80;

				Gdiplus::PointF rect3;
				rect3.X = 475;
				rect3.Y = 80;

				temp->DrawLine(pen_frame_level, rect1, rect2);
				temp->DrawLine(pen_frame_level, rect1, rect3);
				temp->DrawLine(pen_frame_level, rect2, rect3);
			}
		}
	}
private:
	Gdiplus::Pen* pen_frame_level = nullptr;
};
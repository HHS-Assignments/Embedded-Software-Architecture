#include <iostream>

class IPositie {
public:
	virtual ~IPositie() = default;
	virtual int x() const = 0;
	virtual int y() const = 0;
	virtual void move(int dx, int dy) = 0;
};

class Positie : public IPositie {
public:
	Positie(int x, int y) : m_x(x), m_y(y) {}
	int x() const override { return m_x; }
	int y() const override { return m_y; }
	void move(int dx, int dy) override { m_x += dx; m_y += dy; }
private:
	int m_x;
	int m_y;
};

class Robot {
public:
	explicit Robot(IPositie* p) : m_pos(p) {}
	void run()
	{
		// simple behavior: move the position
		if (m_pos) m_pos->move(1, 1);
	}
	void show() const
	{
		if (m_pos)
			std::cout << "Positie: (" << m_pos->x() << ", " << m_pos->y() << ")\n";
		else
			std::cout << "No positie available\n";
	}
private:
	IPositie* m_pos;
};

int main()
{
	Positie P(5,10);
	Robot R(&P);
	R.run();
	R.show();

	return 0;
}


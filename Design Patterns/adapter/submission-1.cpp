class Square {
    double sideLength;

public:
    Square() : sideLength(0) {}

    Square(double sideLength) : sideLength(sideLength) {}

    virtual double getSideLength() {
        return sideLength;
    }
};

class SquareHole {
    double sideLength;

public:
    SquareHole(double sideLength) : sideLength(sideLength) {}

    bool canFit(Square& square) {
        return sideLength >= square.getSideLength();
    }
};

class Circle {
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double getRadius() {
        return radius;
    }
};

class CircleToSquareAdapter : public Square {
private:
    Circle& m_circle; // Member variable

public:
    // Initialize m_circle using the constructor parameter
    CircleToSquareAdapter(Circle& circle) : m_circle(circle) {}

    double getSideLength() override {
        // Access the member variable to get the radius
        return 2 * m_circle.getRadius();
    }
};

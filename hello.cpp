#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    virtual void draw() = 0;
};

class Rectangle : public Shape
{
public:
    void draw() override
    {
        cout << "Inside Rectangle." << endl;
    }
};

class Square : public Shape
{
public:
    void draw() override
    {
        cout << "Inside Square." << endl;
    }
};

class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Inside Circle." << endl;
    }
};

class ShapeFactory
{
private:
    ShapeFactory() {}

public:
    static ShapeFactory &getInstance()
    {
        static ShapeFactory instance;
        return instance;
    }

    Shape *getShape(const string &shapeType)
    {
        if (shapeType == "RECTANGLE")
        {
            return new Rectangle();
        }
        else if (shapeType == "SQUARE")
        {
            return new Square();
        }
        else if (shapeType == "CIRCLE")
        {
            return new Circle();
        }
        return nullptr;
    }
};

int main()
{
    ShapeFactory &shapeFactory = ShapeFactory::getInstance();

    Shape *shape1 = shapeFactory.getShape("CIRCLE");
    if (shape1 != nullptr)
    {
        shape1->draw();
        delete shape1;
    }

    Shape *shape2 = shapeFactory.getShape("RECTANGLE");
    if (shape2 != nullptr)
    {
        shape2->draw();
        delete shape2;
    }

    return 0;
}

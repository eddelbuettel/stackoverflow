#ifndef MISCCLASS1_H
#define MISCCLASS1_H

class miscClass1 {

    int X;
    int Y;

    public:

    miscClass1(int x, int y);

    int addXY();//adds the two variables x and y

    int getX();
    int getY();//accessors

    void setX(int x);
    void setY(int y);//mutators
};

#endif

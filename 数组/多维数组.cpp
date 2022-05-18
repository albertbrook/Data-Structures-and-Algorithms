#include <iostream>

class MultidimensionalArray {
private:
    int **array;
    int sizeX;
    int sizeY;

public:
    MultidimensionalArray(int sizeX, int sizeY) {
        this->sizeX = sizeX;
        this->sizeY = sizeY;
        array = new int *[sizeX];
        for (int i = 0; i < sizeX; ++i) {
            array[i] = new int[sizeY];
            for (int j = 0; j < sizeY; ++j)
                array[i][j] = 0;
        }
    }

    void print() {
        for (int i = 0; i < sizeX; ++i)
            for (int j = 0; j < sizeY; ++j)
                printf("%d%c", array[i][j], j != sizeY - 1 ? ' ' : '\n');
    }

    void assign(int x, int y, int data) {
        if (x >= sizeX || y >= sizeY)
            return;
        array[x][y] = data;
    }

    int getValue(int x, int y) {
        return array[x][y];
    }

    MultidimensionalArray transform() {
        MultidimensionalArray ma(sizeY, sizeX);
        for (int i = 0; i < sizeX; ++i)
            for (int j = 0; j < sizeY; ++j)
                ma.assign(j, i, array[i][j]);
        return ma;
    }

    MultidimensionalArray mul(MultidimensionalArray ma) {
        MultidimensionalArray ma2(sizeX, ma.sizeY);
        if (sizeY != ma.sizeX)
            return ma2;
        for (int i = 0; i < ma2.sizeX; ++i)
            for (int j = 0; j < ma2.sizeY; ++j)
                for (int k = 0; k < sizeY; ++k)
                    ma2.assign(i, j, ma2.getValue(i, j) + array[i][k] * ma.getValue(k, j));
        return ma2;
    }
};
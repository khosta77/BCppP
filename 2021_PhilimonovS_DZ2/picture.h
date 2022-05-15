#ifndef PICTURE_H
#define PICTURE_H

#include <QImage>

struct matrix {
      int **image;
      int X; // ширина
      int Y; // высота
};

class picture{
private:
    QImage img;
    matrix pictureImg;
    matrix delotaition;
    matrix arrozion;
    int MaskLeftSizeX;
    int MaskRightSizeX;
    int MaskUpSizeY;
    int MaskDownSizeY;
public:
    picture();
    void SetAConditonMask(int a, int b, int c, int i);
    void InputImage(QString load_adress);
    void Arrozion();
    void Delotation();
    void Frame();
    void OutputImage(QString onload_adress, int index);
    void MatrixInitializationInittalMatrix(int A, int B);
    void MatrixInitializationDelotation(int A, int B);
    void MatrixInitializationArrozion(int A, int B);
    void MatrixRemovalIntalMatrix(int B);
    void MatrixRemovalDelotation(int B);
    void MatrixRemovalArrozion(int B);
    ~picture();
};

#endif // PICTURE_H

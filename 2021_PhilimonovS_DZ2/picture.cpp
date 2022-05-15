#include "picture.h"
#include <QDebug>
#include <QFile>
#include <QImage>
#include <QColor>
#include <QDebug>

picture::picture(){
    MaskLeftSizeX = 1;
    MaskUpSizeY = 1;
    MaskRightSizeX = 1;
    MaskDownSizeY = 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void picture::SetAConditonMask(int a, int b, int c, int i){
    MaskLeftSizeX = a;
    MaskUpSizeY = b;
    MaskRightSizeX = c;
    MaskDownSizeY = i;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void picture::InputImage(QString load_adress){
    img.load(load_adress);
    img = img.convertToFormat(QImage::Format_Mono);
    pictureImg.X = img.width();
    pictureImg.Y = img.height();
    MatrixInitializationInittalMatrix( pictureImg.X, pictureImg.Y);
    for(int i = 0; i < pictureImg.Y ; i++ ){
        for(int j = 0 ; j < pictureImg.X ; j++){
            pictureImg.image[i][j] = QColor(img.pixel(j, i)).black() > 127 ? 1:0;
        }
    }
    MatrixInitializationDelotation(pictureImg.X + (MaskLeftSizeX + MaskRightSizeX), pictureImg.Y + (MaskUpSizeY + MaskDownSizeY));
    for(int i = MaskUpSizeY, m = 0; i < pictureImg.Y + MaskUpSizeY; i++, m++){
        for(int j = MaskLeftSizeX, c = 0; j < pictureImg.X + MaskLeftSizeX; j++, c++){
            delotaition.image[i][j] = pictureImg.image[m][c];
        }
    }
    MatrixInitializationArrozion(pictureImg.X + (MaskLeftSizeX + MaskRightSizeX), pictureImg.Y + (MaskUpSizeY + MaskDownSizeY));
    for(int i = MaskUpSizeY, m = 0; i < pictureImg.Y + MaskUpSizeY; i++, m++){
        for(int j = MaskLeftSizeX, c = 0; j < pictureImg.X + MaskLeftSizeX; j++, c++){
            arrozion.image[i][j] = pictureImg.image[m][c];
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *           Алгоритм эррозии
 * Вход: отдельная матрица для эррозии
 * Выход: отерожинная матрица
 *
 */
void picture::Arrozion(){
    for(int i = MaskUpSizeY; i < pictureImg.Y + MaskUpSizeY; i++){ // передтем как пременить алгоритм эррозии необходимо применить делатацию
        for(int j = MaskLeftSizeX; j < pictureImg.X + MaskLeftSizeX; j++){
            if(arrozion.image[i][j] == 1){
                for(int t = j; t > j - MaskLeftSizeX - 1; t--){
                    if(arrozion.image[i][t] != 1){
                        arrozion.image[i][t] = 2;
                    }
                }
                for(int t = i; t > i - MaskUpSizeY - 1; t--){
                    if(arrozion.image[t][j] != 1){
                        arrozion.image[t][j] = 2;
                    }
                }
                for(int t = j; t < j + MaskRightSizeX + 1; t++){
                    if(arrozion.image[i][t] != 1){
                        arrozion.image[i][t] = 2;
                    }
                }
                for(int t = i; t < i + MaskDownSizeY + 1; t++){
                    if(arrozion.image[t][j] != 1){
                        arrozion.image[t][j] = 2;
                    }
                }
            }
        }
    }
    for(int i = MaskUpSizeY; i < pictureImg.Y + MaskUpSizeY; i++){
        for(int j = MaskLeftSizeX; j < pictureImg.X + MaskLeftSizeX; j++){
            if(arrozion.image[i][j] == 2){
                if(arrozion.image[i][j-1] == 1){
                    arrozion.image[i][j-1] = 0;
                }
                if(arrozion.image[i][j+1] == 1){
                    arrozion.image[i][j+1] = 0;
                }
                if(arrozion.image[i-1][j] == 1){
                    arrozion.image[i-1][j] = 0;
                }
                if(arrozion.image[i+1][j] == 1){
                    arrozion.image[i+1][j] = 0;
                }
            }
        }
    }
    for(int i = MaskUpSizeY; i < pictureImg.Y + MaskUpSizeY; i++){
        for(int j = MaskLeftSizeX; j < pictureImg.X + MaskLeftSizeX; j++){
            if(arrozion.image[i][j] == 2){
                arrozion.image[i][j] = 0;
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *           Алгоритм делотации
 * Вход: отдельная матрица для делотации
 * Выход: матрица матрица после делотации
 *
 */
void picture::Delotation(){
    for(int i = MaskUpSizeY; i < pictureImg.Y + MaskUpSizeY; i++){ // алгоритм делотации
        for(int j = MaskLeftSizeX; j < pictureImg.X + MaskLeftSizeX; j++){
            if(delotaition.image[i][j] == 1){
                for(int t = j; t > j - MaskLeftSizeX - 1; t--){
                    if(delotaition.image[i][t] != 1){
                        delotaition.image[i][t] = 2;
                    }
                }
                for(int t = i; t > i - MaskUpSizeY - 1; t--){
                    if(delotaition.image[t][j] != 1){
                        delotaition.image[t][j] = 2;
                    }
                }
                for(int t = j; t < j + MaskRightSizeX + 1; t++){
                    if(delotaition.image[i][t] != 1){
                        delotaition.image[i][t] = 2;
                    }
                }
                for(int t = i; t < i + MaskDownSizeY + 1; t++){
                    if(delotaition.image[t][j] != 1){
                        delotaition.image[t][j] = 2;
                    }
                }
            }
        }
    }
    for(int i = 0; i < pictureImg.Y + MaskUpSizeY + MaskDownSizeY; i++){
        for(int j = 0; j < pictureImg.X + MaskLeftSizeX + MaskRightSizeX; j++){
            if(delotaition.image[i][j] == 2){
                delotaition.image[i][j] = 1;
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void picture::Frame(){
    for(int i = MaskUpSizeY, m = 0; i < pictureImg.Y + MaskUpSizeY; i++, m++){
        for(int j = MaskLeftSizeX, c = 0; j < pictureImg.X + MaskLeftSizeX; j++, c++){
            pictureImg.image[m][c] = delotaition.image[i][j] - arrozion.image[i][j];
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void picture::OutputImage(QString onload_adress, int index){
    switch (index) {
    case 1:
        for(int i = MaskUpSizeY, m = 0; i < pictureImg.Y + MaskUpSizeY; i++, m++){
            for(int j = MaskLeftSizeX, c = 0; j < pictureImg.X + MaskLeftSizeX; j++, c++){
                pictureImg.image[m][c] = arrozion.image[i][j];
            }
        }
        break;
    case 2:
        for(int i = MaskUpSizeY, m = 0; i < pictureImg.Y + MaskUpSizeY; i++, m++){
            for(int j = MaskLeftSizeX, c = 0; j < pictureImg.X + MaskLeftSizeX; j++, c++){
                pictureImg.image[m][c] = delotaition.image[i][j];
            }
        }
        break;
    }
    for(int i = 0; i < pictureImg.Y ; i++ ){
        for(int j = 0 ; j < pictureImg.X ; j++){
            img.setPixel(j, i, pictureImg.image[i][j]);
        }
    }
    img.save(onload_adress);
    MatrixRemovalDelotation(delotaition.Y + (MaskUpSizeY + MaskDownSizeY));
    MatrixRemovalArrozion(arrozion.Y + (MaskUpSizeY + MaskDownSizeY));
    MatrixRemovalIntalMatrix(pictureImg.Y);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
picture::~picture(){
    MatrixRemovalDelotation(pictureImg.Y + (MaskUpSizeY + MaskDownSizeY));
    MatrixRemovalArrozion(pictureImg.Y + (MaskUpSizeY + MaskDownSizeY));
    MatrixRemovalIntalMatrix(pictureImg.Y);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Инициализация матриц
 */
void picture::MatrixInitializationInittalMatrix(int A, int B){
    pictureImg.image = NULL;
    pictureImg.image = new int* [B];
    for(int i = 0; i < B; i++){
        pictureImg.image[i] = new int[A];
    }
}

void picture::MatrixInitializationDelotation(int A, int B){
    delotaition.image = NULL;
    delotaition.image = new int* [B];
    for(int i = 0; i < B; i++){
        delotaition.image[i] = new int[A];
    }
}

void picture::MatrixInitializationArrozion(int A, int B){
    arrozion.image = NULL;
    arrozion.image = new int* [B];
    for(int i = 0; i < B; i++){
        arrozion.image[i] = new int[A];
    }
}

void picture::MatrixRemovalIntalMatrix(int B){
    for(int i = 0; i < B; ++i){
        delete[] pictureImg.image[i];
    }
    delete[] pictureImg.image;
}

void picture::MatrixRemovalDelotation(int B){
    for(int i = 0; i < B; ++i){
        delete[] delotaition.image[i];
    }
    delete[] delotaition.image;
}

void picture::MatrixRemovalArrozion(int B){
    for(int i = 0; i < B; ++i){
        delete[] arrozion.image[i];
    }
    delete[] arrozion.image;
}


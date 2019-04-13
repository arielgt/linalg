// Clase linalg que trabaja operaciones matriciales y vectoriales //
////////////////////////////////////////////////////////////////////
#ifndef _LINALG_H_
#define _LINALG_H_

#include<vector>
#include<iostream>

/* ////////////////////// */

class Vector{

public:
    Vector();
    Vector(std::vector<double> &);
    Vector addVect(Vector &);
    Vector subVect(Vector &);
    double dotVect(Vector &);
    Vector crossVect(Vector &);
    Vector prodVect(double); 
    void printVect(); 
    size_t GetSizeVect(); 
    double GetValue(int);

protected:
    std::vector<double> vector_;

};

/* ////////////////////// */

class Matrix{

public:
    Matrix();
    Matrix(std::vector<std::vector<double>> &);
    Matrix addMat(Matrix &);
    Matrix subMat(Matrix &);
    Vector mdotv (Vector &);
    Matrix mdotm (Matrix &);
    void printMat(); 

protected:
    std::vector<std::vector<double>> matrix_;
 
};

/* ////////////////////// */

#endif /* _LINALG_H_ */

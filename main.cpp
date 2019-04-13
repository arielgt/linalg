//   Programa que sirve para probar la clase de linalg     //
/////////////////////////////////////////////////////////////

#include"linalg.h"

int main(){

    double num = {1.5};
    std::vector<double> Vect1 (3);
    Vect1 = {1.2,2.2,3.2};
    std::vector<double> Vect2 (3);
    Vect2 = {1.5,2.5,3.5};
    std::vector<std::vector<double>> Mat1 (3, std::vector<double>(3));
    std::vector<std::vector<double>> Mat2 (3, std::vector<double>(3));
    Mat1 = {{1.3,2.3,3.3},{4.3,5.3,6.3},{7.4,8.2,9.2}};
    Mat2 = {{1.5,2.5,3.5},{4.5,5.5,6.5},{7.5,8.5,9.5}};
   
    // Creación de los objetos de la clase Vector: 
    Vector v1(Vect1);                                      // Objeto del Vector 1.
    Vector v2(Vect2);                                      // Objeto del Vector 2.
    Vector v3;                                             // Objeto del Vector que resulta en la operación.
    
    std::cout << "------- " << std::endl;
    std::cout << "Vect1: " << std::endl;
         v1.printVect();
    std::cout << "------- " << std::endl;
    std::cout << "Vect2: " << std::endl;
         v2.printVect();
    std::cout << "------- " << std::endl;
    std::cout << "Vect1+Vect2: " << std::endl;
         v3 = v1.addVect(v2);
         v3.printVect();
    std::cout << "------- " << std::endl;
    std::cout << "Vect1-Vect2: " << std::endl;
         v3 = v1.subVect(v2);
         v3.printVect();
    std::cout << "------- " << std::endl;
    std::cout << "Vect1*Vect2: " << std::endl;
         std::cout << v1.dotVect(v2) << std::endl;
    std::cout << "------- " << std::endl;
    std::cout << "Vect1XVect2: " << std::endl;
         v3 = v1.crossVect(v2);
         v3.printVect();
    std::cout << "------- " << std::endl;
    std::cout << "Vect1*cte: " << std::endl;
         v3 = v1.prodVect(num);
         v3.printVect(); 
    std::cout << "------- " << std::endl;

    // Creación de los objetos de la clase Matrix: 
    Matrix m1(Mat1);                                       // Objeto de la Matriz 1.
    Matrix m2(Mat2);                                       // Objeto de la Matriz 2.
    Matrix m3;                                             // Objeto de la Matriz que resulta en la operación

    std::cout << "Mat1: " << std::endl;
         m1.printMat();
    std::cout << "------- " << std::endl;
    std::cout << "Mat2: " << std::endl;
         m2.printMat();
    std::cout << "------- " << std::endl;
    std::cout << "Mat1+Mat2: " << std::endl;
         m3 = m1.addMat(m2);
         m3.printMat();
    std::cout << "------- " << std::endl;
    std::cout << "Mat1-Mat2: " << std::endl;
         m3 = m1.subMat(m2);
         m3.printMat();
    std::cout << "------- " << std::endl;
    std::cout << "Vect*Mat: " << std::endl;
         v3 = m1.mdotv(v1); 
         v3.printVect();
    std::cout << "------- " << std::endl;
    std::cout << "Mat1*Mat2: " << std::endl;
         m3 = m1.mdotm(m2);
         m3.printMat();
    std::cout << "------- " << std::endl;
}

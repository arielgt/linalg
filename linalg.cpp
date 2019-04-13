// Clase linalg que trabaja operaciones matriciales y vectoriales ///
/////////////////////////////////////////////////////////////////////
#ifndef _LINALG_CPP_
#define _LINALG_CPP_

#include"linalg.h"

Vector::Vector(){
     
}

Vector::Vector(std::vector<double> &x){
    vector_ = x;
}

Vector Vector::addVect(Vector &x){
    std::vector<double> vsum(vector_.size());              // Tamaño del vector que es objeto de esta clase.
    for(size_t i = 0; i < vector_.size(); ++i){
         if(vector_.size() != x.vector_.size()){           // Tamaño del vector x (Vector 2), objeto v2.  
              std::cout << "Check size!" << std::endl;
              break;   
         }
         vsum[i] = vector_[i] + x.vector_[i];              // Elemento del vector x (v2).
    }
    Vector vs(vsum);
    return vs;
}

Vector Vector::subVect(Vector &x){
    std::vector<double> vsub(vector_.size());
    for(size_t i = 0; i < vector_.size(); ++i){
         if(vector_.size() != x.vector_.size()){
              std::cout << "Check size!" << std::endl;
              break;   
         }
         vsub[i] = vector_[i] - x.vector_[i];
    }
    Vector vr(vsub);
    return vr;
}

double Vector::dotVect(Vector &x){
    double dot = {0};
    for(size_t i = 0; i < vector_.size(); ++i){
         if(vector_.size() != x.vector_.size()){
 	      std::cout << "check size!" << std::endl;
 	      break;
         }
         dot = dot + vector_[i]*x.vector_[i];     
    }
    return dot;      
}

Vector Vector::crossVect(Vector &x){
    std::vector<double> vcross;
    vcross.push_back((vector_[1]*x.vector_[2])-(x.vector_[1]*vector_[2]));
    vcross.push_back(-((vector_[0]*x.vector_[2])-(x.vector_[0]*vector_[2])));
    vcross.push_back((vector_[0]*x.vector_[1])-(x.vector_[0]*vector_[1]));
    if(vector_.size() != x.vector_.size()){
         std::cout << "Check size!" << std::endl;
         vcross = {0.0, 0.0, 0.0};
    }
  
    Vector vc(vcross);  
    return vc;	
}

Vector Vector::prodVect(double n){
    std::vector<double> vproduct(vector_.size());
    for(size_t i = 0; i < vector_.size(); ++i){
         vproduct[i] = (vector_[i]*n);
    }

    Vector vp(vproduct);
    return vp;	
}

void Vector::printVect(){
    for(size_t i = 0; i < vector_.size(); ++i){
         std::cout << vector_[i] << " ";
    }
    std::cout << std::endl;
}

size_t Vector::GetSizeVect(){
    return vector_.size();
}

double Vector::GetValue(int indx){
    return vector_[indx];
}

////////////////////////////////////////////////////////////

Matrix::Matrix(){

}

Matrix::Matrix(std::vector<std::vector<double>> &x){
    matrix_ = x;
}

Matrix Matrix::addMat(Matrix &x){
    std::vector<std::vector<double>> msum 
         (matrix_.size(), std::vector<double>(matrix_.size()));
    for(size_t i = 0; i < matrix_.size(); ++i){
         if(matrix_.size() != x.matrix_.size()){
 	      std::cout << "Check size!" << std::endl;
              break;
         }
	 for(size_t j = 0; j < matrix_.size(); ++j){
              msum[i][j] = matrix_[i][j] + x.matrix_[i][j]; 
         }
    }
   
    Matrix msm(msum);
    return msm;
}

Matrix Matrix::subMat (Matrix &x){
    std::vector<std::vector<double>> msub 
         (matrix_.size(), std::vector<double>(matrix_.size()));
    for(size_t i = 0; i < matrix_.size(); ++i){
         if(matrix_.size() != x.matrix_.size()){
              std::cout << "Check size!" << std::endl;
              break;
         }
	 for(size_t j = 0; j < matrix_.size(); ++j){
	      msub[i][j] = matrix_[i][j] - x.matrix_[i][j]; 
         }
    }
  
    Matrix msb(msub);
    return msb;
}

Vector Matrix::mdotv(Vector &x){
    std::vector<double> dotMV (x.GetSizeVect());              
    for(size_t i = 0; i < x.GetSizeVect(); ++i){              
         if(x.GetSizeVect() != matrix_.size()){
 	      std::cout << "Check size!" << std::endl;
              break;
         }
         double num = {0};
	 for(size_t j = 0; j < x.GetSizeVect(); ++j){
	      num = num + x.GetValue(j)*matrix_[j][i]; 
	 }
	 dotMV[i] = num;
    }
  
    Vector mv(dotMV);
    return mv;	
}

Matrix Matrix::mdotm (Matrix &x){
    std::vector<std::vector<double>> dotMM 
         (matrix_.size(), std::vector<double>(matrix_.size()));
    std::vector<double> v1;
    if(x.matrix_.size() != matrix_.size()){
         std::cout << "Check size!" << std::endl;
    }
    for(size_t i = 0; i < matrix_.size(); ++i){
         for(size_t k = 0; k < matrix_.size(); ++k){
                   double num = {0};
	           for(size_t j = 0; j < matrix_.size(); ++j){
                        if(x.matrix_.size() != matrix_.size()){
                             break;
                        }
	                num = num + matrix_[i][j]*x.matrix_[j][k];
	           }
                   v1.push_back(num);
	 }
    }

    for(size_t i = 0; i< dotMM.size(); ++i){
         for(size_t j = 0; j< dotMM.size(); ++j){
  	      dotMM[i][j] = v1[j+(i*dotMM.size())];
         }
    }
    Matrix mm(dotMM);
    return mm;	
}

void Matrix::printMat(){ 
    for(size_t i = 0; i < matrix_.size(); ++i){
         for(size_t j = 0; j < matrix_.size(); ++j){
              std::cout << matrix_[i][j] << " "; 
         }
    std::cout <<  std::endl;
    }
}

////////////////////////////////////////////////////////////

#endif /*_LINALG_CPP_ */

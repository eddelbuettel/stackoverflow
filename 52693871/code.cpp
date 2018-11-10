#include <RcppArmadillo.h>
#include<omp.h>
#include<Rcpp.h>

using namespace Rcpp;
using namespace arma;

// [[Rcpp::plugins(openmp)]]
// [[Rcpp::depends(RcppArmadillo)]]


// [[Rcpp::export]]
sp_mat sp_sp_gc(const arma::sp_mat &A, const arma::sp_mat &B, double p){

  // This function evaluates A * B where both A & B are sparse and the resultant
  // product is also sparse

  // define matrix sizes
  const int mA= A.n_rows;
  const int nB= B.n_cols;

  // number of non-zeros in the resultant matrix
  const int nnzC = ceil(mA * nB * p);

  // initialize colptr, row_index and value vectors for the resultant sparse matrix
  urowvec colptrC(nB+1);
  colptrC.zeros();
  urowvec rowvalC(nnzC);
  rowvalC.zeros();
  colvec nzvalC(nnzC);

  //setenv("OMP_STACKSIZE","500M",1);

  // counters and other variables
  unsigned int i, jp, j, kp, k, vp; 
  unsigned int ip = 0;
  double nzB, nzA; 
  ivec xb(mA);
  xb.fill(-1);
  vec x(mA);

  // loop logic: outer loop over columns of B and inner loop over columns of A and then aggregate

//  #pragma omp parallel for shared(colptrC,rowvalC,nzvalC,x,xb,ip,A,B) private(j,nzA,nzB,kp,i,jp,kp,k,vp) default(none) schedule(auto) 
  for(i=0; i< nB; i++) { 

    colptrC.at(i) = ip;

       for ( jp = B.col_ptrs[i]; jp < B.col_ptrs[i+1]; jp++) {

              j = B.row_indices[jp];
              nzB = B.values[jp]; 

            for ( kp = A.col_ptrs[j]; kp < A.col_ptrs[j+1]; kp++ ){

                 k = A.row_indices[kp];
                 nzA = A.values[kp];

                   if (xb.at(k) != i){
                         rowvalC.at(ip) = k;
                         ip +=1;
                         xb.at(k) = i;
                         x.at(k) = nzA * nzB;
                  } else {
                         x.at(k) += nzA * nzB;
                 }
            }
         }

      // put in the value vector of resultant matrix 
      for ( vp= colptrC.at(i); vp <= (ip-1); vp++ ) {
         nzvalC.at(vp) = x(rowvalC.at(vp)); 
       }

  }

  // resize and put in the spMat container 
  colptrC.at(nB) = ip; 
  sp_mat C(rowvalC.subvec(0,(ip-1)),colptrC,nzvalC.subvec(0,(ip-1)),mA,nB);

  return C;

}  


 // [[Rcpp::export]]
sp_mat sp_sp_arma(const sp_mat &A, const sp_mat &B){
  return A * B; 
} 


// [[Rcpp::export]]
mat dense_dense_arma(const mat &A, const mat &B){
  return A * B; 
} 

/*** R
library(Matrix)
library(microbenchmark) 

## define two matrices
m <-1000
n <-6000
p <-2000

A <- matrix(runif(m*n),m,n)
B <- matrix(runif(n*p),n,p)
A[abs(A)> .01] = B[abs(B)> .01] = 0
A <- as(A,'dgCMatrix')
B<- as(B,'dgCMatrix')
Adense <- as.matrix(A)
Bdense <- as.matrix(B) 

microbenchmark(sp_sp_gc(A,B,.5),
               sp_sp_arma(A,B),A%*%B,
               dense_dense_arma(Adense,Bdense),
               Adense %*% Bdense,
               Adense %*% B, times=100)
*/

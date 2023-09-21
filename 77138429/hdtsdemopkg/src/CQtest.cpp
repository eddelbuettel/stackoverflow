#include "hdts.h"
using namespace Rcpp;
 //CQ test
 //
 // [[Rcpp::export]]
 arma::vec CQtest(const arma::mat & y1, const arma::mat & y2)
 {
   int n1 = y1.n_cols;int n2 = y2.n_cols;
   arma::mat y1xy1t=y1.t()*y1;
   double sumx1tx1inej=arma::accu(y1xy1t)-arma::trace(y1xy1t);
   arma::mat y2xy2t=y2.t()*y2;
   double sumx2tx2inej=arma::accu(y2xy2t)-arma::trace(y2xy2t);
   arma::mat y1xy2t=y1.t()*y2;
   double sumx1tx2=arma::accu(y1xy2t);
   double Tn=sumx1tx1inej/(n1*(n1-1))+sumx2tx2inej/(n2*(n2-1))-2*sumx1tx2/(n1*n2);

   double tempsum=0.0;
   arma::colvec y1sum=arma::sum(y1,1);//add columns
   //constants for speed up
   int n1_1=n1-1;
   int n2_1=n2-1;
   int n1_2=n1-2;
   int n2_2=n2-2;

   for(int j=0;j<n1;j++)
   {
     arma::colvec y1_j=y1.col(j);
     for(int k=j+1;k<n1;k++)
     {
       arma::colvec y1_k=y1.col(k);
       arma::colvec meanxiexjk = (y1sum-y1_j-y1_k)/n1_2;
       tempsum+=arma::as_scalar(y1_k.t()*(y1_j-meanxiexjk)*y1_j.t()*(y1_k-meanxiexjk));
     }
   }
   double trsigma12hat = (tempsum+tempsum)/(n1*(n1_1));

   tempsum=0.0;
   arma::colvec y2sum=arma::sum(y2,1);//add columns
   for(int j=0;j<n2;j++)
   {
     arma::colvec y2_j=y2.col(j);
     for(int k=j+1;k<n2;k++)
     {
       arma::colvec y2_k=y2.col(k);
       arma::colvec meanxiexjk = (y2sum-y2_j-y2_k)/n2_2;
       tempsum+=arma::as_scalar(y2_k.t()*(y2_j-meanxiexjk)*y2_j.t()*(y2_k-meanxiexjk));
     }
   }
   double trsigma22hat = (tempsum+tempsum)/(n2*(n2_1));

   tempsum=0.0;
   for(int l=0;l<n1;l++)
   {
     arma::colvec y1_l=y1.col(l);
     arma::colvec meanx1exl = (y1sum-y1_l)/n1_1;
     for(int k=0;k<n2;k++)
     {
       arma::colvec y2_k=y2.col(k);
       arma::colvec meanx2exk = (y2sum-y2_k)/n2_1;
       tempsum+=arma::as_scalar(y2_k.t()*(y1_l-meanx1exl)*y1_l.t()*(y2_k-meanx2exk));
     }
   }
   double trsigma1sigma2hat=tempsum/(n1*n2);
   double sigman12hat=2.0/(n1*(n1_1))*trsigma12hat+2.0/(n2*(n2_1))*trsigma22hat+4.0/(n1*n2)*trsigma1sigma2hat;
   double stat=Tn/sqrt(sigman12hat);//Qn
   arma::vec stats(2);
   stats(0)=stat;
   stats(1)=Tn;
   return stats;
 }

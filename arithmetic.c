/////////////////////////////////////////////////////////////////////////////////
//  File: arithmetic.c
//  Desc: Stores all functions to manipulate the polynomial(s)
//        1) Addition
//        2) Subtraction
//        3) Multiplication
//        4) Division
//        5) Normalization
//        6) Order
//
//  Author: Group 3
//  ID: 13131567
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 
#include <stdio.h>

#include "polynomial.h"

/*
  Changelog
  24/11/14
  -Changed arithmetic functions to use new create polynomial function
 */
/*
  Add two polynomials. All assignments are done by pass by reference.

  @param polynomial *a address of the first polynomial
  @param polynomial *b address of the second polynomial
  @param polynomial *out address of the resultant polynomial

 */
polynomial add(polynomial *a, polynomial *b){
  //initialise array with proper allocated memory
  //macro found in header, finds the two max
  int size = MAX(a->length, b->length);
  double data[size];
  polynomial out;
  //loop through both polynomials, add each element
  for(int i = 0; i < size; i++){
    //check if each arrays are finished
    if( i < a->length && i < b->length){
      //store the sum of the current elements
      //in the new polynomial to be returned
      data[i] = a->poly[i] + b->poly[i];
    }else{
      //throw in whatever's left if one of the arrays are exhausted
      if( a->length > b->length){
	data[i] = a->poly[i];
      }else{
	data[i] = b->poly[i];
      }
    }
  }
  createPolynomial(&out,size,data);
  return out;
}

/*
  Subtract two polynomials. All assignments are done by pass by reference.
 
  @param polynomial *a address of the first polynomial
  @param polynomial *b address of the second  polynomial
  @result returns the resulting polynomial

 */
polynomial subtract(polynomial *a, polynomial *b){
  //initialise array with proper allocated memory
  int size = MAX(a->length, b->length);
  polynomial out;
  double data[size];

  //loop through both polynomials, subtract  each element
  for(int i = 0; i < size; i++){
    //check if each arrays are finished
    if( i < a->length && i < b->length){

      //store the sum of the current elements
      //in the new polynomial to be returned
      data[i] = a->poly[i] - b->poly[i];
    }else{
      //throw in whatever's left if one of the arrays are exhausted
      if( a->length > b->length){
	data[i] = a->poly[i];
      }else{
	data[i] = b->poly[i];
      }
    }
  }
  createPolynomial(&out,size,data);
  return out;
}

/*
  Multiplies a polynomial by a double
 
  @param polynomial *a address of the polynomial
  @param double double_coeff used to multiply the polynomial
  @returns the resulting polynomial value
 */
polynomial multiply(polynomial *a, double double_coeff){
  //initialize poly array with correct memory allocation
  double data[a->length];
  int current_a;
  polynomial out;
  //loop through poly 'a' and each element 
  //multiplied by the double coeff
  for(int i = 0; i < a->length; i++){
    //store current value of poly coeff
    current_a = a->poly[i];
    //at each iteration store the evaluation to result
    data[i] = (current_a)*(double_coeff);
  }
  createPolynomial(&out,a->length,data);
  return out;
}

/*
  Divide a polynomial by a double

  @param polynomial *a address of the polynomial 'a'
  @param double_coeff used to divide the polynomial
  @result is a polynomial
 */
polynomial divide(polynomial *a, double double_coeff){
  //initialize poly array with correct memory allocation
  polynomial out;
  double data[a->length];
  int current_a;
  //loop through poly 'a' and each element 
  //diveded by the double coeff
  for(int i = 0; i < a->length; i++){
    //store current value of poly coeff
    current_a = a->poly[i];

    //at each iteration store the evaluation to the 
    //corresponding address for the poly array
    data[i] = (current_a)/(double_coeff);
  }
  createPolynomial(&out,a->length,data);
  return out;
}

/*
  Normalize a polynomial
  
  @param polynomial *a the address of the polynomial
  @param polynomial *out the address of the resultant polynomial
 */
polynomial normalise(polynomial *a){
  double norm;
  polynomial out;
  //find highest order with a valid coeff
  //find the max which will become the normalising coeff
  //loop will stop assigning values to the normal coeff
  //at higher orders if they are 0.
  for(int i = 0; i < a->length; i++){
    if(a->poly[i] != 0)
      norm = a->poly[i];
  }

  //use divide function from before :)
  out = divide(a, norm);

  return out;
}


/*
  Order of the polynomial

  @param polynomial *a address of the polynomial
  @return the order of the polynomial
*/
int order(polynomial *a){
  //length stores the length of the array rather than order so
  //we subtract one to give the right answer
  return a->length - 1; 
}

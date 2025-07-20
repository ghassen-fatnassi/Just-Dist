#pragma once
#include <Eigen/Dense>

using Matrix = Eigen::MatrixXf; 
/*
I chose it to be a matrixXf to take account of the dimension of the batch 
(without it the activations would be vectors only , 
and these functions are applied on activations)
*/ 

Matrix relu(const Matrix& input);
Matrix relu_grad(/**/);

Matrix linear(const Matrix& input,const Matrix& weight,const Matrix& bias);
Matrix linear_grad(const Matrix& grad_output,const Matrix& input,const Matrix& weight);

Matrix softmax(const Matrix& input);
Matrix softmax_grad(/**/);//the derivative of softmax at this point

float mse_loss(const Matrix& output,const Matrix& ground, int batch_size);
Matrix mse_loss_grad(const Matrix& output,const Matrix& ground, int batch_size);

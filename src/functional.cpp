#pragma once
#include <Eigen/Dense>
#include <cmath>
#include <numbers>

using Matrix = Eigen::MatrixXf;
using Vector = Eigen::VectorXf;
/*
I chose it to be a matrixXf to take account of the dimension of the batch 
(without it the activations would be vectors only , 
and these functions are applied on activations)
regardless of whether this batch approach is correct or not now , i'll go with it and suppose
M.shape=(batch_size,d1,d2,d3..)
each row is one sample from the batch
*/ 

Matrix relu(const Matrix& input)
{
    return input.cwiseMax(0.0f);
}

Matrix relu_grad(/**/);

Matrix linear(const Matrix& input,const Matrix& weight,const Matrix& bias)
{
    return input * weight.transpose() + bias;
}
Matrix linear_grad(const Matrix& grad_output,const Matrix& input,const Matrix& weight);

Matrix softmax(const Matrix& input)
{
    Vector maxs=input.rowwise().maxCoeff();
    Matrix normalized=input.colwise()-maxs;
    Matrix input_exp=normalized.array().exp(); //look into this , why .array() , i know to differentiate between A² and a[i]² but still , there should be naother reason
    return input_exp.colwise()/input_exp.rowwise().sum();
}

Matrix softmax_grad(/**/);

float mse_loss(const Matrix& output,const Matrix& ground, int batch_size)
{
    return (output-ground).array().pow(2).sum()/batch_size;
}
Matrix mse_loss_grad(const Matrix& output,const Matrix& ground, int batch_size);

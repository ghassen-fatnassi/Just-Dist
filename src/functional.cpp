#include <Eigen/Dense>

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
    Vector row_max = input.rowwise().maxCoeff();
    Matrix stabilized = input.array().colwise() - row_max.array();
    Matrix exps = stabilized.array().exp();
    Vector exps_row_sum = exps.rowwise().sum();
    return exps.array().colwise() / exps_row_sum.array();
}


Matrix softmax_grad(/**/);

float mse_loss(const Matrix& output,const Matrix& ground, int batch_size)
{
    return (output-ground).array().pow(2).sum()/output.rows();
}
Matrix mse_loss_grad(const Matrix& output,const Matrix& ground, int batch_size);

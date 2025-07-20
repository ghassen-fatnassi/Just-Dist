#pragma once
#include <Eigen/Dense>
#include <random>
#include <functional.hpp>
#include <map>
#include <vector>
#include <string>

using Matrix = Eigen::MatrixXf;
using Vector = Eigen::VectorXf;

class Parameter{

public:
    Matrix _data;
    Matrix _grad;
    int _requires_grad;

    Parameter(Matrix data,int requires_grad/*actual bool*/)
    {
        _data=data;//this is a reference to the current class , not the class itself
        _grad=data.setZero();//just to make sure they are same dims and zeroe'd out so we can accumulate gradient
        _requires_grad=requires_grad;
    };//recheck whether to make this const Matrix&
    //overload cout<< here
};

class Module{
public:
    std::map<std::string,Parameter> _params;
    std::map<std::string,Matrix> _cache;
    int _training;
    Module()
    {
        //no need to initialize the other 2 member variables ,maps are empty by design
        _training=1;//defaults to training (common practice)
    };
    /*
    a quick explanation of pure virtual functions for future reference:
    virtual=> Allows the method to be overridden in a derived class. Enables runtime polymorphism (virtual dispatch).
    const => guarantees the method will not modify Module's member variables
    =0 => makes this method "pure virtual" => forces any subclass to implement this method (the other scenario is the child class doesn't impelemnt is declared as abstract => =0 prevents this behavior)*/
    //virtual void method() const =0;
    virtual Matrix forward(Matrix inputs,int mubatch_id)=0; //no const here since we might change _cache (since we are caching the activations in FWPROP)
    virtual void backward(Matrix dout,int mubatch_id)=0;
    void train(){
        _training=1;
    }
    void eval(){
        _training=0;
    }
    void zero_grad(){
        for(auto elm:_params){elm.second._grad.setZero();} //this line taught me that member attributes/methods in cpp defaukt to private
    }
    std::vector<Parameter> parameters(){
        std::vector<Parameter> out;
        for(auto elm:_params){out.push_back(elm.second);}
        return out;
    }
};

class ReLU: Module
{
    Matrix forward(Matrix inputs,int mubatch_id)
    {
        if(_training)//gotta cache output for backprop later => check if we training or evaluating
        {
            std::string key="bitmask_";
            key+=std::to_string(mubatch_id);
            _cache[key]=(inputs.array()>0.0f).cast<float>(); //this straightforward since the derivative of relu is either 1 or 0 (ik it as heaviside)
        }
        return relu(inputs);
    }
    void backward(Matrix dout,int mubatch_id)
    {

    }
    //overload cout<< here to print "ReLU()";
};

class Softmax: Module
{
    Matrix forward(Matrix inputs,int mubatch_id)
    {
        if(_training)//gotta cache output for backprop later => check if we training or evaluating
        {
            std::string key="input_";
            key+=std::to_string(mubatch_id);
            _cache[key]=inputs; //this straightforward since the derivative of relu is either 1 or 0 (ik it as heaviside)
        }
        return softmax(inputs);
    }
    void backward(Matrix dout,int mubatch_id)
    {

    }
    //overload cout<< here to print "Softmax()";
};

class Linear: Module
{};

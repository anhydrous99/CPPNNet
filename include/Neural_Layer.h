//
// Created by Armando Herrera III
// Structure for a neuron layer of a Network
//

#ifndef CPPNNET_NEURAL_LAYER_H
#define CPPNNET_NEURAL_LAYER_H

#include <functional>
#include <memory>
#include <vector>
#include <Eigen/Core>

typedef std::function<float(float)> function;
typedef Eigen::MatrixXf Ematrix;
typedef Eigen::VectorXf Evector;

class Neural_Layer : public std::enable_shared_from_this<Neural_Layer> {
private:
  typedef std::shared_ptr<Neural_Layer> Neural_Ptr;

  // Weights Matrix
  Ematrix _w;
  // Bias Vector
  Evector _b;
  // Activation Function
  function _activ_func = [](float x) { return x; };
  // Pointer to Previous Layer
  Neural_Ptr _prev_layer;

  // Function to get vector of pointer to all layers
  std::vector<Neural_Ptr> GetVecPtrs();

  // Gets the number of weights and biases
  long parameter_count();

public:
  // Constructors
  Neural_Layer(Ematrix Weights, Evector Bias, Neural_Ptr previous_layer, function activation_function);

  Neural_Layer(Ematrix Weights, Evector Bias, Neural_Ptr previous_layer);

  Neural_Layer(Ematrix Weights, Evector Bias, function activation_function);

  Neural_Layer(Ematrix Weights, Evector Bias);

  Neural_Layer(int nneurons, int ninputs, Neural_Ptr previous_layer, function activation_function);

  Neural_Layer(int nneurons, int ninputs, Neural_Ptr previous_layer);

  Neural_Layer(int nneurons, int ninputs, function activation_function);

  Neural_Layer(int nneurons, int ninputs);

  ~Neural_Layer() = default;

  Evector feedforward(Evector input);

  std::vector<Evector> feedforward_batch(std::vector<Evector> input);

  // Mean Square Error
  float mse(const std::vector<Evector> &input, const std::vector<Evector> &target);

  // Root Mean Square Error
  float rmse(const std::vector<Evector> &input, const std::vector<Evector> &target);

  // Mean Absolute Error
  float mae(const std::vector<Evector> &input, const std::vector<Evector> &target);

  // Mean Percent Error
  float mpe(const std::vector<Evector> &input, const std::vector<Evector> &target);

  // Mean Absolute Percent Error
  float mape(const std::vector<Evector> &input, const std::vector<Evector> &target);

  // coefficient of determination (R squared)
  float r2(const std::vector<Evector> &input, const std::vector<Evector> &target);

  // Akaike information criterion (AIC)
  float aic(const std::vector<Evector> &input, const std::vector<Evector> &target);

  // Corrected Akaike information criterion (AICc)
  float aicc(const std::vector<Evector> &input, const std::vector<Evector> &target);

  // Bayesian information criterion (BIC)
  float bic(const std::vector<Evector> &input, const std::vector<Evector> &target);

  Ematrix GetWeights() { return _w; }

  Evector GetBiases() { return _b; }

  friend class Neural_Trainer;

  friend class MSGD_Neural_Trainer;
};

#endif // CPPNNET_NEURAL_LAYER_H

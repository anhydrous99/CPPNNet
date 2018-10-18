#ifndef NEURAL_LAYER_H
#define NEURAL_LAYER_H

#include <functional>
#include <memory>
#include <vector>

#include <Eigen/Core>

typedef std::function<float(float)> function;
typedef Eigen::MatrixXf Ematrix;
typedef Eigen::VectorXf Evector;

class Neural_Layer
{
private:
  typedef std::shared_ptr<Neural_Layer> Neural_Ptr;

  // Weights Matrix
  Ematrix _w;
  // Bias Vector
  Evector _b;
  // Activation Function
  function _activ_func = [](float x){ return x; };
  // Pointer to Previous Layer
  Neural_Ptr _prev_layer;
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

  ~Neural_Layer() {}

  Evector feedforward(Evector input);
  std::vector<Evector> feedforward_batch(std::vector<Evector> input);

  std::vector<Neural_Ptr> GetVecPtrs();

  Ematrix GetWeights() { return _w; }
  Evector GetBiases() { return _b; }

  friend class Neural_Trainer;
};

#endif // NEURAL_LAYER_H

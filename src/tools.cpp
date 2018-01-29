#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  VectorXd rmse(4);
  rmse << 0, 0, 0, 0;
  
  auto n = estimations.size();
  if (n == 0 || n != ground_truth.size()) {
    cout << "Invalid estimations and ground_truth" << endl;
    return rmse;
  }

  for (auto i = 0; i != n; i++) {
    VectorXd residual = estimations[i] - ground_truth[i];
    residual = residual.array() * residual.array();
    rmse += residual;
  }
  rmse /= n;
  rmse = rmse.array().sqrt();
  return rmse;
}
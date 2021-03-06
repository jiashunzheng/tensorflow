/* Copyright 2015 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef THIRD_PARTY_TENSORFLOW_CC_FRAMEWORK_GRADIENTS_H_
#define THIRD_PARTY_TENSORFLOW_CC_FRAMEWORK_GRADIENTS_H_

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"

namespace tensorflow {

// NOTE: This API is a work in progress and will likely be changing frequently.
//
// Given initial gradients 'grad_inputs' (which represent the symbolic partial
// derivatives of some loss function 'L' w.r.t 'outputs'), adds gradient nodes
// to the graph associated with 'scope', which compute (and return in
// 'grad_outputs') the symbolic partial derivatives of 'L' w.r.t 'inputs'.
//

// TODO(andydavis) Add overload of this function with no 'grad_inputs' arg.
// Implementation will fill in 'OnesLike' for all shapes in 'outputs'.
Status AddSymbolicGradients(const Scope& scope,
                            const std::vector<ops::Output>& outputs,
                            const std::vector<ops::Output>& inputs,
                            const std::vector<ops::Output>& grad_inputs,
                            std::vector<ops::Output>* grad_outputs);

}  // namespace tensorflow

#endif  // THIRD_PARTY_TENSORFLOW_CC_FRAMEWORK_GRADIENTS_H_

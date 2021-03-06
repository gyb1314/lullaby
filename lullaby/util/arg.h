/*
Copyright 2017 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS-IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef LULLABY_UTIL_ARG_H_
#define LULLABY_UTIL_ARG_H_

#include <functional>
#include <string>
#include <unordered_set>
#include "lullaby/util/string_view.h"

namespace lull {

// Definition of an "argument" that will be parsed by the ArgParser.
class Arg {
 public:
  // Defines an argument with a given name.
  explicit Arg(string_view name) : name_(name.to_string()) {}

  // Specifies a single character that can be used as an alternative name for
  // this argument.
  Arg& SetShortName(char c) {
    short_name_ = c;
    return *this;
  }

  // Specifies the number of arguments following this argument to consume and
  // associate with this argument.
  Arg& SetNumArgs(int num) {
    num_args_ = num;
    return *this;
  }

  // Sets the description for this argument to be displayed in a help string.
  Arg& SetDescription(string_view description) {
    description_ = description.to_string();
    return *this;
  }

  // Specifies that this argument is required.
  Arg& SetRequired() {
    required_ = true;
    return *this;
  }

  // Sets a default value for the argument if no argument is specified.s
  Arg& SetDefault(string_view defvalue) {
    default_value_ = defvalue.to_string();
    return *this;
  }

  // Returns the number of arguments to be consumed and associated with this
  // argument.
  int GetNumArgs() const { return num_args_; }

  // Returns true if this argument is required.
  bool IsRequired() const { return required_; }

  // Returns the short name for this argument.
  char GetShortName() const { return short_name_; }

  // Returns the (full) name for this argument.
  string_view GetName() const { return name_; }

  // Returns the description for this argument.
  string_view GetDescription() const { return description_; }

  // Returns the default value for this argument.
  string_view GetDefaultValue() const { return default_value_; }

 private:
  int num_args_ = 0;
  char short_name_ = 0;
  bool required_ = false;
  std::string name_;
  std::string description_;
  std::string default_value_;
};

}  // namespace lull

#endif  // LULLABY_UTIL_ARG_H_

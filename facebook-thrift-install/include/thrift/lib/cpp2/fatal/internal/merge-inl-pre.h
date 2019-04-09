/*
 * Copyright 2016-present Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

namespace apache {
namespace thrift {
namespace merge_into_detail {

template <typename T>
using remove_const_reference =
    typename std::remove_const<typename std::remove_reference<T>::type>::type;

template <typename T>
struct merge;
template <typename TypeClass>
struct merge_impl;

} // namespace merge_into_detail
} // namespace thrift
} // namespace apache

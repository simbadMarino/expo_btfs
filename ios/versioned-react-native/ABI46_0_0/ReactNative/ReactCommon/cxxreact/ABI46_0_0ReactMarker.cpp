/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "ABI46_0_0ReactMarker.h"

namespace ABI46_0_0facebook {
namespace ABI46_0_0React {
namespace ABI46_0_0ReactMarker {

#if __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif

LogTaggedMarker logTaggedMarker = nullptr;
LogTaggedMarker logTaggedMarkerBridgeless = nullptr;

#if __clang__
#pragma clang diagnostic pop
#endif

void logMarker(const ABI46_0_0ReactMarkerId markerId) {
  logTaggedMarker(markerId, nullptr);
}

void logMarkerBridgeless(const ABI46_0_0ReactMarkerId markerId) {
  logTaggedMarkerBridgeless(markerId, nullptr);
}

} // namespace ABI46_0_0ReactMarker
} // namespace ABI46_0_0React
} // namespace ABI46_0_0facebook

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#ifdef __cplusplus

#include "ABI46_0_0BitUtils.h"
#include "ABI46_0_0YGFloatOptional.h"
#include "ABI46_0_0Yoga-internal.h"

using namespace ABI46_0_0facebook::yoga;

struct ABI46_0_0YGLayout {
  std::array<float, 4> position = {};
  std::array<float, 2> dimensions = {{ABI46_0_0YGUndefined, ABI46_0_0YGUndefined}};
  std::array<float, 4> margin = {};
  std::array<float, 4> border = {};
  std::array<float, 4> padding = {};

private:
  static constexpr size_t directionOffset = 0;
  static constexpr size_t didUseLegacyFlagOffset =
      directionOffset + ABI46_0_0facebook::yoga::detail::bitWidthFn<ABI46_0_0YGDirection>();
  static constexpr size_t doesLegacyStretchFlagAffectsLayoutOffset =
      didUseLegacyFlagOffset + 1;
  static constexpr size_t hadOverflowOffset =
      doesLegacyStretchFlagAffectsLayoutOffset + 1;
  uint8_t flags = 0;

public:
  uint32_t computedFlexBasisGeneration = 0;
  ABI46_0_0YGFloatOptional computedFlexBasis = {};

  // Instead of recomputing the entire layout every single time, we cache some
  // information to break early when nothing changed
  uint32_t generationCount = 0;
  ABI46_0_0YGDirection lastOwnerDirection = ABI46_0_0YGDirectionInherit;

  uint32_t nextCachedMeasurementsIndex = 0;
  std::array<ABI46_0_0YGCachedMeasurement, ABI46_0_0YG_MAX_CACHED_RESULT_COUNT>
      cachedMeasurements = {};
  std::array<float, 2> measuredDimensions = {{ABI46_0_0YGUndefined, ABI46_0_0YGUndefined}};

  ABI46_0_0YGCachedMeasurement cachedLayout = ABI46_0_0YGCachedMeasurement();

  ABI46_0_0YGDirection direction() const {
    return ABI46_0_0facebook::yoga::detail::getEnumData<ABI46_0_0YGDirection>(
        flags, directionOffset);
  }

  void setDirection(ABI46_0_0YGDirection direction) {
    ABI46_0_0facebook::yoga::detail::setEnumData<ABI46_0_0YGDirection>(
        flags, directionOffset, direction);
  }

  bool didUseLegacyFlag() const {
    return ABI46_0_0facebook::yoga::detail::getBooleanData(
        flags, didUseLegacyFlagOffset);
  }

  void setDidUseLegacyFlag(bool val) {
    ABI46_0_0facebook::yoga::detail::setBooleanData(flags, didUseLegacyFlagOffset, val);
  }

  bool doesLegacyStretchFlagAffectsLayout() const {
    return ABI46_0_0facebook::yoga::detail::getBooleanData(
        flags, doesLegacyStretchFlagAffectsLayoutOffset);
  }

  void setDoesLegacyStretchFlagAffectsLayout(bool val) {
    ABI46_0_0facebook::yoga::detail::setBooleanData(
        flags, doesLegacyStretchFlagAffectsLayoutOffset, val);
  }

  bool hadOverflow() const {
    return ABI46_0_0facebook::yoga::detail::getBooleanData(flags, hadOverflowOffset);
  }
  void setHadOverflow(bool hadOverflow) {
    ABI46_0_0facebook::yoga::detail::setBooleanData(
        flags, hadOverflowOffset, hadOverflow);
  }

  bool operator==(ABI46_0_0YGLayout layout) const;
  bool operator!=(ABI46_0_0YGLayout layout) const { return !(*this == layout); }
};

#endif

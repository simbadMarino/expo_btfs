/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <folly/Portability.h>
#include <cstdint>
#include <cstring>

#ifndef ABI46_0_0RN_EXPORT
#define ABI46_0_0RN_EXPORT __attribute__((visibility("default")))
#endif

namespace ABI46_0_0facebook {
namespace ABI46_0_0React {

/*
 * Scripts given to the JS Executors to run could be in any of the following
 * formats. They are tagged so the executor knows how to run them.
 * Hermes bytecode bundles (as encoded by hermesc, not metro) are not treated
 * in a special way, they will be identified as ScriptTag::String.
 */
enum struct ScriptTag {
  String = 0,
  RAMBundle,
  MetroHBCBundle,
};

/**
 * RAM bundles and BC bundles begin with headers. For RAM bundles this is
 * 4 bytes, for BC bundles this is 12 bytes. This structure holds the first 12
 * bytes from a bundle in a way that gives access to that information.
 */
FOLLY_PACK_PUSH
struct FOLLY_PACK_ATTR BundleHeader {
  BundleHeader() {
    std::memset(this, 0, sizeof(BundleHeader));
  }

  union {
    struct {
      uint32_t value;
      uint32_t reserved_;
    } magic32;
    uint64_t magic64;
  };
  uint32_t version;
};
FOLLY_PACK_POP

/**
 * Takes the first 8 bytes of a bundle, and returns a tag describing the
 * bundle's format.
 */
ABI46_0_0RN_EXPORT ScriptTag parseTypeFromHeader(const BundleHeader &header);

/**
 * Convert an `ScriptTag` enum into a string, useful for emitting in errors
 * and diagnostic messages.
 */
ABI46_0_0RN_EXPORT const char *stringForScriptTag(const ScriptTag &tag);

/**
 * Check whether a given bundle is hermesc-generated bytecode
 */
ABI46_0_0RN_EXPORT bool isHermesBytecodeBundle(const BundleHeader &header);

} // namespace ABI46_0_0React
} // namespace ABI46_0_0facebook

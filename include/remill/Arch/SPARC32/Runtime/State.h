/*
 * Copyright (c) 2019 Trail of Bits, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#pragma clang diagnostic push
#pragma clang diagnostic fatal "-Wpadded"

#include "remill/Arch/Runtime/State.h"
#include "remill/Arch/Runtime/Types.h"

struct Reg final {
  uint32_t dword;
} __attribute__((packed));


union PtrReg final {
  uint32_t dword;
} __attribute__((packed));

static_assert(sizeof(PtrReg) == 4);

struct GPR {

  // Prevents LLVM from casting a `GPR` into an `i64` to access `I0`.
  volatile uint32_t _0;
  Reg i0;
  volatile uint32_t _1;
  Reg i1;
  volatile uint32_t _2;
  Reg i2;
  volatile uint32_t _3;
  Reg i3;
  volatile uint32_t _4;
  Reg i4;
  volatile uint32_t _5;
  Reg i5;
  volatile uint32_t _6;
  PtrReg i6;
  volatile uint32_t _7;
  Reg i7;

  volatile uint32_t _8;
  Reg l0;
  volatile uint32_t _9;
  Reg l1;
  volatile uint32_t _10;
  Reg l2;
  volatile uint32_t _11;
  Reg l3;
  volatile uint32_t _12;
  Reg l4;
  volatile uint32_t _13;
  Reg l5;
  volatile uint32_t _14;
  Reg l6;
  volatile uint32_t _15;
  Reg l7;

  volatile uint32_t _16;
  Reg o0;
  volatile uint32_t _17;
  Reg o1;
  volatile uint32_t _18;
  Reg o2;
  volatile uint32_t _19;
  Reg o3;
  volatile uint32_t _20;
  Reg o4;
  volatile uint32_t _21;
  Reg o5;
  volatile uint32_t _22;
  PtrReg o6;
  volatile uint32_t _23;
  Reg o7;

  volatile uint32_t _24;
  Reg g0;
  volatile uint32_t _25;
  Reg g1;
  volatile uint32_t _26;
  Reg g2;
  volatile uint32_t _27;
  Reg g3;
  volatile uint32_t _28;
  Reg g4;
  volatile uint32_t _29;
  Reg g5;
  volatile uint32_t _30;
  Reg g6;
  volatile uint32_t _31;
  Reg g7;
};

enum AlternativeSpaceIdentifier : uint32_t {
  ASI_PST8_PRIMARY = 0xc0,
  ASI_PST8_SECONDARY,
  ASI_PST16_PRIMARY,
  ASI_PST16_SECONDARY,
  ASI_PST32_PRIMARY,
  ASI_PST32_SECONDARY,
  ASI_FL8_PRIMARY = 0xd0,
  ASI_FL8_SECONDARY,
  ASI_FL16_PRIMARY,
  ASI_FL16_SECONDARY,
  ASI_BLOCK_COMMIT_PRIMARY = 0xe0,
  ASI_TWINX_P = 0xe2,
  ASI_TWINX_S,
  ASI_BLOCK_PRIMARY = 0xf0,
  ASI_BLOCK_SECONDARY,
};

struct alignas(8) FPURegs final {
  vec128_t v[8];
} __attribute__((packed));

static_assert(128 == sizeof(struct FPURegs),
              "Invalid packing of `struct FPURegs`.");

struct FSRReg final {
  volatile uint8_t _0;
  uint8_t cexc;
  volatile uint8_t _1;
  uint8_t aexc;
  volatile uint8_t _2;
  uint8_t fcc0;
  volatile uint8_t _3;
  uint8_t reserve;
  volatile uint8_t _4;
  uint8_t ftt;
  volatile uint8_t _5;
  uint8_t ver;
  volatile uint8_t _6;
  uint8_t ns;
  volatile uint8_t _7;
  uint8_t tem;
  volatile uint8_t _8;
  uint8_t rd;
  volatile uint8_t _9;
  uint8_t fcc1;
  volatile uint8_t _10;
  uint8_t fcc2;
  volatile uint8_t _11;
  uint8_t fcc3;
} __attribute__((packed));

static_assert(24 == sizeof(struct FSRReg),
              "Invalid packing of `struct FSRReg`.");

// Integer condition code register flags
struct ICCRFlags final {
  struct {
    volatile uint8_t _0;
    bool c;
    volatile uint8_t _1;
    bool v;
    volatile uint8_t _2;
    bool z;
    volatile uint8_t _3;
    bool n;
  } __attribute__((packed)) icc, xcc;
} __attribute__((packed));

union GSRFlags final {
  uint64_t flat;
  struct {
    uint64_t align : 3;
    uint64_t scale : 5;
    uint64_t reserved_0 : 17;
    uint64_t irnd : 2;
    uint64_t im : 1;
    uint64_t reserved_1 : 4;
    uint64_t mask : 32;
  } __attribute__((packed));
} __attribute__((packed));

struct ASR final {
  Reg asr7;
  volatile uint32_t _0;
  Reg asr8;
  volatile uint32_t _1;
  Reg asr9;
  volatile uint32_t _2;
  Reg asr10;
  volatile uint32_t _3;
  Reg asr11;
  volatile uint32_t _4;
  Reg asr12;
  volatile uint32_t _5;
  Reg asr13;
  volatile uint32_t _6;
  Reg asr14;
  volatile uint32_t _7;
  Reg asr15;
  volatile uint32_t _8;
  Reg asr16;
  volatile uint32_t _9;
  Reg asr17;
  volatile uint32_t _10;
  Reg asr18;
  volatile uint32_t _11;
  Reg asr19;
  volatile uint32_t _12;
  Reg asr20;
  volatile uint32_t _13;
  Reg asr21;
  volatile uint32_t _14;
  Reg asr22;
  volatile uint32_t _15;
  Reg asr23;
  volatile uint32_t _16;
  Reg asr24;
  volatile uint32_t _17;
  Reg asr25;
  volatile uint32_t _18;
  Reg asr26;
  volatile uint32_t _19;
  Reg asr27;
  volatile uint32_t _20;
  Reg asr28;
  volatile uint32_t _21;
  Reg asr29;
  volatile uint32_t _22;
  Reg asr30;
  volatile uint32_t _23;
  Reg asr31;
  volatile uint32_t _24;
} __attribute__((packed));

struct CSR {
  uint8_t ccc;
  uint8_t padding0;
  uint16_t padding1;
  uint32_t padding2;
} __attribute__((packed));

static_assert(8 == sizeof(struct CSR), "Invalid packing of `struct CSR`.");

struct PSR {
  uint64_t tpc;
  uint64_t tnpc;
  uint64_t tstate;
  uint64_t tick;
  uint64_t tba;
  volatile uint8_t _0;  //padding
  uint8_t tt;
  uint8_t tl;
  union {
    uint16_t pstate;
    struct {
      uint16_t res1 : 1;
      uint16_t ie : 1;
      uint16_t priv : 1;
      uint16_t am : 1;
      uint16_t pef : 1;
      uint16_t res2 : 1;
      uint16_t mm : 1;
      uint16_t tle : 1;
      uint16_t cle : 1;
      uint16_t res3 : 1;
      uint16_t res4 : 1;
      uint16_t tct : 1;
      uint16_t padding : 4;
    } __attribute__((packed)) ps;
  } __attribute__((packed));
  volatile uint8_t _1;
  uint8_t pil;
  uint8_t cwp;
  uint8_t cansave;
  volatile uint8_t _2;
  uint8_t canrestore;
  uint8_t cleanwin;
  uint8_t otherwin;
  volatile uint8_t _3;
  union {
    uint8_t wstate;
    struct {
      uint8_t normal : 2;
      uint8_t other : 3;
      uint8_t padding : 3;
    } __attribute__((packed)) ws;
  } __attribute__((packed));
  uint8_t gl;
} __attribute__((packed));

struct alignas(16) SPARC32State : public ArchState {
  volatile uint64_t _0;
  FPURegs fpreg;  // 128 bytes
  volatile uint64_t _1;
  GPR gpr;  // 256 bytes
  volatile uint64_t _2;
  ASR asr;  // 168 bytes
  volatile uint64_t _3;
  PSR psr;  // 56 bytes
  volatile uint64_t _4;
  FSRReg fsr;  // 24 bytes
  volatile uint32_t _5;
  Reg pc;  // 4 bytes
  volatile uint32_t _6;
  Reg next_pc;  // 4 bytes
  volatile uint32_t _7;
  Reg cwp;
  volatile uint32_t _8;
  Reg tick;
  volatile uint32_t _9;
  Reg yreg;
  volatile uint32_t _10;
  Reg ccs;
  volatile uint32_t _11;
  Reg pcr;
  volatile uint32_t _12;
  Reg pic;
  volatile uint32_t _13;
  Reg gsr;
  volatile uint32_t _14;
  Reg softint_set;
  volatile uint32_t _15;
  Reg softint_clr;
  volatile uint32_t _16;
  Reg softint;
  volatile uint32_t _17;
  Reg tick_cmpr;
  volatile uint32_t _18;
  Reg stick;
  volatile uint32_t _19;
  Reg stick_cmpr;
  volatile uint32_t _20;
  // fake register for sleigh
  uint8_t decompile_mode;
  volatile uint8_t _padding0[3];
};

struct State : public SPARC32State {};

#pragma clang diagnostic pop

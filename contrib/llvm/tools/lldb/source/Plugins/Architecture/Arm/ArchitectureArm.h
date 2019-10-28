//===-- ArchitectureArm.h ---------------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_PLUGIN_ARCHITECTURE_ARM_H
#define LLDB_PLUGIN_ARCHITECTURE_ARM_H

#include "lldb/Core/Architecture.h"

namespace lldb_private {

class ArchitectureArm : public Architecture {
public:
  static ConstString GetPluginNameStatic();
  static void Initialize();
  static void Terminate();

  ConstString GetPluginName() override;
  uint32_t GetPluginVersion() override;

  void OverrideStopInfo(Thread &thread) const override;

  lldb::addr_t GetCallableLoadAddress(lldb::addr_t load_addr,
                                      AddressClass addr_class) const override;

  lldb::addr_t GetOpcodeLoadAddress(lldb::addr_t load_addr,
                                    AddressClass addr_class) const override;

private:
  static std::unique_ptr<Architecture> Create(const ArchSpec &arch);
  ArchitectureArm() = default;
};

} // namespace lldb_private

#endif // LLDB_PLUGIN_ARCHITECTURE_ARM_H

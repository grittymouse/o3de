/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include "ScriptCanvasMultiplayerSystemComponent.h"
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

namespace ScriptCanvasMultiplayer
{
    class ScriptCanvasMultiplayerModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(ScriptCanvasMultiplayerModule, "{6cf9ae34-9d26-45cf-b48e-ffc7d8f0c56e}", AZ::Module);
        AZ_CLASS_ALLOCATOR(ScriptCanvasMultiplayerModule, AZ::SystemAllocator, 0);

        ScriptCanvasMultiplayerModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                ScriptCanvasMultiplayerSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<ScriptCanvasMultiplayerSystemComponent>(),
            };
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(Gem_ScriptCanvasMultiplayer, ScriptCanvasMultiplayer::ScriptCanvasMultiplayerModule)

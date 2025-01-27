// Copyright(c) 2019 - 2020, #Momo
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met :
// 
// 1. Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and /or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include "Platform/GraphicAPI.h"
#include "Utilities/ECS/Component.h"
#include "LightBase.h"

namespace MxEngine
{
    class SpotLight : public LightBase
    {
        MAKE_COMPONENT(SpotLight);

        float innerAngle  = 35.0f;
        float innerCos    = std::cos(Radians(innerAngle));
        float outerAngle  = 45.0f;
        float outerCos    = std::cos(Radians(outerAngle));
        float maxDistance = 1000.0f;

        void LoadDepthTexture();
    public:
        TextureHandle DepthMap;

        SpotLight() = default;

        [[nodiscard]] bool IsCastingShadows() const;
        void ToggleShadowCast(bool value);

        Vector3 Direction = MakeVector3(0.0f, -1.0f, 0.0f);

        [[nodiscard]] float GetInnerAngle() const;
        [[nodiscard]] float GetOuterAngle() const;
        [[nodiscard]] float GetInnerCos() const;
        [[nodiscard]] float GetOuterCos() const;
        [[nodiscard]] float GetMaxDistance() const;
        void SetInnerAngle(float angle);
        void SetOuterAngle(float angle);
        void SetMaxDistance(float zvalue);

        [[nodiscard]] Matrix4x4 GetMatrix(const Vector3& position) const;
        [[nodiscard]] Matrix4x4 GetPyramidTransform(const Vector3& position) const;
    };
}
// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "SpriteComponent.hpp"
#include "Shader.hpp"

SpriteComponent::SpriteComponent():
	,mTexture(nullptr)
	,mTexWidth(0)
	,mTexHeight(0)
{
	//mOwner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	//mOwner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw(Shader* shader)
{
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

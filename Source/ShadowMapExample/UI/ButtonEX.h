// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include <functional>
#include "ButtonEX.generated.h"

UCLASS()
class SHADOWMAPEXAMPLE_API UButtonEX : public UButton
{
	GENERATED_BODY()
	
public:
	UButtonEX();

protected:
	UFUNCTION()
	void Do();
	
public:
	std::function<void()> _OnClicked_Lambda;
	
};

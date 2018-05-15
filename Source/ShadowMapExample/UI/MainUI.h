// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUI.generated.h"

/**
 * 
 */
UCLASS()
class SHADOWMAPEXAMPLE_API UMainUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UMainUI(const FObjectInitializer& ObjectInitializer);
	
protected:
	UClass _NPCSpawnerClass;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUI.generated.h"

class UPanelWidget;

UCLASS()
class SHADOWMAPEXAMPLE_API UMainUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UMainUI(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnNPC(int count);

	UFUNCTION(BlueprintCallable)
	void InitialCountButtons(UPanelWidget* parent);

};

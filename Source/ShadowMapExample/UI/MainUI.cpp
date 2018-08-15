// Fill out your copyright notice in the Description page of Project Settings.

#include "MainUI.h"
#include "UObject/ConstructorHelpers.h"
#include "PanelWidget.h"
#include "ButtonEX.h"
#include "TextBlock.h"
#include <stdlib.h>


UMainUI::UMainUI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UMainUI::InitialCountButtons(UPanelWidget* parent)
{
	if(!parent)
		return;

	for(int i = 0; i < parent->GetChildrenCount(); ++i)
	{
		UButtonEX* button = Cast<UButtonEX>(parent->GetChildAt(i));
		if(!button)
			continue;

		UTextBlock* textBlock = Cast<UTextBlock>(button->GetChildAt(0));
		if(!textBlock)
			continue;

		int count = FCString::Atoi(*textBlock->Text.ToString());
		button->_OnClicked_Lambda = [=]()
		{
			SpawnNPC(count);
		};
	}
}

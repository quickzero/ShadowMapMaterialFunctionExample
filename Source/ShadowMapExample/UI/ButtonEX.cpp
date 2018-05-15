// Fill out your copyright notice in the Description page of Project Settings.

#include "ButtonEX.h"


UButtonEX::UButtonEX()
{
	OnClicked.AddDynamic(this, &UButtonEX::Do);
}

void UButtonEX::Do()
{
	if(_OnClicked_Lambda)
		_OnClicked_Lambda();
}


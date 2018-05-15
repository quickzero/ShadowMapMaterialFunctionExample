// Fill out your copyright notice in the Description page of Project Settings.

#include "MainUI.h"


UMainUI::UMainUI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ConstructorHelpers::FClassFinder finder("Blueprint'/Game/TopDownCPP/Blueprints/NPC_SPAWNER.NPC_SPAWNER'");
	if(finder.Succeeded())
		_NPCSpawnerClass = finder.Class;
}

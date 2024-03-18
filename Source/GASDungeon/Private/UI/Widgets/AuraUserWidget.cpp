// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController=InWidgetController;
	//after setting the widget controller, call the event - WidgetControllerSet
	WidgetControllerSet();
}

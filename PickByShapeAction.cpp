#include "PickByShapeAction.h"

PickByShapeAction::PickByShapeAction(ApplicationManager* pApp):Action(pApp)
{
	PickedFig = pManager->Rand();
}

void PickByShapeAction::ReadActionParameters()
{
}

void PickByShapeAction::Execute()
{
}

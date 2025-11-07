//========================================================================================
//  
//  $File: $
//  
//  Owner: 
//  
//  $Author: $
//  
//  $DateTime: $
//  
//  $Revision: $
//  
//  $Change: $
//  
//  Copyright 1997-2012 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#include "VCPlugInHeaders.h"

// Interface includes:
#include "IControlView.h"
#include "IPanelControlData.h"
#include "IPanorama.h"
#include "IScript.h"
#include "IScriptRequestData.h"
#include "IWorkspace.h"

// General includes:
#include "CAlert.h"
#include "CScriptProvider.h"
#include "LayoutUIID.h" // for kLayoutWidgetBoss

// Project includes:
#include "KESLVLScriptingDefs.h"
#include "KESLVLID.h"

class KESLVLScriptProvider : public CScriptProvider
{
public:
	// Constructor.
	// param boss interface ptr from boss object on which this interface is aggregated.
	KESLVLScriptProvider(IPMUnknown* boss) : CScriptProvider(boss) {};

	// Destructor. Does nothing.
	~KESLVLScriptProvider() {}

	// This method is called if a provider can handle a property.
	// @param scriptID_property identifies the ID of the property to handle.
	// @param iScriptRequestData identifies an interface pointer used to extract data.
	// @param iScript_parent identifies an interface pointer on the script object representing the parent of the application object.
	virtual ErrorCode AccessProperty
		(ScriptID scriptID_property, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);

private:
	// Layout view location
	virtual ErrorCode AccessContentLocationAtFrameOrigin
		(ScriptID scriptID_property, IScriptRequestData* iScriptRequestData, IScript* iScript_parent, bool16 XYFlg);
};


// CREATE_PMINTERFACE
// Binds the C++ implementation class onto its ImplementationID making the C++ code callable by the application.
CREATE_PMINTERFACE(KESLVLScriptProvider, kKESLVLScriptProviderImpl)

// AccessProperty
ErrorCode KESLVLScriptProvider::AccessProperty
	(ScriptID scriptID_property, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;
	bool16 X = 0, Y = 1;

	switch (scriptID_property.Get())
	{
		case p_LocationAtFrameOriginX:
			status = this->AccessContentLocationAtFrameOrigin(scriptID_property, iScriptRequestData, iScript_parent, X);
			break;
		case p_LocationAtFrameOriginY:
			status = this->AccessContentLocationAtFrameOrigin(scriptID_property, iScriptRequestData, iScript_parent, Y);
			break;
		default:
			status = CScriptProvider::AccessProperty(scriptID_property, iScriptRequestData, iScript_parent);
	}

	return status;
}

// Access content location at frame origin
ErrorCode KESLVLScriptProvider::AccessContentLocationAtFrameOrigin
	(ScriptID scriptID_property, IScriptRequestData* iScriptRequestData, IScript* iScript_parent, bool16 XYFlg)
{
	ErrorCode status = kFailure;
	bool16 X = 0, Y = 1;

	do {
		// ---------------------------------------------------------------------------------------
		// Get top-left position
		InterfacePtr<IPanelControlData> iPanelControlData(iScript_parent, ::UseDefaultIID());
		if (!iPanelControlData) break;

		// kLayoutWidgetBoss is a BOSS representing a layout view.
		IControlView* iControlView = iPanelControlData->FindWidget(kLayoutWidgetBoss);
		if (!iControlView) break;

		InterfacePtr<IPanorama> iPanorama(iControlView, ::UseDefaultIID());
		if (!iPanorama) break;

		PMPoint pMPoint_viewTopLeft = iPanorama->GetContentLocationAtFrameOrigin();

		// ---------------------------------------------------------------------------------------
		// Request
		ScriptData scriptData;
		if (iScriptRequestData->IsPropertyGet()) // Get
		{
			// ---------------------------------------------------------------------------------------
			// Append return data
			if (XYFlg == X)
			{
				scriptData.SetPMReal(pMPoint_viewTopLeft.X());
			}
			else if (XYFlg == Y)
			{
				scriptData.SetPMReal(pMPoint_viewTopLeft.Y());
			}

			iScriptRequestData->AppendReturnData(iScript_parent, scriptID_property, scriptData);
		}
		else if (iScriptRequestData->IsPropertyPut()) // Set
		{
			status = iScriptRequestData->ExtractRequestData(scriptID_property.Get(), scriptData);
			if (status != kSuccess) break;

			// ---------------------------------------------------------------------------------------
			// Scroll
			PMReal pMReal_point;
			status = scriptData.GetPMReal(&pMReal_point);
			if (status != kSuccess) break;

			if (XYFlg == X)
			{
				pMPoint_viewTopLeft.X(pMReal_point);
			}
			else if (XYFlg == Y)
			{
				pMPoint_viewTopLeft.Y(pMReal_point);
			}

			iPanorama->ScrollContentLocationToFrameOrigin(pMPoint_viewTopLeft);
		}
		status = kSuccess;

	} while (kFalse);

	return status;
}
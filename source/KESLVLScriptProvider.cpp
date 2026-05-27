#include "VCPlugInHeaders.h"

// Interface includes:
#include "IControlView.h"
#include "IPanelControlData.h"
#include "IPanorama.h"
#include "IScript.h"
#include "IScriptRequestData.h"

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
	KESLVLScriptProvider(IPMUnknown* boss) : CScriptProvider(boss) {};

	// Destructor.
	~KESLVLScriptProvider() {}

	// AccessProperty
	ErrorCode AccessProperty(ScriptID scriptID_property, IScriptRequestData* iScriptRequestData, IScript* iScript);

private:
	// AccessContentLocationAtFrameOrigin
	ErrorCode AccessContentLocationAtFrameOrigin(ScriptID scriptID_property, IScriptRequestData* iScriptRequestData, IScript* iScript, bool16 XYFlg);

	// AccessContentLocationAtFrameCenter 
	ErrorCode AccessContentLocationAtFrameCenter(ScriptID scriptID_property, IScriptRequestData* iScriptRequestData, IScript* iScript, bool16 XYFlg);
};


// CREATE_PMINTERFACE
CREATE_PMINTERFACE(KESLVLScriptProvider, kKESLVLScriptProviderImpl)

// AccessProperty
ErrorCode KESLVLScriptProvider::AccessProperty(ScriptID scriptID_property, IScriptRequestData* iScriptRequestData, IScript* iScript)
{
	ErrorCode status = kFailure;
	bool16 x = 0, y = 1;

	switch (scriptID_property.Get())
	{
		case p_KESLVLLocationAtFrameOriginX:
			status = this->AccessContentLocationAtFrameOrigin(scriptID_property, iScriptRequestData, iScript, x);
			break;
		case p_KESLVLLocationAtFrameOriginY:
			status = this->AccessContentLocationAtFrameOrigin(scriptID_property, iScriptRequestData, iScript, y);
			break;
		case p_KESLVLLocationAtFrameCenterX:
			status = this->AccessContentLocationAtFrameCenter(scriptID_property, iScriptRequestData, iScript, x);
			break;
		case p_KESLVLLocationAtFrameCenterY:
			status = this->AccessContentLocationAtFrameCenter(scriptID_property, iScriptRequestData, iScript, y);
			break;
		default:
			status = CScriptProvider::AccessProperty(scriptID_property, iScriptRequestData, iScript);
	}

	return status;
}

// AccessContentLocationAtFrameOrigin
ErrorCode KESLVLScriptProvider::AccessContentLocationAtFrameOrigin
(ScriptID scriptID_property, IScriptRequestData* iScriptRequestData, IScript* iScript, bool16 XYFlg)
{
	ErrorCode status = kFailure;

	do {
		// ---------------------------------------------------------------------------------------
		// Get top-left position
		// iScript == layoutWindows object
		InterfacePtr<IPanelControlData> iPanelControlData(iScript, ::UseDefaultIID());
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
		bool16 x = 0, y = 1;
		if (iScriptRequestData->IsPropertyGet()) // Get
		{
			// ---------------------------------------------------------------------------------------
			// Append return data
			if (XYFlg == x)
			{
				scriptData.SetPMReal(pMPoint_viewTopLeft.X());
			}
			else if (XYFlg == y)
			{
				scriptData.SetPMReal(pMPoint_viewTopLeft.Y());
			}

			iScriptRequestData->AppendReturnData(iScript, scriptID_property, scriptData);
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

			if (XYFlg == x)
			{
				pMPoint_viewTopLeft.X(pMReal_point);
			}
			else if (XYFlg == y)
			{
				pMPoint_viewTopLeft.Y(pMReal_point);
			}

			iPanorama->ScrollContentLocationToFrameOrigin(pMPoint_viewTopLeft);
		}
		status = kSuccess;

	} while (kFalse);

	return status;
}

// AccessContentLocationAtFrameCenter
ErrorCode KESLVLScriptProvider::AccessContentLocationAtFrameCenter
(ScriptID scriptID_property, IScriptRequestData* iScriptRequestData, IScript* iScript, bool16 XYFlg)
{
	ErrorCode status = kFailure;

	do {
		// ---------------------------------------------------------------------------------------
		// Get top-left position
		// iScript == layoutWindows object
		InterfacePtr<IPanelControlData> iPanelControlData(iScript, ::UseDefaultIID());
		if (!iPanelControlData) break;

		// kLayoutWidgetBoss is a BOSS representing a layout view.
		IControlView* iControlView = iPanelControlData->FindWidget(kLayoutWidgetBoss);
		if (!iControlView) break;

		InterfacePtr<IPanorama> iPanorama(iControlView, ::UseDefaultIID());
		if (!iPanorama) break;

		PMPoint pMPoint_viewTopLeft = iPanorama->GetContentLocationAtFrameCenter();

		// ---------------------------------------------------------------------------------------
		// Request
		ScriptData scriptData;
		bool16 x = 0, y = 1;
		if (iScriptRequestData->IsPropertyGet()) // Get
		{
			// ---------------------------------------------------------------------------------------
			// Append return data
			if (XYFlg == x)
			{
				scriptData.SetPMReal(pMPoint_viewTopLeft.X());
			}
			else if (XYFlg == y)
			{
				scriptData.SetPMReal(pMPoint_viewTopLeft.Y());
			}

			iScriptRequestData->AppendReturnData(iScript, scriptID_property, scriptData);
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

			if (XYFlg == x)
			{
				pMPoint_viewTopLeft.X(pMReal_point);
			}
			else if (XYFlg == y)
			{
				pMPoint_viewTopLeft.Y(pMReal_point);
			}

			iPanorama->ScrollContentLocationToFrameCenter(pMPoint_viewTopLeft);
		}
		status = kSuccess;

	} while (kFalse);

	return status;
}
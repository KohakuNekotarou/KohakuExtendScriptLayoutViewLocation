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


#ifndef __KESLVLID_h__
#define __KESLVLID_h__

#include "SDKDef.h"

// Company:
#define kKESLVLCompanyKey	kSDKDefPlugInCompanyKey		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kKESLVLCompanyValue	kSDKDefPlugInCompanyValue	// Company name displayed externally.

// Plug-in:
#define kKESLVLPluginName	"KohakuExtendScriptLayoutViewLocation"			// Name of this plug-in.
#define kKESLVLPrefixNumber	0xe204455 		// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kKESLVLVersion		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kKESLVLAuthor		""					// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kKESLVLPrefixNumber above to modify the prefix.)
#define kKESLVLPrefix		RezLong(kKESLVLPrefixNumber)				// The unique numeric prefix for all object model IDs for this plug-in.
#define kKESLVLStringPrefix	SDK_DEF_STRINGIZE(kKESLVLPrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// Missing plug-in: (see ExtraPluginInfo resource)
#define kKESLVLMissingPluginURLValue		kSDKDefPartnersStandardValue_enUS // URL displayed in Missing Plug-in dialog
#define kKESLVLMissingPluginAlertValue	kSDKDefMissingPluginAlertValue // Message displayed in Missing Plug-in dialog - provide a string that instructs user how to solve their missing plug-in problem

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kKESLVLPluginID, kKESLVLPrefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kKESLVLScriptProviderBoss, kKESLVLPrefix + 0)

// InterfaceIDs:
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESLVLINTERFACE, kKESLVLPrefix + 0)

// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace, kKESLVLScriptProviderImpl, kKESLVLPrefix + 0 )

// ActionIDs:
DECLARE_PMID(kActionIDSpace, kKESLVLAboutActionID, kKESLVLPrefix + 0)
//DECLARE_PMID(kActionIDSpace, kKESLVLActionID, kKESLVLPrefix + 5)

// WidgetIDs:
//DECLARE_PMID(kWidgetIDSpace, kKESLVLWidgetID, kKESLVLPrefix + 2)

//Script Element IDs

DECLARE_PMID(kScriptInfoIDSpace, kKESLVLLocationAtFrameOriginXPropertyScriptElement, kKESLVLPrefix + 0)
DECLARE_PMID(kScriptInfoIDSpace, kKESLVLLocationAtFrameOriginYPropertyScriptElement, kKESLVLPrefix + 1)

// "About Plug-ins" sub-menu:
#define kKESLVLAboutMenuKey			kKESLVLStringPrefix "kKESLVLAboutMenuKey"
#define kKESLVLAboutMenuPath		kSDKDefStandardAboutMenuPath kKESLVLCompanyKey

// "Plug-ins" sub-menu:
#define kKESLVLPluginsMenuKey 		kKESLVLStringPrefix "kKESLVLPluginsMenuKey"
#define kKESLVLPluginsMenuPath		kSDKDefPlugInsStandardMenuPath kKESLVLCompanyKey kSDKDefDelimitMenuPath kKESLVLPluginsMenuKey

// Menu item keys:

// Other StringKeys:
#define kKESLVLAboutBoxStringKey	kKESLVLStringPrefix "kKESLVLAboutBoxStringKey"
#define kKESLVLTargetMenuPath kKESLVLPluginsMenuPath

// Menu item positions:


// Initial data format version numbers
#define kKESLVLFirstMajorFormatNumber  RezLong(1)
#define kKESLVLFirstMinorFormatNumber  RezLong(0)

// Data format version numbers for the PluginVersion resource 
#define kKESLVLCurrentMajorFormatNumber kKESLVLFirstMajorFormatNumber
#define kKESLVLCurrentMinorFormatNumber kKESLVLFirstMinorFormatNumber

#endif // __KESLVLID_h__

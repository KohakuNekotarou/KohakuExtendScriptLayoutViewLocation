#ifndef __KESLVLScriptingDefs_h__
#define __KESLVLScriptingDefs_h__

#define kCPrefs_CLSID { 0x8d448fe0, 0x8194, 0x11d3, { 0xa6, 0x53, 0x0, 0xe0, 0x98, 0x71, 0xa, 0x6f } }
DECLARE_GUID(CPrefs_CLSID, kCPrefs_CLSID);

// Note: 4-char IDs below must be unique.
// See ScriptingDefs.h for further information.

// Property IDs
enum KESLVLScriptProperties
{
	p_KESLVLLocationAtFrameOriginX = 'KLOX',
	p_KESLVLLocationAtFrameOriginY = 'KLOY',
	p_KESLVLLocationAtFrameCenterX = 'KLCX',
	p_KESLVLLocationAtFrameCenterY = 'KLCY',
};

#endif // __KESLVLScriptingDefs_h__
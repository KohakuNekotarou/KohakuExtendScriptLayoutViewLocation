# InDesign Plug-In

**I'll add various things to ExtendScript.**
<br>**Let's learn the InDesign SDK together.**

We cannot be held responsible for any issues arising from your use of this service.<br>
Please use it at your own risk.<br>

On Mac, you cannot use downloaded plug-ins directly.<br>
https://helpx.adobe.com/jp/indesign/kb/indesign-and-macos-catalina.html<br>
Refer to the above and use Terminal to<br>
sudo xattr -r -d com.apple.quarantine /Applications/Adobe\ Indesign\ 2025/Plug-ins/KohakuExtendScriptQueryInfoPanelText.InDesignPlugin<br>
Please execute.

## extendScript for JavaScript
```
// Retrieve the text displayed on the information panel.

// TypeToolPanelCursorXLocationLabel
value = app.queryInfoPanelText("0x17D00", 83);
alert(value);

// TypeToolPanelCursorYLocationLabel
value = app.queryInfoPanelText("0x17D00", 85);
alert(value);

// Save the list to the desktop.
var text = "";
for(i = 1; i <= 255; i++){
	value = app.queryInfoPanelText("0x15C00", i);
	text += "0x15C00 " + i + " : " + value + "\n";
}
for(i = 1; i <= 255; i++){
	value = app.queryInfoPanelText("0x17D00", i);
	text += "0x17D00 " + i + " : " + value + "\n";
}
var f0 = File("~/desktop/InfoPanelText.txt");
f0.open("w");
f0.write(text);
f0.close();
```

## Build Method
**Mac Edition**

**1. Download the SDK**<br>
https://developer.adobe.com/indesign/

**2. Downloading the programming software, Xcode**<br>
SDK/docs/html/index.html<br>
Download the Xcode version compatible with your InDesign version as a reference.<br>
https://developer.apple.com/download/all/?q=xcode

**3. Create a PlugIn template**<br>
Search for and install Java to use dolly.jar<br>
SDK/devtools/dolly/dolly.jar<br>
use<br>
<img width="486" height="593" alt="dolly1" src="https://github.com/user-attachments/assets/187632dc-9ff0-43c4-98aa-c4caa93ef2cc" /><br>
<img width="486" height="593" alt="dolly2" src="https://github.com/user-attachments/assets/8f08d7d5-dd47-45ce-91b1-2951034368da" /><br>
<img width="486" height="593" alt="dolly3" src="https://github.com/user-attachments/assets/da50a70c-1a63-410c-a99e-ae38f836e0ab" /><br>
<img width="486" height="593" alt="dolly4" src="https://github.com/user-attachments/assets/8f6fc0c4-a3f9-460b-b04f-50d078144980" /><br>
The project directory is located at<br>
SDK/build/mac/prj<br>
Set up and create as follows.

**4. Download the source from Git**<br>
![Git](https://github.com/user-attachments/assets/5157f513-096f-4e2e-b471-af644948e97c)<br>
Place the source files in the<br>
SDK/source/sdksamples/kohakuExtendScriptQueryInfoPanelText
folder.

**5. Build in Xcode**<br>
Load KohakuExtendScript project in Xcode.<br>
Set the build configuration to Release.<br>
<img width="279" height="58" alt="rere" src="https://github.com/user-attachments/assets/420c409a-f7f0-495f-95bf-f61c1497d380" /><br>
Product > Build

**6. Load PlugIn**<br>
SDK/build/mac/release_cocoa64/KohakuExtendScriptQueryInfoPanelText.InDesignPlugin<br>
Place the PlugIn in the PlugIn folder in InDesign.<br>
If the message “As the correct plugin” appears.<br>
Product > Clean Build Folder...<br>
After performing the above, please try building.

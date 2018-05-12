# ShadowMapMaterialFunction
![image](https://github.com/quickzero/ShadowMapMaterialFunctionExample/blob/master/Featured%20Image_01.jpg)

* Independent shadow system, draw dynamic shadow by material function without light.
* Work well without [Mobile HDR], [Mobile HDR] is necessary for [Modulated Shadows] of UE4.
* Work well with [GoogleVR], [GoogleVR] must disable [Mobile HDR].
* Enable [Mobile HDR] is OK.
* Shadow caster can recive shadow. (Self Shadow)
* Good performance for slower mobile device.
* Good compatibility for old mobile device.
* Supported Windows, Mac, iOS and Android.

Android Benchmark APK:
https://drive.google.com/open?id=1JgTWAChTGT1hW9mpTMeCEMTcM4koefh6

# Content:
ShadowCapture :<br>
Blueprint Actor, place to scene to capture shadow, follows location of [ShadowMapTargetComponent], X-axis of ShadowCaptureBP is virtual light direction.

ShadowMapTargetComponent :<br>
Component, ShadowCapture follows location of ShadowMapTargetComponent.

CastShadowMapComponent :<br>
Component, Actor with this component cast shadow.

ShadowMapMultiply :<br>
Material Function, material with ShadowMapMultiply recive shadow;

# Features:
1.Shadow Mapping depth comparison.<br>
2.Shadow Map Antialiasing by Percentage-Closer Filtering.<br>
3.Pack depth float into a RGBA render target texture, compatible with older mobile device.<br>

Number of Blueprints: 1<br>
Number of C++ Classes: 5<br>
Supported Devlopment Platforms:Win64, macOS<br>
Supported Target Build Platforms: Win32, Win64, macOS, iOS, Android<br>

# Quickstart:
1. Create a map which have a DirectionalLight.
2. Add ShadowCapture to scene and edit ShadowCapture propertys.
* Shadow Map Size : Set shadow resolution.
* Shadow Region Size : Set area size effected by Shadow.
* Shadow Color : Set shadow color.
* Direct Light : Select DirectionalLight referenced by ShadowCapture, ShadowCapture will follow rotation of DirectionalLight.<br>
![image](https://github.com/quickzero/ShadowMapMaterialFunctionExample/blob/master/ShadowCaptureParameter.jpg)

* Auto Find Direct Light : If Direct Light is null, find a DirectionalLight in the world.
* Lock World Location of Pixel : Decrease shake of static static shadow caster.
* Force Pack RGB : Use RGBA format shadow map replace R32F format.

3. Attach CastShadowMapComponent to Actors which cast shadow.
4. Attach ShadowMapTargetComponent to Actor which be followed by ShadowCapture.
5. Add ShadowMapMultiply node in material which recive shadow, it should be the final node before Base Color.
![image](https://github.com/quickzero/ShadowMapMaterialFunctionExample/blob/master/MaterialEditor.jpg)

# Note:
When deploy on iOS, please modify r.MetalVertexParameterSize and r.MetalPixelParameterSize to 100.<br>
Location is Window -> Developer Tools -> Device Profiles -> iOS.<br>
After modity values, Press Save as Default.<br>
![image](https://github.com/quickzero/ShadowMapMaterialFunctionExample/blob/master/Note_01.jpg)



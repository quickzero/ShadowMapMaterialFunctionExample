# ShadowMapMaterialFunction
![image](https://github.com/quickzero/ShadowMapMaterialFunctionExample/blob/master/Featured%20Image_01.jpg)

The Plugin provides MaterialFunction which draw dynamic shadow, it is the solution of dynamic shadow without Mobile HDR on iOS and Android, for example GoogleVR Project must disable Mobile HDR.

This dynamic shadow system have much better performance than UE4 default on mobile device.

# Content:
ShadowCapture :<br>
Blueprint Actor, place to scene to capture depth of Actors with CastShadowMapComponent, follows location of ShadowMapTargetComponent and rotation of DirectionalLight.

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
1.Create a map which have a DirectionalLight.<br>
2.Add ShadowCapture to scene.<br>
3.Attach CastShadowMapComponent to Actors which cast shadow.<br>
4.Attach ShadowMapTargetComponent to Actor which be followed by ShadowCapture.<br>
5.Add ShadowMapMultiply node in material which recive shadow, it should be the final node before Base Color.<br>
![image](https://github.com/quickzero/ShadowMapMaterialFunctionExample/blob/master/MaterialEditor.jpg)

# Note:
When deploy on iOS, please modify r.MetalVertexParameterSize and r.MetalPixelParameterSize to 100.<br>
Location is Window -> Developer Tools -> Device Profiles -> iOS.<br>
After modity values, Press Save as Default.<br>
![image](https://github.com/quickzero/ShadowMapMaterialFunctionExample/blob/master/Note_01.jpg)



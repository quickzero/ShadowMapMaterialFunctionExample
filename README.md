# ShadowMapMaterialFunction

The Plugin provides MaterialFunction which draw dynamic shadow, it is the solution of dynamic shadow without Mobile HDR on iOS and Android, for example GoogleVR Project must disable Mobile HDR.

This dynamic shadow system have much better performance than UE4 default on mobile device.

# Content:
ShadowCaptureBP :<br>
Blueprint Actor, place to scene to capture depth of Actors with CastShadowMapComponent, follows location of ShadowMapTargetComponent and rotation of DirectionalLight.

ShadowMapTargetComponent :<br>
Component, ShadowCaptureBP follows location of ShadowMapTargetComponent.

CastShadowMapComponent :<br>
Component, Actor with this component cast shadow.

ShadowMapMultiply :<br>
Material Function, material with ShadowMapMultiply recive shadow;

# Features:

1.Shadow Mapping depth comparison.<br>
2.Shadow Map Antialiasing by Percentage-Closer Filtering.<br>
3.Pack depth float into a RGBA render target texture, compatible with older mobile device.<br>

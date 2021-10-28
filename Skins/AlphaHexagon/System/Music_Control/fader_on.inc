[Variables]
U1=[!UpdateMeasure Fader][!UpdateMeter MeterInactiveColorPrevious][!Redraw]
U2=[!UpdateMeasure Fader][!UpdateMeter MeterInactiveColorPlayPause][!Redraw]
U3=[!UpdateMeasure Fader][!UpdateMeter MeterInactiveColorNext][!Redraw]
FadingAlpha1=255
FadingAlpha2=255
FadingAlpha3=255

[Fader]
Measure=Plugin
Plugin=ActionTimer
FadeIn1=[!SetVariable FadingAlpha1 "(Clamp((#FadingAlpha1# - 255 / #FadeInSteps#), 0, 255))"]#U1#
FadeOut1=[!SetVariable FadingAlpha1 "(Clamp((#FadingAlpha1# + 255 / #FadeOutSteps#), 0, 255))"]#U1#
FadeIn2=[!SetVariable FadingAlpha2 "(Clamp((#FadingAlpha2# - 255 / #FadeInSteps#), 0, 255))"]#U2#
FadeOut2=[!SetVariable FadingAlpha2 "(Clamp((#FadingAlpha2# + 255 / #FadeOutSteps#), 0, 255))"]#U2#
FadeIn3=[!SetVariable FadingAlpha3 "(Clamp((#FadingAlpha3# - 255 / #FadeInSteps#), 0, 255))"]#U3#
FadeOut3=[!SetVariable FadingAlpha3 "(Clamp((#FadingAlpha3# + 255 / #FadeOutSteps#), 0, 255))"]#U3#
ActionList1=Repeat FadeIn1, 40, #FadeInSteps#
ActionList2=Repeat FadeOut1, 40, #FadeOutSteps#
ActionList3=Repeat FadeIn2, 40, #FadeInSteps#
ActionList4=Repeat FadeOut2, 40, #FadeOutSteps#
ActionList5=Repeat FadeIn3, 40, #FadeInSteps#
ActionList6=Repeat FadeOut3, 40, #FadeOutSteps#
DynamicVariables=1

[StyleInactiveColor]
W=#IconWidth#
H=#IconHeight#
DynamicVariables=1

[MeterHitboxPrevious]
MouseOverAction=[!CommandMeasure Fader "Stop 2"][!CommandMeasure Fader "Execute 1"]
MouseLeaveAction=[!CommandMeasure Fader "Stop 1"][!CommandMeasure Fader "Execute 2"]

[MeterHitboxPlayPause]
MouseOverAction=[!CommandMeasure Fader "Stop 4"][!CommandMeasure Fader "Execute 3"]
MouseLeaveAction=[!CommandMeasure Fader "Stop 3"][!CommandMeasure Fader "Execute 4"]

[MeterHitboxNext]
MouseOverAction=[!CommandMeasure Fader "Stop 6"][!CommandMeasure Fader "Execute 5"]
MouseLeaveAction=[!CommandMeasure Fader "Stop 5"][!CommandMeasure Fader "Execute 6"]

[MeterInactiveColorPrevious]
Container=MeterIconMaskPrevious
Meter=Image
MeterStyle=StyleInactiveColor
SolidColor=#InactiveColor#,#FadingAlpha1#

[MeterInactiveColorPlayPause]
Container=MeterIconMaskPlayPause
Meter=Image
MeterStyle=StyleInactiveColor
SolidColor=#InactiveColor#,#FadingAlpha2#

[MeterInactiveColorNext]
Container=MeterIconMaskNext
Meter=Image
MeterStyle=StyleInactiveColor
SolidColor=#InactiveColor#,#FadingAlpha3#

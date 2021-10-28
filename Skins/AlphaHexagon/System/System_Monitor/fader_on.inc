[Variables]
U=[!UpdateMeasure Fader][!UpdateMeasure FadingColor][!UpdateMeterGroup Fading][!Redraw]
FadingAlpha=1

[Fader]
Measure=Plugin
Plugin=ActionTimer
FadeIn=[!SetVariable FadingAlpha "(Clamp((#FadingAlpha# - 1 / #FadeInSteps#), 0, 1))"]#U#
FadeOut=[!SetVariable FadingAlpha "(Clamp((#FadingAlpha# + 1 / #FadeOutSteps#), 0, 1))"]#U#
ActionList1=Repeat FadeIn, 40, #FadeInSteps#
ActionList2=Repeat FadeOut, 40, #FadeOutSteps#
DynamicVariables=1

[FadingColor]
Measure=Calc
Formula=#InactiveTint# * #FadingAlpha# + #ActiveTint# * (1 - #FadingAlpha#)
RegExpSubstitute=1
Substitute="^(.+)$":"\1,\1,\1"
DynamicVariables=1

[StyleHitbox]
MouseOverAction=[!CommandMeasure Fader "Stop 2"][!CommandMeasure Fader "Execute 1"]
MouseLeaveAction=[!CommandMeasure Fader "Stop 1"][!CommandMeasure Fader "Execute 2"]

[StyleRoundline]
Group=Fading
DynamicVariables=1

[StyleLabel]
Group=Fading
DynamicVariables=1

/*
  ==============================================================================

    SynthVoice.h
    Created: 13 Jul 2023 10:24:22pm
    Author:  fscha

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
//==============================================================================
/*
*/
class SynthVoice  : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity,juce::SynthesiserSound*sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void controllerMoved(int controllerNumber, int newControlerValue) override;
    void pitchWheelMoved(int newPitchwheelValue)override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock(juce::AudioBuffer<float>&outputBuffer, int startSample, int numSamples) override;
    SynthVoice() {};
    /*
    ~SynthVoice() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    */
private:
    juce::ADSR adsr;
    juce::ADSR::Parameters adsrParams;
    //juce::dsp::Oscillator<float> osc{ [](float x) {return std::sin(x); }}; //sine
    //juce::dsp::Oscillator<float> osc{ [](float x) {return x / juce::MathConstants<float>::pi; } }; //saw
    juce::dsp::Oscillator<float> osc{ [](float x) {return x < 0.0f ? -1.0f : 1.0f; } }; //sqare
    //juce::dsp::Oscillator<float> osc{ [](float x) {return x; } };
    juce::dsp::Gain<float> gain;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SynthVoice)
    bool isPreparered{ false };
};

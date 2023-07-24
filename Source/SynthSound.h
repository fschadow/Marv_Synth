/*
  ==============================================================================

    SynthSound.h
    Created: 13 Jul 2023 10:25:17pm
    Author:  fscha

  ==============================================================================
*/

#pragma once

#include  <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    /*
	SynthSound : public juce::SynthesiserSound();
	~SynthSound : public juce::SynthesiserSound();
    */
    bool appliesToNote(int midiNoteNumber) override { return true; }
    bool appliesToChannel(int midiChanal) override { return true; }
    SynthSound() {  };
private:

};
/*
SynthSound : public juce::SynthesiserSound::SynthSound : public juce::SynthesiserSound()
{
}

SynthSound : public juce::SynthesiserSound::~SynthSound : public juce::SynthesiserSound()
{
}
*/
/*
  ==============================================================================

    SynthVoice.cpp
    Created: 13 Jul 2023 10:24:22pm
    Author:  fscha

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SynthVoice.h"

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound)
{


    return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
}
void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
    osc.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    adsr.noteOn();
}
void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
    adsr.noteOff();
}
void SynthVoice::controllerMoved(int controllerNumber, int newControlerValue)
{
  
}
void SynthVoice::pitchWheelMoved(int newPitchwheelValue)
{

}
void SynthVoice::prepareToPlay(double sampleRate, int samplesPerBlock,int outputChannels)
{
    adsr.setSampleRate(sampleRate); 
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = sampleRate;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;
    osc.prepare(spec);
    gain.prepare(spec);
    
    gain.setGainLinear(0.01f);
    isPreparered = true;
}
void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    jassert(isPreparered); 
    juce::dsp::AudioBlock<float> audioBlock{ outputBuffer };
    osc.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
    gain.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
    adsr.applyEnvelopeToBuffer(outputBuffer, startSample, numSamples);
}

// //==============================================================================
// SynthVoice::SynthVoice()
// {
//     // In your constructor, you should add any child components, and
//     // initialise any special settings that your component needs.

// }

// SynthVoice::~SynthVoice()
// {
// }

// void SynthVoice::paint (juce::Graphics& g)
// {
//     /* This demo code just fills the component's background and
//        draws some placeholder text to get you started.

//        You should replace everything in this method with your own
//        drawing code..
//     */

//     g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

//     g.setColour (juce::Colours::grey);
//     g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

//     g.setColour (juce::Colours::white);
//     g.setFont (14.0f);
//     g.drawText ("SynthVoice", getLocalBounds(),
//                 juce::Justification::centred, true);   // draw some placeholder text
// }

// void SynthVoice::resized()
// {
//     // This method is where you should set the bounds of any child
//     // components that your component contains..

// }
